#include "script_component.hpp"
#include "config_macros.hpp"

class DefaultEventhandlers;
class CfgPatches {
  class vehicle_Viper {
    units[] = {
      "SMT_Viper"
    };
    weapons[] = { 
      "SMT_200mm"
    };
    ammo[] = {
        "SMT_200mm_HE_Slow",
        "SMT_200mm_HE",
        "SMT_200mm_SALH",
        "SMT_200mm_APFSDS"
        };              // No specific ammo defined in this config
    magazines[] = {
      "SMT_Mag_XXRnd_200mm_HE",
      "SMT_Mag_XXRnd_200mm_HE_Slow",
      "SMT_Mag_XXRnd_200mm_SALH",
      "SMT_Mag_XXRnd_200mm_APFSDS"
    };
    requiredVersion = 0.1;    // Minimum required version of the game
    requiredAddons[] = { 
      "A3_Weapons_F", "A3_Armor_F_Gamma","A3_Air_F","A3_Air_F_Beta","A3_Soft_F_Exp","A3_Characters_F_BLUFOR","SMT_core"    // List of required addons for this config to work
    };
  };
};

class CfgEditorSubcategories {
    class EDS_SMT_faction_Viper {
    displayName="Viper";  // Ground vehicles (cars, trucks).
  };
};

#include "model.cfg"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
