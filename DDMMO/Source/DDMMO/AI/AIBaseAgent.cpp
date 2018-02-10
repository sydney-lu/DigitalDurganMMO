// Copyright Digital Durgan studios. All rights reserved.

#include "AIBaseAgent.h"


AAIBaseAgent::AAIBaseAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	CURHEALTH = MAXHEALTH;
}

void AAIBaseAgent::BeginPlay()
{

}

void AAIBaseAgent::Tick(float DeltaTime)
{

}

void AAIBaseAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AAIBaseAgent::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	//return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	UE_LOG(LogTemp, Display, TEXT("Damaged"));
	CURHEALTH -= DamageAmount;
	if (CURHEALTH <= 0.0f)
	{
		Destroy();
	}
	return 0.0f;
}

