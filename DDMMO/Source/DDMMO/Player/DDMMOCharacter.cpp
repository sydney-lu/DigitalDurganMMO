// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DDMMOCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "CharacterClass.h"
#include "CharacterSkill.h"
#include "Components/TextRenderComponent.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"
//#include "Blueprint/UserWidget.h"
//#include "Components/WidgetComponent.h"

ADDMMOCharacter::ADDMMOCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	Zoom_Power = 55.0f;
	ZoomIn_Max = 75.0f;
	ZoomOut_Max = 1000.0f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = ZoomOut_Max; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraZoom_v = ZoomOut_Max;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Chat System
	ChatText = CreateDefaultSubobject<UTextRenderComponent>("ChatText");
	ChatText->SetRelativeLocation(FVector(0, 0, 100));
	ChatText->SetHorizontalAlignment(EHTA_Center);
	ChatText->SetupAttachment(RootComponent);

	CurrentMessage = "";
}


void ADDMMOCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	//	W.I.P camera controls for MMORPG
	PlayerInputComponent->BindAction("RMB", IE_Pressed, this, &ADDMMOCharacter::RMB);
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
		//UE_LOG(LogTemp, Warning, TEXT("Camera Zoom = %f - %f"), CameraZoom_v, Zoom_Power);
		CameraZoom_v = CameraZoom_v - Zoom_Power;

		if (CameraZoom_v <= ZoomIn_Max)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Zoom In Max"));
			CameraBoom->TargetArmLength = ZoomIn_Max;
			CameraZoom_v = ZoomIn_Max;
		}

		else
		{
			//UE_LOG(LogTemp, Display, TEXT("CameraBoom Arm Length: %f"), CameraBoom->TargetArmLength);
			//UE_LOG(LogTemp, Warning, TEXT("Zooming In"));
			CameraBoom->TargetArmLength = CameraZoom_v;
		}
	}
}

void ADDMMOCharacter::ZoomOut()
{
	if (Controller != NULL)
	{	//UE_LOG(LogTemp, Warning, TEXT("Camera Zoom = %f - %f"), CameraZoom_v, Zoom_Power);
		CameraZoom_v = CameraZoom_v + Zoom_Power;
	
		if (CameraZoom_v >= ZoomOut_Max)
		{
			CameraBoom->TargetArmLength = ZoomOut_Max;
			CameraZoom_v = ZoomOut_Max;
		}

		else
		{	//UE_LOG(LogTemp, Display, TEXT("CameraBoom Arm Length: %f"), CameraBoom->TargetArmLength);
			CameraBoom->TargetArmLength = CameraZoom_v;
		}
	}
}

void ADDMMOCharacter::OpenBag()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the BAG UI is in progress."));
	}
}

void ADDMMOCharacter::RMB()
{
	if (Controller != NULL)
	{
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();
		CenterViewportCursor(MyController);
		MyController->bShowMouseCursor = true;
	}
}

void ADDMMOCharacter::LMBPressed()
{
	if (Controller != NULL)
	{
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();
		MyController->bShowMouseCursor = false;
	}
}

void ADDMMOCharacter::LMBReleased()
{
	if (Controller != NULL)
	{

	}
}

void ADDMMOCharacter::CenterViewportCursor(const APlayerController* PlayerController)
{
	if (PlayerController)
	{
		const ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		if (LocalPlayer && LocalPlayer->ViewportClient)
		{
			FViewport* Viewport = LocalPlayer->ViewportClient->Viewport;
			if (Viewport)
			{
				FVector2D ViewportSize;
				LocalPlayer->ViewportClient->GetViewportSize(ViewportSize);
				const int32 X = static_cast<int32>(ViewportSize.X * 0.5f);
				const int32 Y = static_cast<int32>(ViewportSize.Y * 0.5f);

				Viewport->SetMouse(X, Y);
			}
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for the Skill Info is in progress."));
	}
}

void ADDMMOCharacter::Interact()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Functionality for Interaction is in progress."));
	}
}

void ADDMMOCharacter::SkillZero()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '0'."));
	}
}

void ADDMMOCharacter::SkillOne()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '1'."));
	}
}

void ADDMMOCharacter::SkillTwo()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '2'."));
	}
}

void ADDMMOCharacter::SkillThree()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '3'."));
	}
}

void ADDMMOCharacter::SkillFour()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '4'."));
	}
}

void ADDMMOCharacter::SkillFive()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '5'."));
	}
}

void ADDMMOCharacter::SkillSix()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '6'."));
	}
}

void ADDMMOCharacter::SkillSeven()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '7'."));
	}
}

void ADDMMOCharacter::SkillEight()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '8'."));
	}
}

void ADDMMOCharacter::SkillNine()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '9'."));
	}
}

void ADDMMOCharacter::SkillOemminus()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '-'."));
	}
}

void ADDMMOCharacter::SkillOemplus()
{
	if (Controller != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("You don't have a skill binded to '='."));
	}
}

void ADDMMOCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADDMMOCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADDMMOCharacter, CurrentMessage);

}

void ADDMMOCharacter::AttemptToSendChatMessage(const FString & Message)
{
	if (Role < ROLE_Authority) // Check to see if we are the server, call ServerSendChatMessage if we are, otherwise call SendChatMessage.
	{
		ServerSendChatMessage(Message);
	}
	else SendChatMessage(Message);
}

void ADDMMOCharacter::SendChatMessage(const FString& Message)
{
	CurrentMessage = Message;
	UpdateChatText();

	FTimerHandle TestHandle;
	GetWorldTimerManager().SetTimer(TestHandle, this, &ADDMMOCharacter::ClearChatMessage, 5.f);
}

void ADDMMOCharacter::ClearChatMessage()
{
	CurrentMessage = "";
	UpdateChatText();
}

void ADDMMOCharacter::ServerSendChatMessage_Implementation(const FString & Message)
{
	SendChatMessage(Message);
}

bool ADDMMOCharacter::ServerSendChatMessage_Validate(const FString& Message)
{
	if (Message.Len() < 255)
	{
		return true;
	}
	else
		return false; // will boot player out of the game.
}

void ADDMMOCharacter::OnRep_CurrentMessage()
{
	UpdateChatText();
}

void ADDMMOCharacter::UpdateChatText()
{
	ChatText->SetText(FText::FromString(CurrentMessage));

}

//void ADDMMOCharacter::OpenChatWidget()
//{
//	if (NameplateUIClass)
//	{
//		if (!NameplateWidget)
//		{
//			NameplateWidget = CreateWidget<UUserWidget>(GetWorld()->GetGameInstance(), NameplateUIClass);
//			if (!NameplateWidget)
//			{
//				return;
//			}
//
//			NameplateWidget->AddToViewport();
//			NameplateWidget->SetVisibility(ESlateVisibility::Hidden);
//		}
//	}
//}

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