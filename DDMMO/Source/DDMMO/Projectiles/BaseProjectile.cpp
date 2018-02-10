// Copyright Digital Durgan studios. All rights reserved.

#include "BaseProjectile.h"
//#include "EngineMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AI/AIBaseAgent.h"

ABaseProjectile::ABaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ColliderRadius = 3.f;
	InitVelocity = 3000.f;
	MaxVelocity = 3000.f;
	Buoyancy = 0.3f;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(ColliderRadius);
	RootComponent = CollisionComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = InitVelocity;
	ProjectileMovementComponent->MaxSpeed = MaxVelocity;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = Buoyancy;

	CollisionComponent->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
	//CollisionComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ABaseProjectile::OverlapBegins);
}

void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		AAIBaseAgent* RecastedBaseAgent = Cast<AAIBaseAgent>(OtherActor);
		if (RecastedBaseAgent)
		{
			TSubclassOf<UDamageType> P;
			UGameplayStatics::ApplyPointDamage(OtherActor, 5.0f, GetActorLocation(), Hit, nullptr, this, P);
			Destroy();
		}
		Destroy();
	}
}
