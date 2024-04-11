// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DrunkenMogus : ModuleRules
{
	public DrunkenMogus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			"DeveloperSettings"
			
		});
	}
}
