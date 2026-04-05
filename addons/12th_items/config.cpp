#include "script_component.hpp"
//Fixed with the help of Crowdedlight

class CfgPatches {
  class 12th_items {
    units[] = {
	  "Dons_Radio"
    };
    weapons[] = {};           // No specific weapons defined in this config
    ammo[] = {};              // No specific ammo defined in this config
    magazines[] = {
    };
    requiredVersion = 0.1;    // Minimum required version of the game
    requiredAddons[] = {      // List of required addons for this config to work
      "kat_pharma",           // KAT medical module
      "OPTRE_ACE_Compat",     // OPTRE and ACE compatibility module
      "ace_medical_engine"    // ACE medical engine
    };
  };
};

class CfgEditorCategories
{
	class 12th_Assets // Category class, you point to it in editorCategory property
	{
		displayName = "12th MEU Props"; // Name visible in the list
	};
};
    class CfgEditorSubcategories ///sub category creation.
{
	class Misc_Props
	{
		displayName="Misc Props";
	};
	

};



#include "CfgVehicles.hpp"
