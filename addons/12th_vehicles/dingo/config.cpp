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
    requiredAddons[] = {"TCP_Soft", "TCP_Soft_M12A"};
  };
};

class CfgVehicles {
  // Dingo base classes
  class SMT_DingoMed;
  class SMT_DingoTroop;
  class SMT_DingoCargo;
  class SMT_DingoRCWS_minigun;
  class SMT_DingoRCWS_autogun;
  class SMT_DingoRCWS_minigun_troop;
  class SMT_DingoRCWS_autogun_troop;

  class Twelfth_Dingo_Cargo: SMT_DingoCargo {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo Cargo";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "x\12thMEU\addons\main\logo.paa"
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
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "\x\12thMEU\addons\main\logo.paa"
				};
    DINGO_SP_INFO(1,FAV Minigun)
    STDINV
  };

  class Twelfth_Dingo_RCWS_autocannon: SMT_DingoRCWS_autogun {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo RCWS (autocannon)";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "\x\12thMEU\addons\main\logo.paa"
				};
    DINGO_SP_INFO(2,FAV Autocannon)
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
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "\x\12thMEU\addons\main\logo.paa"
				};
    // NOTE: the police texture here would look too weird
    DINGO_SP_INFO(3,Troop)
    STDINV
  };

    class Twelfth_Dingo_RCWS_minigun_troop: SMT_DingoRCWS_minigun_troop {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo Troop RCWS (minigun)";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "\x\12thMEU\addons\main\logo.paa"
				};
    DINGO_SP_INFO(4,Troop Minigun)
    STDINV
  };

  class Twelfth_Dingo_RCWS_autocannon_troop: SMT_DingoRCWS_autogun_troop {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo Troop RCWS (autocannon)";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "\x\12thMEU\addons\main\logo.paa"
				};
    DINGO_SP_INFO(5,Troop Autocannon)
    STDINV
  };
  class Twelfth_Dingo_Fav_Medical: SMT_DingoMed {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo Medical";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[] = {"camo1","camo7","camo11","camo12","camo13","unit"};
    hiddenSelectionsTextures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\autoturret_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\cloth_co.paa",
          "\x\12thMEU\addons\main\logo.paa"
				};
    DINGO_SP_INFO(6,Medical APC)
    MEDINV
  };
};