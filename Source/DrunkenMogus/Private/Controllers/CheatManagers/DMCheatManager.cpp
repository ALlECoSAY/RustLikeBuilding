// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Controllers/CheatManagers/DMCheatManager.h"

void UDMCheatManager::InitCheatManager()
{
	Super::InitCheatManager();

	for (const auto CheatManagerExtensionClass : CheatManagerExtensionsClasses)
	{
		if (CheatManagerExtensionClass)
		{
			UCheatManagerExtension* CheatManagerExtension = NewObject<UCheatManagerExtension>(this, CheatManagerExtensionClass);
			if (CheatManagerExtension)
			{
				AddCheatManagerExtension(CheatManagerExtension);
			}
		}
	}
	

	
}
