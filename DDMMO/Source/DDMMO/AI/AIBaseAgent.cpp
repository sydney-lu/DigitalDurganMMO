// Copyright Digital Durgan studios. All rights reserved.

#include "AIBaseAgent.h"


AAIBaseAgent::AAIBaseAgent()
{
	PrimaryActorTick.bCanEverTick = true;

	if (maxHealth <= 0) maxHealth = 10.f;
	currentHealth = maxHealth;
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
	currentHealth -= DamageAmount;
	if (currentHealth <= 0.0f)
	{
		UE_LOG(LogTemp, Display, TEXT("You destroyed an enemy."));
		Destroy();
	}
	return 0.0f;
}

