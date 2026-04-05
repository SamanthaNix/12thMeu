#pragma hemtt suppress pw3_padded_arg config
#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_warthogs {
    units[] = {
      "Twelfth_DingoCargo",
      "twelfth_Dingo_troop",
      "twelfth_dingo_fav_medical"
    };
    requiredVersion = 0.1;
  };
};

class CfgVehicles {
  // warthog base classes
  class SMT_DingoMed;
  class SMT_DingoTroop;
  class SMT_DingoCargo;


  class Twelfth_Dingo_Cargo: SMT_DingoCargo {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] Dingo Cargo";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1","camo7","camo8"};
    hiddenSelectionsTextures[] = {
      "x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
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
    hiddenSelections[]= {"camo1","camo7","camo8"};
    hiddenSelectionsTextures[] = {
      "x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
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
    hiddenSelections[]= {"camo1","camo7","camo8"};
    hiddenSelectionsTextures[] = {
      "x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
      "x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
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

};