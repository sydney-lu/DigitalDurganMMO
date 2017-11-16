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

