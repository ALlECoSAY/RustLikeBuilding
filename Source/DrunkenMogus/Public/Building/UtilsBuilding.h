#pragma once

/*
 *  UtilFunctionsBuilding.h
*/

#include "CoreMinimal.h"


UENUM(BlueprintType, Category = "Building|Socket", meta = (DisplayName = "Socket Type"))
enum class EBuildingSocketType : uint8
{
 Center UMETA(DisplayName = "Center"),
 Side UMETA(DisplayName = "Side"),
 Corner UMETA(DisplayName = "Corner"),
 MAX UMETA(Hidden = "true")
};



UENUM(BlueprintType, Category = "Building|Grade", meta = (DisplayName = "Grade Type"))
enum class EBuildingGradeType : uint8
{
 Grade1 UMETA(DisplayName = "Grade 1"),
 Grade2 UMETA(DisplayName = "Grade 2"),
 Grade3 UMETA(DisplayName = "Grade 3"),
 MAX UMETA(Hidden = "true")
};


UENUM(BlueprintType, Category = "Resource", meta = (DisplayName = "Resource Type"))
enum class EResourceType : uint8
{
 ResourceA UMETA(DisplayName = "Resource A"),
 ResourceB UMETA(DisplayName = "Resource B"),
 ResourceC UMETA(DisplayName = "Resource C"),
 MAX UMETA(Hidden = "true")
};

#pragma region to_string

static const char* to_string(EBuildingSocketType e)
{
 switch (e)
 {
 case EBuildingSocketType::Center: return "Center";
 case EBuildingSocketType::Side: return "Side";
 case EBuildingSocketType::Corner: return "Corner";
 case EBuildingSocketType::MAX: return "MAX";
 default: return "unknown";
 }
}

static const char* to_string(EBuildingGradeType e)
{
 switch (e)
 {
 case EBuildingGradeType::Grade1: return "Grade1";
 case EBuildingGradeType::Grade2: return "Grade2";
 case EBuildingGradeType::Grade3: return "Grade3";
 case EBuildingGradeType::MAX: return "MAX";
 default: return "unknown";
 }
}

static const char* to_string(EResourceType e)
{
 switch (e)
 {
 case EResourceType::ResourceA: return "ResourceA";
 case EResourceType::ResourceB: return "ResourceB";
 case EResourceType::ResourceC: return "ResourceC";
 case EResourceType::MAX: return "MAX";
 default: return "unknown";
 }
}

#pragma endregion

