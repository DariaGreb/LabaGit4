// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Ball.generated.h"

UCLASS()
class TOCHNOCONTROLWORK_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float Mass;

	UStaticMesh* asset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	float ForcePower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PARAMETERS)
	FVector Force;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
