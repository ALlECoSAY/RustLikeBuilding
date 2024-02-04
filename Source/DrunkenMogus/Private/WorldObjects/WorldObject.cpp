// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjects/WorldObject.h"

AWorldObject::AWorldObject()
{

	const auto NewRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(NewRootComponent);
	
}


void AWorldObject::BeginPlay()
{
	Super::BeginPlay();
	
}
