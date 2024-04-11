// Oleksii Pushkarov practice Rust-alike Building System + UI

using UnrealBuildTool;
using System.Collections.Generic;

public class DrunkenMogusClientTarget : TargetRules //Change this line according to the name of your project
{
	public DrunkenMogusClientTarget(TargetInfo Target) : base(Target) //Change this line according to the name of your project
	{
		Type = TargetType.Client;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("DrunkenMogus"); //Change this line according to the name of your project
	}
}