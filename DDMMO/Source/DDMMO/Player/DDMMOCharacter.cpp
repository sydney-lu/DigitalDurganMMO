// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DDMMOCharacter.h"
#include <EngineGlobals.h>
#include "Engine.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "WarriorClass.h" // Only Here For Testing Classes, Will not be needed with a proper Class Selection Screen.
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Projectiles/BaseProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Player/PlayerInfoWidget.h"
#include "Kismet/GameplayStatics.h"

ADDMMOCharacter::ADDMMOCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	Zoom_Power = 75.0f;
	ZoomIn_MAX = 800.0f;
	ZoomOut_MAX = 1250.0f;

	Health_MAX = 50.f;
	Mana_MAX = 25.f;
	Stamina_MAX = 25.f;

	Health_CUR = Health_MAX;
	Mana_CUR = Mana_MAX;
	Stamina_CUR = Stamina_MAX;

	BasicAttackSpeed = 1.f;
	BasicAttackRange = 20.f;

	CurrentSpeed = 0.0f;
	bIsAttacking = false;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;

	CurrentState = PlayerCharacterState(PlayerCharacterState::IDLE);

	SkeletalMesh = GetMesh();

	MeleeCollider = CreateDefaultSubobject<USphereComponent>("Melee Sphere Collider");
	MeleeCollider->OnComponentHit.AddDynamic(this, &ADDMMOCharacter::OnMeleeHit);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = ZoomOut_MAX; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraZoom_v = ZoomOut_MAX;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Skill Delegates
	SkillLogicDelegates.SetNum(12);

	// UI
	MainHud = CreateWidget<UHUD_Main>(GetWorld());
	if (MainHud)
	{
		MainHud->AddToViewport();
		MainHud->SetVisibility(ESlateVisibility::Visible);
	}

	ConstructorHelpers::FClassFinder<ABaseProjectile>ProjectileAsset(TEXT("Blueprint'/Game/Projectiles/BaseProjectile_BP.BaseProjectile_BP_C'"));
	if (ProjectileAsset.Class)
	{
		ProjectileClass = (UClass*)ProjectileAsset.Class;
	}
}

void ADDMMOCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TargetingHandle, this, &ADDMMOCharacter::FindTarget, TargetingRate, true);
	MeleeCollider->SetNotifyRigidBodyCollision(true);
	MeleeCollider->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName("WeaponSocket"));
}

void ADDMMOCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	//	W.I.P camera controls for MMORPG
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ADDMMOCharacter::ZoomIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ADDMMOCharacter::ZoomOut);

	//	Traversal for character
	PlayerInputComponent->BindAxis("MoveForward", this, &ADDMMOCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADDMMOCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ADDMMOCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ADDMMOCharacter::LookUpAtRate);

	//	UI keys
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &ADDMMOCharacter::Inventory);
	PlayerInputComponent->BindAction("CharacterMenu", IE_Pressed, this, &ADDMMOCharacter::CharacterMenu);
	PlayerInputComponent->BindAction("SkillMenu", IE_Pressed, this, &ADDMMOCharacter::SkillMenu);

	// Action keys
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ADDMMOCharacter::Interact);
	PlayerInputComponent->BindAction("SwitchTargetLock", IE_Pressed, this, &ADDMMOCharacter::SwitchTargetLock);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ADDMMOCharacter::ToggleCrouch);
	PlayerInputComponent->BindAction("BasicAttack", IE_Pressed, this, &ADDMMOCharacter::BasicAttack);
	PlayerInputComponent->BindAction("Defense", IE_Pressed, this, &ADDMMOCharacter::Defense);
	PlayerInputComponent->BindAction("DebugFire", IE_Pressed, this, &ADDMMOCharacter::Fire);

	//	Non-Functional skill binding keys
	PlayerInputComponent->BindAction("Skill0", IE_Pressed, this, &ADDMMOCharacter::SkillZero);
	PlayerInputComponent->BindAction("Skill1", IE_Pressed, this, &ADDMMOCharacter::SkillOne);
	PlayerInputComponent->BindAction("Skill2", IE_Pressed, this, &ADDMMOCharacter::SkillTwo);
	PlayerInputComponent->BindAction("Skill3", IE_Pressed, this, &ADDMMOCharacter::SkillThree);
	PlayerInputComponent->BindAction("Skill4", IE_Pressed, this, &ADDMMOCharacter::SkillFour);
	PlayerInputComponent->BindAction("Skill5", IE_Pressed, this, &ADDMMOCharacter::SkillFive);
	PlayerInputComponent->BindAction("Skill6", IE_Pressed, this, &ADDMMOCharacter::SkillSix);
	PlayerInputComponent->BindAction("Skill7", IE_Pressed, this, &ADDMMOCharacter::SkillSeven);
	PlayerInputComponent->BindAction("Skill8", IE_Pressed, this, &ADDMMOCharacter::SkillEight);
	PlayerInputComponent->BindAction("Skill9", IE_Pressed, this, &ADDMMOCharacter::SkillNine);
	PlayerInputComponent->BindAction("Skill11", IE_Pressed, this, &ADDMMOCharacter::SkillTen);
	PlayerInputComponent->BindAction("Skill12", IE_Pressed, this, &ADDMMOCharacter::SkillEleven);
}

void ADDMMOCharacter::Destroyed()
{
	Super::Destroyed();
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void ADDMMOCharacter::OnMeleeHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("You punched stuff"));

	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("You punched %s, %s"), *OtherActor->GetName(), *OtherComp->GetName());
	}
}

void ADDMMOCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ADDMMOCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ADDMMOCharacter::ZoomIn()
{
	if (Controller != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Zoom = %f - %f"), CameraZoom_v, Zoom_Power);
		CameraZoom_v = CameraZoom_v - Zoom_Power;

		if (CameraZoom_v <= ZoomIn_MAX)
		{
			UE_LOG(LogTemp, Warning, TEXT("Zoom In Max"));
			CameraBoom->TargetArmLength = ZoomIn_MAX;
			CameraZoom_v = ZoomIn_MAX;
		}

		else
		{
			UE_LOG(LogTemp, Display, TEXT("CameraBoom Arm Length: %f"), CameraBoom->TargetArmLength);
			UE_LOG(LogTemp, Warning, TEXT("Zooming In"));
			CameraBoom->TargetArmLength = CameraZoom_v;
		}
	}
}

void ADDMMOCharacter::ZoomOut()
{
	if (Controller != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Zoom = %f - %f"), CameraZoom_v, Zoom_Power);
		CameraZoom_v = CameraZoom_v + Zoom_Power;

		if (CameraZoom_v >= ZoomOut_MAX)
		{
			UE_LOG(LogTemp, Warning, TEXT("Zoom Out Max"));
			CameraBoom->TargetArmLength = ZoomOut_MAX;
			CameraZoom_v = ZoomOut_MAX;
		}

		else
		{
			UE_LOG(LogTemp, Display, TEXT("CameraBoom Arm Length: %f"), CameraBoom->TargetArmLength);
			UE_LOG(LogTemp, Warning, TEXT("Zooming Out"));
			CameraBoom->TargetArmLength = CameraZoom_v;
		}
	}
}

void ADDMMOCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		if (!bIsAttacking)
		{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		}
	}
}

void ADDMMOCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		if (!bIsAttacking)
		{
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			AddMovementInput(Direction, Value);
		}
	}
}

void ADDMMOCharacter::SetPlayerState(PlayerCharacterState NewState)
{
	CurrentState = NewState;
}

void ADDMMOCharacter::SwitchTargetLock()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No target lock functionality implemented."));
	}
}

void ADDMMOCharacter::Interact()
{
	if (Controller != NULL)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Restored Health, Mana, and Stamina."));
		Health_CUR = Health_MAX;
		Mana_CUR = Mana_MAX;
		Stamina_CUR = Stamina_MAX;
	}
}

void ADDMMOCharacter::ToggleCrouch()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for crouching is in progress."));
	}
}

void ADDMMOCharacter::FindTarget()
{
	FCollisionQueryParams TraceParams;
	TraceParams.bTraceComplex = true;
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;

	FVector start = GetFollowCamera()->GetComponentToWorld().GetLocation();
	FVector end = start + GetFollowCamera()->GetForwardVector() * TargetingRange;

	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByObjectType(Hit, start, end, ECC_Pawn, TraceParams);
	SetTarget(Hit.GetActor());
}

void ADDMMOCharacter::SetTarget(AActor* newTarget)
{
	if (newTarget == CurrentTarget || !Cast<ITargetable>(newTarget))
		return;

	ITargetable::Execute_OnUntargeted(CurrentTarget);
	if (newTarget)
	{
		CurrentTarget = newTarget;
		ITargetable::Execute_OnTargeted(newTarget);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "NewTargetSelected" + newTarget->GetName());
	}
}

void ADDMMOCharacter::Fire()
{
	CurrentSpeed = FVector::DotProduct(GetVelocity(), GetActorRotation().Vector());

	if (CurrentSpeed == 0)
	{
		if (!bIsAttacking)
		{
			bIsAttacking = true;
			if (ProjectileClass)
			{
				FVector spawnLocation;
				FRotator spawnRotation;

				SkeletalMesh->GetSocketWorldLocationAndRotation("ProjectileSpawn", spawnLocation, spawnRotation);

				UWorld* World = GetWorld();
				if (World)
				{
					FActorSpawnParameters SpawnParams;
					SpawnParams.Owner = this;
					SpawnParams.Instigator = Instigator;

					ABaseProjectile* Projectile = World->SpawnActor<ABaseProjectile>(ProjectileClass, spawnLocation, spawnRotation, SpawnParams);
					if (Projectile)
					{
						FVector LaunchDirection = spawnRotation.Vector();
						Projectile->FireInDirection(LaunchDirection);
					}
				}
			}
			bIsAttacking = false;
		}
	}
}

void ADDMMOCharacter::BasicAttack()
{
	if (Controller != NULL)
	{
		//if (Mana_CUR > 0)
		//{
			//Mana_CUR--;
			//Fire();
		//}
	}
}

void ADDMMOCharacter::Defense()
{
	if (Controller != NULL)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No Defense functionality implemented."));
	}
}

void ADDMMOCharacter::SkillOne()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[0].ExecuteIfBound())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'RMB', open the skill menu by pressing 'K'"));
		}
	}
}

void ADDMMOCharacter::SkillTwo()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[1].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'Q', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillThree()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[2].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'Z', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillFour()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[3].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'X', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillFive()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[4].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'C', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillSix()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[5].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'V', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillSeven()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[6].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to 'E', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillEight()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[7].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '1', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillNine()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[8].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '2', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillZero()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[9].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '3', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillTen()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[10].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '4', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SkillEleven()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[11].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '5', open the skill menu by pressing 'K'."));
	}
}

void ADDMMOCharacter::SetSkillSelection(UPlayerInfoWidget* widget)
{
	skillSelectionWidget = widget;
	if (MainHud) skillSelectionWidget->MainHud = MainHud;
}

void ADDMMOCharacter::SetSkillDelegate(int index, UCharacterSkillData* skillData)
{
	if (!characterClass) // Temp Class Selection Code
		characterClass = NewObject<UWarriorClass>();

	if (characterClass)
	{
		if (characterClass->FindFunction(skillData->Name()))
		{
			// Bind UFunction found in characterClass Named the same skillData
			SkillLogicDelegates[index].BindUFunction(characterClass, skillData->Name(), skillData);
			// Check if UFunction was Found and properly bound, else Bind to DefaultSkill
			if (!SkillLogicDelegates[index].IsBound())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Failed to SetSkillDelegate: No UFunction was found"));
				SkillLogicDelegates[index].BindUFunction(characterClass, FName("DefaultSkill"), skillData);
			}
			else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("SetSkillDelegate Success"));
		}
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Failed to SetSkillDelegate: No UFunction was found"));
	}
	else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Failed to SetSkillDelegate: No CharacterClass Selected"));
}

void ADDMMOCharacter::SkillMenu()
{
	if (Controller != NULL)
	{
		if (skillSelectionWidget) skillSelectionWidget->ToggleVisible();
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the Skill Info is in progress."));
	}
}

void ADDMMOCharacter::MainMenu()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the Main Menu is in progress."));
	}
}

void ADDMMOCharacter::Inventory()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the BAG UI is in progress."));
	}
}

void ADDMMOCharacter::CharacterMenu()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the Character info is in progress."));
	}
}