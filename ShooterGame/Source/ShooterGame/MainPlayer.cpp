// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "RedProjectile.h"
#include "BlueProjectile.h"
#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include "MainPlayerController.h"
// Sets default values
AMainPlayer::AMainPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	Health = 100.f;
	OverlappedByEnemy = false;
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AMainPlayer::ComponentHit);


}
void AMainPlayer::MoveForward(float Value)
{
	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, Value);
}

void AMainPlayer::MoveRight(float Value)
{
	FVector Right = GetActorRightVector();
	AddMovementInput(Right, Value);
}

void AMainPlayer::LeftClick()
{
	FVector ForwardVector = GetActorForwardVector();
	float SpawnDistance = 40.f;

	FVector SpawnLocation = GetActorLocation() + (ForwardVector * SpawnDistance);

	GetWorld()->SpawnActor<ARedProjectile>(RedProjectileClass, SpawnLocation, GetActorRotation());
}

void AMainPlayer::RightClick()
{
	FVector ForwardVector = GetActorForwardVector();
	float SpawnDistance = 40.f;

	FVector SpawnLocation = GetActorLocation() + (ForwardVector * SpawnDistance);

	GetWorld()->SpawnActor<ABlueProjectile>(BlueProjectileClass, SpawnLocation, GetActorRotation());

}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AMainPlayerController* control = Cast<AMainPlayerController>(GetController());

	if (control != nullptr)
	{
		control->UpdateHealthPercent(Health / 100.f);
		if (Health <= 0)
		{
			control->ShowRestartWidget();
		}
	}

	if (OverlappedByEnemy)
	{
		Health -= 10.f;
		OverlappedByEnemy = false;
	}

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &AMainPlayer::LeftClick);
	PlayerInputComponent->BindAction("RightClick", IE_Pressed, this, &AMainPlayer::RightClick);
}

void AMainPlayer::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AEnemy* enemy = Cast<AEnemy>(OtherActor);

	if (enemy)
		OverlappedByEnemy = true;
}
