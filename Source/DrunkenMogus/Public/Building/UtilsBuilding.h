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




UENUM(BlueprintType, Category = "Building|Grade", meta = (DisplayName = "Resource Type"))
enum class EBuildingGrade : uint8
{
 Grade1 UMETA(DisplayName = "Grade 1"),
 Grade2 UMETA(DisplayName = "Grade 2"),
 Grade3 UMETA(DisplayName = "Grade 3"),
 MAX UMETA(Hidden = "true")
};

UENUM(BlueprintType, Category = "Building", meta = (DisplayName = "BuildingNode Type"))
enum class EBuildingNode : uint8
{
 SquareFoundation UMETA(DisplayName = "Square Foundation"),
 TriangleFoundation UMETA(DisplayName = "Triangle Foundation"),
 MAX UMETA(Hidden = "true")
};

//todo exclude from project
UENUM(BlueprintType, Category = "Building|Sockets", meta = (Bitflags, DisplayName = "SquareFoundation Sockets"))
enum ESquareFoundationSocket
{
 SquareFoundation0 UMETA(DisplayName = "Square Foundation 0"),
 SquareFoundation1 UMETA(DisplayName = "Square Foundation 1"),
 SquareFoundation2 UMETA(DisplayName = "Square Foundation 2"),
 SquareFoundation3 UMETA(DisplayName = "Square Foundation 3"),
 TriangleFoundation0 UMETA(DisplayName = "Triangle Foundation 0"),
 TriangleFoundation1 UMETA(DisplayName = "Triangle Foundation 1"),
 TriangleFoundation2 UMETA(DisplayName = "Triangle Foundation 2"),
 TriangleFoundation3 UMETA(DisplayName = "Triangle Foundation 3"),
 MAX UMETA(Hidden = "true")
};
ENUM_CLASS_FLAGS(ESquareFoundationSocket);

/*UENUM(BlueprintType, Category = "Building|Sockets", meta = (DisplayName = "TriangleFoundation Sockets"))
enum class ETriangleFoundationSocket : uint8
{
 SquareFoundation0 UMETA(DisplayName = "Square Foundation 0"),
 SquareFoundation1 UMETA(DisplayName = "Square Foundation 1"),
 SquareFoundation2 UMETA(DisplayName = "Square Foundation 2"),
 TriangleFoundation0 UMETA(DisplayName = "Triangle Foundation 0"),
 TriangleFoundation1 UMETA(DisplayName = "Triangle Foundation 1"),
 TriangleFoundation2 UMETA(DisplayName = "Triangle Foundation 2"),
 MAX UMETA(Hidden = "true")
};*/


UENUM(BlueprintType, Category = "Resource", meta = (DisplayName = "Resource Type"))
enum class EResource : uint8
{
 ResourceA UMETA(DisplayName = "Resource A"),
 ResourceB UMETA(DisplayName = "Resource B"),
 ResourceC UMETA(DisplayName = "Resource C"),
 MAX UMETA(Hidden = "true")
};


#pragma region to_string

class DRUNKENMOGUS_API EnumHelpers
{
public:
 static FString EnumToString(EBuildingNode Enum)
 {
  switch (Enum)
  { 
  case EBuildingNode::SquareFoundation: return "SquareFoundation";
  case EBuildingNode::TriangleFoundation: return "TriangleFoundation";
  case EBuildingNode::MAX: return "MAX";
  default:
   checkNoEntry()
   return "unknown";
  }
 }

 
 
};
#pragma endregion


