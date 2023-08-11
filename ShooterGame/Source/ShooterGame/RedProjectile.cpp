// Fill out your copyright notice in the Description page of Project Settings.


#include "RedProjectile.h"

#include "RedEnemy.h"


void ARedProjectile::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		ARedEnemy* RedEnemy = Cast<ARedEnemy>(OtherActor);
		if (RedEnemy)
		{
			RedEnemy->Health -= 10.f;
			Destroy();
		}
	}
}

void ARedProjectile::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentHit.AddDynamic(this, &ARedProjectile::ComponentHit);
}