#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "JaegerUnit.generated.h"

UENUM(BlueprintType)
enum class EJaegerClass : uint8
{
    Striker    UMETA(DisplayName = "Striker / Brawler"),
    Artillery  UMETA(DisplayName = "Heavy Support / Ranged"),
    Vanguard   UMETA(DisplayName = "Frontline / Shield")
};

UCLASS()
class PACIFICRIMBREACHFALL_API AJaegerUnit : public APawn
{
    GENERATED_BODY()

public:
    AJaegerUnit();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    // --- Components ---
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class USkeletalMeshComponent* MechaMesh;

    // --- Stats & Properties ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jaeger Stats")
    FString JaegerName = TEXT("Gipsy Prime");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jaeger Stats")
    EJaegerClass UnitType = EJaegerClass::Striker;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jaeger Stats")
    float MaxHullIntegrity = 1000.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Jaeger Stats")
    float CurrentHullIntegrity;

    // --- Combat Actions ---
    UFUNCTION(BlueprintCallable, Category = "Jaeger Actions")
    void TakeKaijuDamage(float DamageAmount);

    UFUNCTION(BlueprintImplementableEvent, Category = "Jaeger Events")
    void OnHullCritical();
};
