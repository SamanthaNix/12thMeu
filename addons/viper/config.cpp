class DefaultEventhandlers;
class CfgPatches {
  class vehicle_Viper {
    units[] = {
      "SMT_Viper"
    };
    weapons[] = { 
      "SMT_200mm"
    };
    ammo[] = {};              // No specific ammo defined in this config
    magazines[] = {
      "SMT_500Rnd_20mm_shells_Dingo"
    };
    requiredVersion = 0.1;    // Minimum required version of the game
    requiredAddons[] = { 
      "A3_Weapons_F", "A3_Armor_F_Gamma","A3_Air_F","A3_Air_F_Beta","A3_Soft_F_Exp","A3_Characters_F_BLUFOR"    // List of required addons for this config to work
    };
  };
};