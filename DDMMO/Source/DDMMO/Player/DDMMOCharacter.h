// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterClass.h"
#include "CharacterClassData.h"
#include "PlayerInfoWidget.h"
#include "TimerManager.h"
#include "DDMMO/Targetable.h"
#include "HUD_Main.h"
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

DECLARE_DELEGATE(SkillLogic);

UCLASS(config=Game)
class ADDMMOCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	TArray<SkillLogic> SkillLogicDelegates;

public:	// Class UI References

	UPROPERTY()
		UHUD_Main* MainHud;

	UPROPERTY()
		UPlayerInfoWidget* skillSelectionWidget;

	UPROPERTY(BlueprintReadWrite)
		UPlayerInfoWidget* SelectedWidged;

	UPROPERTY(VisibleAnywhere)
		UCharacterClass* characterClass;

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

	UPROPERTY(EditAnywhere, Category = Targeting)
	AActor* CurrentTarget;

	UPROPERTY(EditAnywhere, Category = Targeting)
	FTimerHandle TargetingHandle;

	UPROPERTY(EditAnywhere,Category = Targeting)
	float TargetingRange = 5000;

	UPROPERTY(EditAnywhere, Category = Targeting)
	float TargetingRate = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsAttacking;

protected:
	virtual void BeginPlay() override;

protected:	// Traversal functions
	void MoveForward(float Value);
	void MoveRight(float Value);

protected:	// Camera Functions
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void ZoomIn();
	void ZoomOut();

protected:	// Targeting
	UFUNCTION()
	void FindTarget();
	void SetTarget(AActor* newTarget);

protected:	// UI Functions
	UFUNCTION(BlueprintCallable)
	void SetSkillSelection(UPlayerInfoWidget* widget);

	UFUNCTION(BlueprintCallable)
	void SetSkillDelegate(int index, UCharacterSkillData* skillData);

protected:	// Action Functions
	void Inventory();
	void CharacterMenu();
	void SkillMenu();
	void MainMenu();
	void Interact();
	void SwitchTargetLock();

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
	void SkillTen();
	void SkillEleven();

	void Fire();
	void BasicAttack();
	void Defense();
	void ToggleCrouch();
	
	float CurrentSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABaseProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
	class USphereComponent* MeleeCollider;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SetPlayerState(PlayerCharacterState NewState);
	virtual void Destroyed() override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	UFUNCTION(BlueprintCallable)
	//void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	void OnMeleeHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};