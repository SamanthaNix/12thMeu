#pragma hemtt suppress pw3_padded_arg config
#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_warthogs {
    units[] = {
      "twelfth_warthog_fav",
      "twelfth_warthog_fav_apc",
      "twelfth_warthog_fav_medical",
      "twelfth_warthog_tt",
      "twelfth_warthog_mg",
      "twelfth_warthog_atgm",
      "twelfth_warthog_gauss",
      "twelfth_warthog_mlms",
    };
    requiredAddons[]= {
      "TCP_soft"
    };
    requiredVersion = 0.1;
  };
};

class CfgVehicles {
  // warthog base classes
  class OPTRE_M12_FAV_APC;
  class OPTRE_M12_FAV_APC_MED;
  class TCP_B_UNSC_MC_M12A;
  class TCP_B_UNSC_MC_M12A_LAAG_M41;
  class OPTRE_M12A1_LRV;
  class TCP_B_UNSC_MC_M831A;
  class OPTRE_M12G1_LRV;
  class OPTRE_M12R_AA;
  class SAG6_M12_MLMS;


  class twelfth_warthog_fav: TCP_B_UNSC_MC_M12A {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog FAV";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
 /*    hiddenSelections[]= {"camo1", "camo2", "camo_doors"};
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa", 
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa", 
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa",
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1
    }; */
    WARTHOG_SP_INFO(0,FAV)
    STDINV
  };

  class twelfth_warthog_fav_apc: OPTRE_M12_FAV_APC {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog APC";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\troop_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    // NOTE: the police texture here would look too weird
    class TextureSources {
      WARTHOG_TEX_STD_V1_APC
    };
    WARTHOG_SP_INFO(1,APC)
    STDINV
  };

  class twelfth_warthog_fav_medical: OPTRE_M12_FAV_APC_MED {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog Medical";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\troop_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1_MED
    };
    WARTHOG_SP_INFO(2,Medical APC)
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

  class twelfth_warthog_tt: TCP_B_UNSC_MC_M831A {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog TT";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    /*
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\troop_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    // NOTE: the police texture here would look too weird
    class TextureSources {
      WARTHOG_TEX_STD_V1_APC
    };*/
    WARTHOG_SP_INFO(3,Troop Transport)
    STDINV
  };

  class twelfth_warthog_mg: TCP_B_UNSC_MC_M12A_LAAG_M41 {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog MG";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    /*
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo_doors"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m12_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1_M12
    };*/
    WARTHOG_SP_INFO(4,MG)
    STDINV
  };

  class twelfth_warthog_atgm: OPTRE_M12A1_LRV {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog ATGM";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo_doors"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m12_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1_M12
    };
    WARTHOG_SP_INFO(5,ATGM)
    STDINV
  };

  class twelfth_warthog_gauss: OPTRE_M12G1_LRV {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog Gauss";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4", "camo_doors"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m68_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m12_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1_M68
    };
    WARTHOG_SP_INFO(6,Gauss)
    STDINV
  };

  class twelfth_warthog_aa: OPTRE_M12R_AA {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog AA";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4", "camo_doors"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m79_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m12_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1_M79
    };
    WARTHOG_SP_INFO(7,AA)
    STDINV
  };

  class twelfth_warthog_mlms: SAG6_M12_MLMS {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Warthog MLMS";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4", "camo_doors"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_vehicles\warthog\default\body_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\under_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m79_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\m12_co.paa",
      "\x\12thMEU\addons\12th_vehicles\warthog\default\apc_co.paa"
    };
    class TextureSources {
      WARTHOG_TEX_STD_V1_M79
    };
    WARTHOG_SP_INFO(8,MLMS)
    STDINV
  };

};