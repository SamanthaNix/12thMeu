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
      "Twelfth_Dingo_RCWS_minigun",
      "Twelfth_M12A_ALIM_M68A_fix",
      "Twelfth_M12A_ALIM_M68B_fix"
    };
    requiredVersion = 0.1;
    requiredAddons[] = {"TCP_Soft", "TCP_Soft_M12A"};
  };
};

class CfgVehicles {
  // warthog base classes
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
    class TransportMagazines {   
      class _xx_OPTRE_32Rnd_762x51_Mag_Tracer { magazine = "OPTRE_32Rnd_762x51_Mag_Tracer"; count = 4; }; 
      class _xx_OPTRE_36Rnd_95x40_Mag_Tracer { magazine = "OPTRE_36Rnd_95x40_Mag_Tracer"; count = 4; };
    };
    class TransportItems{
      class _xx_kat_IV_16 { name = "kat_IV_16"; count = 10; };     
      class _xx_kat_AFAK { name = "kat_AFAK"; count = 4; };    
      class _xx_kat_MFAK { name = "kat_MFAK"; count = 2; };    
      class _xx_ACE_tourniquet { name = "ACE_tourniquet"; count = 8; };    
      class _xx_kat_bloodIV_O_N_500 { name = "kat_bloodIV_O_N_500"; count = 10; };     
      class _xx_ACE_splint { name = "ACE_splint"; count = 8; };    
      class _xx_ACE_morphine { name = "ACE_morphine"; count = 10; };   
      class _xx_ACE_adenosine { name = "ACE_adenosine"; count = 10; };     
      class _xx_ACE_epinephrine { name = "ACE_epinephrine"; count = 10; };     
      class _xx_ACE_salineIV { name = "ACE_salineIV"; count = 5; };    
      class _xx_ACE_suture { name = "ACE_suture"; count = 40; };   
    };
  };
  class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class Turrets
		{
			class MainTurret;
		};
	};
  class TCP_M12A_base: Car_F {
    class Turrets;
	};
  class TCP_M12A_ALIM_M68A_base: TCP_M12A_base {
    class Turrets: Turrets {
      class M68A_Turret;
    };
  };
  class TCP_M12A_ALIM_M68B_base: TCP_M12A_ALIM_M68A_base {
    class Turrets: Turrets {
      class M68A_Turret;
    };
  };
  class Twelfth_M12A_ALIM_M68A_fix: TCP_M12A_ALIM_M68A_base {
    scope=2;
    side = 1;
    scopeCurator=2;
    author="idk";
    crew = "TCP_B_UNSC_A_Soldier";
    typicalCargo[] = {"TCP_B_UNSC_A_Soldier"};
    displayName="[12th] M12AG1 LAAV Warthog (M68A) HOTFIX";
    hiddenSelectionsTextures[] = {"\TCP\Soft\M12A\data\camo\olive\M12A_Ext_CO.paa","\TCP\Soft\M12A\data\camo\default\M12A_Int_CO.paa","\TCP\Soft\M12A\data\camo\default\M12A_Tub_CO.paa","\TCP\Soft\M12A\data\camo\default\M12A_Susp_CO.paa","\TCP\Soft\M12A\data\camo\olive\M12A_Rim_CO.paa","\TCP\Soft\M12A\data\camo\black\M12A_DecalSheet_CA.paa","\TCP\static\M68A_ALIM\data\camo\olive\M68A_ALIM_01_CO.paa"};
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    class SimpleObject{};
		threat[] = {0.1,0.1,0.1};
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    class Turrets: Turrets {
      class M68A_Turret: M68A_Turret {
        memoryPointGunnerOptics = "pip4_pos";
				memoryPointGunnerOutOptics = "pip4_pos";
        gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
        class ViewOptics {
					initAngleX = 0;
					initAngleY = 0;
					initFov = 0.4375;
					maxAngleX = 30;
					maxAngleY = 100;
					maxFov = 0.4375;
					maxMoveX = 0;
					maxMoveY = 0;
					maxMoveZ = 0;
					minAngleX = -30;
					minAngleY = -100;
					minFov = 0.03482;
					minMoveX = 0;
					minMoveY = 0;
					minMoveZ = 0;
					thermalMode[] = {0,1};
					visionMode[] = {"Normal","NVG","Ti"};
				};
      };
    };
  };
  class Twelfth_M12A_ALIM_M68B_fix: TCP_M12A_ALIM_M68B_base {
    scope=2;
    side = 1;
    scopeCurator=2;
    author="idk";
    crew = "TCP_B_UNSC_A_Soldier";
    typicalCargo[] = {"TCP_B_UNSC_A_Soldier"};
    displayName="[12th] M12AG2 LAAV Warthog (M68B) HOTFIX";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    class SimpleObject{};
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    class Turrets: Turrets {
      class M68A_Turret: M68A_Turret {
        memoryPointGunnerOptics = "pip4_pos";
				memoryPointGunnerOutOptics = "pip4_pos";
        gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
        class ViewOptics {
					initAngleX = 0;
					initAngleY = 0;
					initFov = 0.4375;
					maxAngleX = 30;
					maxAngleY = 100;
					maxFov = 0.4375;
					maxMoveX = 0;
					maxMoveY = 0;
					maxMoveZ = 0;
					minAngleX = -30;
					minAngleY = -100;
					minFov = 0.03482;
					minMoveX = 0;
					minMoveY = 0;
					minMoveZ = 0;
					thermalMode[] = {0,1};
					visionMode[] = {"Normal","NVG","Ti"};
				};
      };
    };
  };
};