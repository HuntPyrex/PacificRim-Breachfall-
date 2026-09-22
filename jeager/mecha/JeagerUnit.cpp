#include "JaegerUnit.h"
#include "Components/SkeletalMeshComponent.h"

AJaegerUnit::AJaegerUnit()
{
    PrimaryActorTick.bCanEverTick = true;

    MechaMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MechaMesh"));
    RootComponent = MechaMesh;

    CurrentHullIntegrity = MaxHullIntegrity;
}

void AJaegerUnit::BeginPlay()
{
    Super::BeginPlay();
}

void AJaegerUnit::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AJaegerUnit::TakeKaijuDamage(float DamageAmount)
{
    CurrentHullIntegrity = FMath::Clamp(CurrentHullIntegrity - DamageAmount, 0.0f, MaxHullIntegrity);

    if (CurrentHullIntegrity <= MaxHullIntegrity * 0.2f)
    {
        OnHullCritical();
    }
}
