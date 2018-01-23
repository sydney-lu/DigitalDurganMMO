// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DDMMOCharacter.generated.h"

//  Player can only be in one state at a time
UENUM(BlueprintType)
enum class PlayerCharacterState : uint8
{
	IDLE				UMETA(DisplayName = "Idle"),
	ATTACKING			UMETA(DisplayName = "Attacking"),
	RESTING				UMETA(DisplayName = "Resting"),
	CASTING				UMETA(DisplayName = "Casting"),
	TRAVERSAL_WALK		UMETA(DisplayName = "TraversalWalk"),
	TRAVERSAL_RUN		UMETA(DisplayName = "TraversalRun"),
	TRAVERSAL_FLY		UMETA(DisplayName = "TraversalFly"),
	TRAVERSAL_SWIM		UMETA(DisplayName = "TraversalSwim"),
	DISABLED			UMETA(DisplayName = "Disabled"),
	HARDCROWDCONTROL	UMETA(DisplayName = "HardCrowdControl"),
	SOFTCROWDCONTROL	UMETA(DisplayName = "SoftCrowdControl")

};

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

	//UPROPERTY(EditAnywhere)
	//class USphereComponent* MeleeCollider;

	UPROPERTY(EditAnywhere)
	PlayerCharacterState CurrentState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Character)
	float Health_MAX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Character)
	float Health_CUR;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Character)
	float Mana_MAX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Character)
	float Mana_CUR;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Character)
	float Stamina_MAX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Character)
	float Stamina_CUR;

	UPROPERTY(EditAnywhere)
	float BasicAttackSpeed;

	UPROPERTY(EditAnywhere)
	float BasicAttackRange;

	UPROPERTY(EditAnywhere)
	float Zoom_Power;
	
	UPROPERTY(EditAnywhere)
	float ZoomIn_MAX;

	UPROPERTY(EditAnywhere)
	float ZoomOut_MAX;

	float CameraZoom_v;

protected:	// Traversal functions
	void MoveForward(float Value);
	void MoveRight(float Value);

protected:	// Camera Functions
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void ZoomIn();
	void ZoomOut();
	void RMBPressed();
	void RMBReleased();
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

	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABaseProjectile> ProjectileClass;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SetPlayerState(PlayerCharacterState NewState);

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

