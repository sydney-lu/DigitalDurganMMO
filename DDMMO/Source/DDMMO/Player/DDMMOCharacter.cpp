// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DDMMOCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "WarriorClass.h" // Only Here For Testing Classes, Will not be needed with a proper Class Selection Screen.
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Projectiles/BaseProjectile.h"

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

	//MuzzleOffset = FVector(0.f, 0.f, 0.f);
	
	//MeleeCollider = CreateDefaultSubobject<USphereComponent>("Melee Sphere Collider");
	//MeleeCollider->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CurrentState = PlayerCharacterState(PlayerCharacterState::IDLE);

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
}


void ADDMMOCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	//	W.I.P camera controls for MMORPG
	PlayerInputComponent->BindAction("RMB", IE_Pressed, this, &ADDMMOCharacter::RMBPressed);
	PlayerInputComponent->BindAction("RMB", IE_Released, this, &ADDMMOCharacter::RMBReleased);
	PlayerInputComponent->BindAction("LMB", IE_Pressed, this, &ADDMMOCharacter::LMBPressed);
	PlayerInputComponent->BindAction("LMB", IE_Released, this, &ADDMMOCharacter::LMBReleased);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ADDMMOCharacter::ZoomIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ADDMMOCharacter::ZoomOut);

	//	Traversal for character
	PlayerInputComponent->BindAxis("MoveForward", this, &ADDMMOCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADDMMOCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ADDMMOCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ADDMMOCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("OpenBag", IE_Pressed, this, &ADDMMOCharacter::OpenBag);
	PlayerInputComponent->BindAction("CharacterInfo", IE_Pressed, this, &ADDMMOCharacter::CharacterInfo);
	PlayerInputComponent->BindAction("SkillInfo", IE_Pressed, this, &ADDMMOCharacter::SkillInfo);

	//	Functional action keys
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//	Non-Functional action keys
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ADDMMOCharacter::Interact);

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
	PlayerInputComponent->BindAction("Skill-", IE_Pressed, this, &ADDMMOCharacter::SkillOemminus);
	PlayerInputComponent->BindAction("Skill=", IE_Pressed, this, &ADDMMOCharacter::SkillOemplus);
}

void ADDMMOCharacter::SetPlayerState(PlayerCharacterState NewState)
{
	CurrentState = NewState;
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

void ADDMMOCharacter::SetSkillSelection(UPlayerInfoWidget* widget)
{
	skillSelectionWidget = widget;
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
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Failed to SetSkillDelegata: No UFucntion was found"));
				SkillLogicDelegates[index].BindUFunction(characterClass, FName("DefaultSkill"), skillData);
			}
			else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("SetSkillDelegata Success"));
		}
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Failed to SetSkillDelegata: No UFucntion was found"));
	}
	else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Failed to SetSkillDelegata: No CharacterClass Selected"));
}

void ADDMMOCharacter::OpenBag()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the BAG UI is in progress."));
	}
}

void ADDMMOCharacter::LMBPressed()
{
	if (Controller != NULL)
	{
		if (Stamina_CUR > 0)
		{
			//APlayerController* MyController = GetWorld()->GetFirstPlayerController();
			//MyController->bShowMouseCursor = false;
			if (CurrentState == PlayerCharacterState::IDLE)
			{
				UE_LOG(LogTemp, Warning, TEXT("You're using your melee attack"));
				SetPlayerState(PlayerCharacterState::ATTACKING);

				Stamina_CUR--;
			}
		}
	}
}

void ADDMMOCharacter::LMBReleased()
{
	if (Controller != NULL)
	{
		//UE_LOG(LogTemp, Warning, TEXT("LMB Released"));
		//APlayerController* MyController = GetWorld()->GetFirstPlayerController();
		if (CurrentState == PlayerCharacterState::ATTACKING)
		{
			//MyController->bShowMouseCursor = true;
			SetPlayerState(PlayerCharacterState::IDLE);
		}
	}
}

void ADDMMOCharacter::RMBPressed()
{
	if (Controller != NULL)
	{
		//UE_LOG(LogTemp, Warning, TEXT("RMB"));
		if (Mana_CUR > 0)
		{
			if (CurrentState == PlayerCharacterState::IDLE)
			{
				UE_LOG(LogTemp, Warning, TEXT("You're using your ranged attack"));
				SetPlayerState(PlayerCharacterState::CASTING);
				Mana_CUR--;
				Fire();
			}
		}
	}
}

void ADDMMOCharacter::RMBReleased()
{
	if (Controller != NULL)
	{
		//UE_LOG(LogTemp, Warning, TEXT("RMB"));
		if (CurrentState == PlayerCharacterState::CASTING)
		{
			SetPlayerState(PlayerCharacterState::IDLE);
		}
	}
}


void ADDMMOCharacter::CharacterInfo()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the Character info is in progress."));
	}
}

void ADDMMOCharacter::SkillInfo()
{
	if (Controller != NULL)
	{
		if (skillSelectionWidget) skillSelectionWidget->ToggleVisible();
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the Skill Info is in progress."));
	}
}

void ADDMMOCharacter::Interact()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Restored Health, Mana, and Stamina."));
		Health_CUR = Health_MAX;
		Mana_CUR = Mana_MAX;
		Stamina_CUR = Stamina_MAX;
	}
}

void ADDMMOCharacter::SkillOne()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[0].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '1'."));
	}
}

void ADDMMOCharacter::SkillTwo()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[1].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '2'."));
	}
}

void ADDMMOCharacter::SkillThree()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[2].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '3'."));
	}
}

void ADDMMOCharacter::SkillFour()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[3].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '4'."));
	}
}

void ADDMMOCharacter::SkillFive()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[4].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '5'."));
	}
}

void ADDMMOCharacter::SkillSix()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[5].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '6'."));
	}
}

void ADDMMOCharacter::SkillSeven()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[6].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '7'."));
	}
}

void ADDMMOCharacter::SkillEight()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[7].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '8'."));
	}
}

void ADDMMOCharacter::SkillNine()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[8].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '9'."));
	}
}

void ADDMMOCharacter::SkillZero()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[9].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '0'."));
	}
}

void ADDMMOCharacter::SkillOemminus()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[10].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '-'."));
	}
}

void ADDMMOCharacter::SkillOemplus()
{
	if (Controller != NULL)
	{
		if (!SkillLogicDelegates[11].ExecuteIfBound())
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill bound to '='."));
	}
}

void ADDMMOCharacter::Fire()
{
	//UE_LOG(LogTemp, Display, TEXT("Pew, Pew"));
	if (ProjectileClass)
	{
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		//MuzzleRotation.Pitch += 10.0f;

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			ABaseProjectile* Projectile = World->SpawnActor<ABaseProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}

void ADDMMOCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ADDMMOCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}