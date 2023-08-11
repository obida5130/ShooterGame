// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueProjectile.h"
#include "BlueEnemy.h"

void ABlueProjectile::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		ABlueEnemy* BlueEnemy = Cast<ABlueEnemy>(OtherActor);
		if (BlueEnemy)
		{
			BlueEnemy->Health -= 10.f;
			Destroy();
		}
	}
}

void ABlueProjectile::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentHit.AddDynamic(this, &ABlueProjectile::ComponentHit);
}
