// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	SetRootComponent(BaseMesh);

	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshToMyMesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	

	if (StaticMeshToMyMesh.Succeeded())
	{
		asset = StaticMeshToMyMesh.Object;
		BaseMesh->SetStaticMesh(asset);
	}
	

	Mass = 1.0f;
	Force = FVector(0.0f, 0.0f, 980.0f);
	ForcePower = 109.45668f;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	BaseMesh->SetSimulatePhysics(true);
	BaseMesh->SetEnableGravity(true);


}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	BaseMesh->AddForce(Force * ForcePower);

}

