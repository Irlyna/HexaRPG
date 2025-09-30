// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HexaRPG : ModuleRules
{
	public HexaRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"HexaRPG",
			"HexaRPG/Variant_Platforming",
			"HexaRPG/Variant_Platforming/Animation",
			"HexaRPG/Variant_Combat",
			"HexaRPG/Variant_Combat/AI",
			"HexaRPG/Variant_Combat/Animation",
			"HexaRPG/Variant_Combat/Gameplay",
			"HexaRPG/Variant_Combat/Interfaces",
			"HexaRPG/Variant_Combat/UI",
			"HexaRPG/Variant_SideScrolling",
			"HexaRPG/Variant_SideScrolling/AI",
			"HexaRPG/Variant_SideScrolling/Gameplay",
			"HexaRPG/Variant_SideScrolling/Interfaces",
			"HexaRPG/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
