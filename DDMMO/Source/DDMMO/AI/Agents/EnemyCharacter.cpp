// Copyright Digital Durgan studios. All rights reserved.

#include "EnemyCharacter.h"

#include "Player/DDMMOCharacter.h"
#include "AI/Controllers/AIEnemyController.h"

#include "Perception/PawnSensingComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;

	maxHealth = 100.0f;
	currentHealth = maxHealth;

	damage = 10.0f;

	areaRadius = 3000.0f;

	attackDistance = 180.0f;
}

void AEnemyCharacter::BeginPlay()
{
	AAIEnemyController* controller = Cast<AAIEnemyController>(GetController());
	if (controller)
	{
		controller->SetBlackboardOwner(this);

		controller->SetWaypoint(GetActorLocation());

		controller->SetTarget(nullptr);

		controller->SetAreaRadius(areaRadius);
	}

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AEnemyCharacter::OnSeePlayer);
		PawnSensingComp->OnHearNoise.AddDynamic(this, &AEnemyCharacter::OnHearNoise);
	}
}

void AEnemyCharacter::OnSeePlayer(APawn * Pawn)
{
	if (!IsAlive())
		return;

	if (bIsReturning)
		return;

	AAIEnemyController* controller = Cast<AAIEnemyController>(GetController());
	ADDMMOCharacter* SensedPawn = Cast<ADDMMOCharacter>(Pawn);
	if (controller && SensedPawn)
	{
		if (target == nullptr)
		{
			bIsAttacking = true;
			target = SensedPawn;
			controller->SetTarget(SensedPawn);
		}
	}
}

void AEnemyCharacter::OnHearNoise(APawn * PawnInstigator, const FVector & Location, float Volume)
{
	if (!IsAlive())
		return;

	if (bIsReturning)
		return;

	AAIEnemyController* controller = Cast<AAIEnemyController>(GetController());
	ADDMMOCharacter* SensedPawn = Cast<ADDMMOCharacter>(PawnInstigator);
	if (controller && SensedPawn)
	{
		if (target == nullptr)
		{
			bIsAttacking = true;
			target = SensedPawn;
			controller->SetTarget(SensedPawn);
		}
	}
}
