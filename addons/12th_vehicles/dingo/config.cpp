#pragma hemtt suppress pw3_padded_arg config
#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_dingos {
    units[] = {
      "Twelfth_Dingo_Cargo",
      "Twelfth_Dingo_Troop",
      "Twelfth_Dingo_Fav_Medical",
      "Twelfth_Dingo_RCWS_autocannon",
      "Twelfth_Dingo_RCWS_minigun"
    };
    requiredVersion = 0.1;
  };
};

class CfgVehicles {
  // Dingo base classes
  class SMT_DingoMed;
  class SMT_DingoTroop;
  class SMT_DingoCargo;
  class SMT_DingoRCWS_minigun;
  class SMT_DingoRCWS_autocannon;


  class Twelfth_Dingo_Cargo: SMT_DingoCargo {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo Cargo";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1","camo7","camo11","camo8"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
      "\x\12thMEU\addons\12th_vehicles\dingo\default\decals_ca.paa"
    };
    DINGO_SP_INFO(0,FAV)
    STDINV
  };

  class Twelfth_Dingo_RCWS_minigun: SMT_DingoRCWS_minigun {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo RCWS (minigun)";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1","camo7","camo11","camo8"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
      "\x\12thMEU\addons\12th_vehicles\dingo\default\decals_ca.paa"
    };
    DINGO_SP_INFO(0,FAV)
    STDINV
  };

  class Twelfth_Dingo_RCWS_autocannon: SMT_DingoRCWS_autocannon {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo RCWS (autocannon)";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1","camo7","camo11","camo8"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
      "\x\12thMEU\addons\12th_vehicles\dingo\default\decals_ca.paa"
    };
    DINGO_SP_INFO(0,FAV)
    STDINV
  };

  class Twelfth_Dingo_Troop: SMT_DingoTroop {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Dingo Troop";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1","camo7","camo11","camo8"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
      "\x\12thMEU\addons\12th_vehicles\dingo\default\decals_ca.paa"
    };
    // NOTE: the police texture here would look too weird
    DINGO_SP_INFO(1,Troop)
    STDINV
  };

  class Twelfth_Dingo_Fav_Medical: SMT_DingoMed {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Dingo Medical";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1","camo7","camo11","camo8"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
      "\x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
      "\x\12thMEU\addons\12th_vehicles\dingo\default\decals_ca.paa"
    };
    DINGO_SP_INFO(2,Medical APC)
    MEDINV
  };

};