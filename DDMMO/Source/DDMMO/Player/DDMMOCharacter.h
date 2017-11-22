// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DDMMOCharacter.generated.h"

UCLASS(config=Game)
class ADDMMOCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ADDMMOCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
	
	UPROPERTY(EditAnywhere)
	float Zoom_Power;
	
	UPROPERTY(EditAnywhere)
	float ZoomIn_Max;

	UPROPERTY(EditAnywhere)
	float ZoomOut_Max;

	float CameraZoom_v;

	//// The class that will be used for the Items Nameplate
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	//	TSubclassOf<class UUserWidget> NameplateUIClass;

	//// The instance of the players Inventory UI Widget
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	//	class UUserWidget* NameplateWidget;

	virtual void BeginPlay() override;

	// Networking
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;		//	What do we want to replicate in terms of networking, and what we don't want.

	// Chat System
	class UTextRenderComponent* ChatText;

	UFUNCTION(BlueprintCallable, Category = "Chat/Messaging")
	void AttemptToSendChatMessage(const FString& Message); //	Const references for networking

private:  // Chat System 
	void SendChatMessage(const FString& Message); // Sends a message, only call this function if we are the server, otherwise use ServerChatMessage.
	void ClearChatMessage(); //	Clears the current message, called automatically after 5 seconds after sending the message.

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSendChatMessage(const FString& Message);
	void ServerSendChatMessage_Implementation(const FString& Message);
	bool ServerSendChatMessage_Validate(const FString& Message);

	UFUNCTION()
	void OnRep_CurrentMessage();
	void UpdateChatText();

protected:  // Chat System
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, ReplicatedUsing = OnRep_CurrentMessage, Category = "Chat/Messaging")
	FString CurrentMessage;	//	Whenever this variable changes, we automatically call 'OnRep_CurrentMessage' 

	//void OpenChatWidget();

protected:	// Traversal functions
	void MoveForward(float Value);
	void MoveRight(float Value);

protected:	// Camera Functions
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void ZoomIn();
	void ZoomOut();
	void RMB();
	void LMBPressed();
	void LMBReleased();
	void CenterViewportCursor(const APlayerController* PlayerController);

protected:	// Action Functions
	void OpenBag();
	void CharacterInfo();
	void SkillInfo();
	void Interact();

protected:	// Skill Functions
	void SkillZero();
	void SkillOne();
	void SkillTwo();
	void SkillThree();
	void SkillFour();
	void SkillFive();
	void SkillSix();
	void SkillSeven();
	void SkillEight();
	void SkillNine();
	void SkillOemminus();
	void SkillOemplus();



protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

