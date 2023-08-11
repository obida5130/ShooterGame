#include "EnemySpawner.h"
#include "RedEnemy.h"
#include "BlueEnemy.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Area"));
    SpawnArea->SetupAttachment(RootComponent);

    SpawnDelay = 1.0f; 
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
    Super::BeginPlay();
    GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnDelay, true);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemySpawner::SpawnEnemy()
{
    float random = FMath::FRandRange(0, 10);

    FBoxSphereBounds bounds = SpawnArea->Bounds;
    FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(bounds.Origin, bounds.BoxExtent);

    if (random <= 5)
    {
        GetWorld()->SpawnActor<ARedEnemy>(RedEnemyClass, SpawnLocation, GetActorRotation());
    }
    else
    {
        GetWorld()->SpawnActor<ABlueEnemy>(BlueEnemyClass, SpawnLocation, GetActorRotation());
    }
}
