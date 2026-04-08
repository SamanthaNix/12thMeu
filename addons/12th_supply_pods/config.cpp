/*
  ==============================================================================
  config.cpp

  This file configures custom supply pods for the 12th MEU mod. Each supply pod
  inherits from an OPTRE base class, but carries different inventories (medical,
  explosives, launcher ammo, mortar ammo, etc.). A logic module is also modified
  so these pods can be selected in an in-game Pelican Supply Drop module.

  Key Points:
    - CfgPatches: Identifies this as part of twelfth_supply_pods. Lists the
      supply pod units.
    - CfgVehicles: Contains all supply pod definitions, each inheriting from
      OPTRE_Ammo_SupplyPod_Empty but with different textures and inventory.
    - Module_OPTRE_PelicanSupplyDrop: Extended so mission makers can pick
      your custom 12th supply pods from a drop-down list in Eden Editor.

  ==============================================================================
*/

// Suppresses HEMTT's warning about padded arguments in config files
#pragma hemtt suppress pw3_padded_arg config

class CfgPatches {
  class twelfth_supply_pods {
    units[] = {
      "twelfth_supply_pod_empty",
      "twelfth_supply_pod_medical",
      "twelfth_supply_pod_ex",
      "twelfth_supply_pod_at",
      "twelfth_supply_pod_mortar",
      "twelfth_supply_pod_rifle",
      "twelfth_supply_pod_mg",
      "twelfth_supply_pod_eq"
    };
    weapons[] = {};
    requiredVersion = 0.1;
  };
}; 

class CfgVehicles {
  /*
    Base Class:
    OPTRE_Ammo_SupplyPod_Empty is from the OPTRE mod. 
    Make sure your mod includes "OPTRE_Weapons...", "OPTRE_Ammo..." or 
    appropriate references in your requiredAddons.
  */
  class OPTRE_Ammo_SupplyPod_Empty;

  // ---------------------------------------------------------------------------
  //  Empty Supply Pod
  // ---------------------------------------------------------------------------
  /*
    The "twelfth_supply_pod_empty" serves as the baseline for all pods below. 
    It retextures the base pod with a default texture. 
    Then it sets capacity and leaves inventory empty for custom usage.
  */
  class twelfth_supply_pod_empty: OPTRE_Ammo_SupplyPod_Empty {
    author = "Weber";
    scope = 2;          // Visible in Editor
    scopeCurator = 2;   // Visible in Zeus
    scopeArsenal = 2;   // Accessible in Virtual Arsenal
    displayName = "[12th] Supply Pod (Empty)";
    faction = "twelfth_MEU";         // Which faction it belongs to
    editorCategory ="12th_Assets";  // Editor category/folder
    editorSubcategory = "twelfth_MEU_Supplies"; // Editor subfolder

    // The maximum items/magazines/weapons this supply pod can hold
    transportMaxWeapons = 50;
    transportMaxMagazines = 200;
	  maximumLoad = 7500;

    // HiddenSelections for retexturing
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_equipment.paa"  
        // The default texture for an empty supply pod
    };

    // By default, no items, magazines, or weapons
    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {};
  };

  // ---------------------------------------------------------------------------
  //  Medical Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_medical: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Medical)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_medical.paa"
    };
    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {
      class _xx_kat_IV_16 { name = "kat_IV_16"; count = 25; };
      class _xx_kat_naloxone { name = "kat_naloxone"; count = 25; };
      class _xx_kat_AFAK { name = "kat_AFAK"; count = 10; };
      class _xx_kat_IFAK { name = "kat_IFAK"; count = 60; };
      class _xx_kat_MFAK { name = "kat_MFAK"; count = 10; };
      class _xx_kat_Painkiller { name = "kat_Painkiller"; count = 25; };
      class _xx_kat_Carbonate { name = "kat_Carbonate"; count = 25; };
      class _xx_kat_IO_FAST { name = "kat_IO_FAST"; count = 25; };
      class _xx_kat_phenylephrine_inject { name = "kat_phenylephrine_inject"; count = 25; };
      class _xx_kat_TXA { name = "kat_TXA"; count = 25; };
      class _xx_UNSCI_MediGel_Canister { name = "UNSCI_MediGel_Canister"; count = 100; };
      class _xx_UNSCI_Biofoam { name = "UNSCI_Biofoam"; count = 100; };
      class _xx_ACE_tourniquet { name = "ACE_tourniquet"; count = 30; };
      class _xx_ACE_splint { name = "ACE_splint"; count = 30; };
      class _xx_ACE_morphine { name = "ACE_morphine"; count = 25; };
      class _xx_ACE_adenosine { name = "ACE_adenosine"; count = 25; };
      class _xx_ACE_epinephrine { name = "ACE_epinephrine"; count = 25; };
      class _xx_ACE_salineIV { name = "ACE_salineIV"; count = 20; };
      class _xx_ACE_salineIV_500 { name = "ACE_salineIV_500"; count = 20; };
      class _xx_ACE_bodyBag { name = "ACE_bodyBag"; count = 20; };
      class _xx_ACE_plasmaIV { name = "ACE_plasmaIV"; count = 20; };
      class _xx_ACE_plasmaIV_500 { name = "ACE_plasmaIV_500"; count = 20; };
      class _xx_kat_EACA { name = "kat_EACA"; count = 25; };
      class _xx_kat_norepinephrine { name = "kat_norepinephrine"; count = 25; };
      class _xx_kat_nitroglycerin { name = "kat_nitroglycerin"; count = 25; };
      class _xx_kat_phenylephrineAuto { name = "kat_phenylephrineAuto"; count = 25; };
      class _xx_UNSCI_Injector_Stimulant { name = "UNSCI_Injector_Stimulant"; count = 25; };
      class _xx_ACE_suture { name = "ACE_suture"; count = 25; };
      class _xx_UNSCI_MediGel_40ml { name = "UNSCI_MediGel_40ml"; count = 25; };
    };
  };

  // ---------------------------------------------------------------------------
  //  Explosives Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_ex: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Explosives)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_grenades.paa"
    };
    class TransportMagazines {
      class _xx_1Rnd_HE_Grenade_shell { magazine = "1Rnd_HE_Grenade_shell"; count = 40; };
      class _xx_1Rnd_Smoke_Grenade_shell { magazine = "1Rnd_Smoke_Grenade_shell"; count = 20; };
      class _xx_1Rnd_SmokeRed_Grenade_shell { magazine = "1Rnd_SmokeRed_Grenade_shell"; count = 10; };
      class _xx_1Rnd_SmokePurple_Grenade_shell { magazine = "1Rnd_SmokePurple_Grenade_shell"; count = 10; };
      class _xx_1Rnd_SmokeBlue_Grenade_shell { magazine = "1Rnd_SmokeBlue_Grenade_shell"; count = 10; };
      class _xx_ACE_HuntIR_M203 { magazine = "ACE_HuntIR_M203"; count = 10; };
      class _xx_C7_Remote_Mag { magazine = "C7_Remote_Mag"; count = 20; };
      class _xx_C12_Remote_Mag { magazine = "C12_Remote_Mag"; count = 10; };
      class _xx_M168_Remote_Mag { magazine = "M168_Remote_Mag"; count = 5; };
      class _xx_tsp_breach_block_mag { magazine = "tsp_breach_block_mag"; count = 20; };
      class _xx_tsp_breach_linear_mag { magazine = "tsp_breach_linear_mag"; count = 20; };
      class _xx_tsp_breach_popper_mag { magazine = "tsp_breach_popper_mag"; count = 40; };
      class _xx_tsp_breach_silhouette_mag { magazine = "tsp_breach_silhouette_mag"; count = 10; };
      class _xx_tsp_breach_package_mag { magazine = "tsp_breach_package_mag"; count = 10; };
      class _xx_tsp_breach_stick_mag { magazine = "tsp_breach_stick_mag"; count = 20; };
      class _xx_DemoCharge_Remote_Mag { magazine = "DemoCharge_Remote_Mag"; count = 10; };
      class _xx_M319_HEDP_Grenade_Shell { magazine = "M319_HEDP_Grenade_Shell"; count = 20; };
    };
    class TransportWeapons {};
    class TransportItems {
      class _xx_ACE_IR_Strobe_Item { name = "ACE_IR_Strobe_Item"; count = 30; };
      class _xx_TCP_M9I_Frag { name = "TCP_M9I_Frag"; count = 20; };
      class _xx_TCP_M21_Smoke { name = "TCP_M21_Smoke"; count = 20; };
      class _xx_TCP_M21_SmokeBlue { name = "TCP_M21_SmokeBlue"; count = 10; };
      class _xx_TCP_M21_SmokeRed { name = "TCP_M21_SmokeRed"; count = 10; };
      class _xx_TCP_M21_SmokeGreen { name = "TCP_M21_SmokeGreen"; count = 10; };
      class _xx_TCP_M21_SmokePurple { name = "TCP_M21_SmokePurple"; count = 10; };
      class _xx_OPTRE_ELB47_Strobe { name = "OPTRE_ELB47_Strobe"; count = 5; };
      class _xx_ACE_M84 { name = "ACE_M84"; count = 10; };
      class _xx_ACRE_M26_Clacker { name = "ACRE_M26_Clacker"; count = 10; };
    };
  };



  // ---------------------------------------------------------------------------
  //  Mines Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_mines: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Mines)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_grenades.paa"
    };
    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {
      class _xx_UNSCMine_Range_Mag { name = "UNSCMine_Range_Mag"; count = 50; };
      class _xx_ATMine_Range_Mag { name = "ATMine_Range_Mag"; count = 50; };
      class _xx_APERSMineDispenser_Mag { name = "APERSMineDispenser_Mag"; count = 50; };
      class _xx_ACE_APERSMine_ToePopper_mag { name = "ACE_APERSMine_ToePopper_mag"; count = 50; };
      class _xx_TCP_T14_Remote_Mag { name = "TCP_T14_Remote_Mag"; count = 50; };
      class _xx_ClaymoreDirectionalMine_Remote_Mag { name = "ClaymoreDirectionalMine_Remote_Mag"; count = 50; };
      class _xx_TCP_M250_remote_Mag { name = "TCP_M250_remote_Mag"; count = 50; };
      class _xx_APERSBoundingMine_Range_Mag { name = "APERSBoundingMine_Range_Mag"; count = 50; };
      class _xx_SLAMDirectionalMine_Wire_Mag { name = "SLAMDirectionalMine_Wire_Mag"; count = 50; };
      class _xx_TCP_M725_Remote_Mag { name = "TCP_M725_Remote_Mag"; count = 50; };
    };
  };

  // ---------------------------------------------------------------------------
  //  Launcher Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_at: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Launchers)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_launcher.paa"
    };
    class TransportMagazines {
      class _xx_OPTRE_M41_Twin_HEAT_SACLOS { magazine = "OPTRE_M41_Twin_HEAT_SACLOS"; count = 4; };
      class _xx_OPTRE_M41_Twin_HEAT_SALH { magazine = "OPTRE_M41_Twin_HEAT_SALH"; count = 4; };
      //class _xx_OPTRE_M41_Twin_HEAT_Thermal { magazine = "OPTRE_M41_Twin_HEAT_Thermal"; count = 4; };
	  class _xx_MRAWS_HE_F { magazine = "MRAWS_HE_F"; count = 4; };
	  class _xx_twelfth_HEAT_95 { magazine = "twelfth_HEAT_95"; count = 4; };
	  class _xx_MRAWS_HEAT_F { magazine = "MRAWS_HEAT_F"; count = 4; };
    class _xx_OPTRE_M44_Lykoi_HEAT_mag {magazine = "OPTRE_M44_Lykoi_HEAT_mag"; count = 20;};
    class _xx_OPTRE_M44_Lykoi_HE_mag {magazine = "OPTRE_M44_Lykoi_HE_mag"; count = 10;};
    class _xx_OPTRE_M44_Lykoi_AA_mag {magazine = "OPTRE_M44_Lykoi_AA_mag"; count = 10;};
    };
    class TransportWeapons {};
    class TransportItems {};
  };

  // ---------------------------------------------------------------------------
  //  Mortar Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_mortar: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Mortars)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_mortar.paa"
    };
    class TransportMagazines {
      class _xx_avm224_M_6Rnd_60mm_HE_0_csw { magazine = "avm224_M_6Rnd_60mm_HE_0_csw"; count = 500; };
      class _xx_avm224_M_6Rnd_60mm_HE_csw { magazine = "avm224_M_6Rnd_60mm_HE_csw"; count = 600; };
      class _xx_avm224_M_6Rnd_60mm_ILLUM_IR_csw { magazine = "avm224_M_6Rnd_60mm_ILLUM_IR_csw"; count = 10; };
      class _xx_avm224_M_6Rnd_60mm_ILLUM_csw { magazine = "avm224_M_6Rnd_60mm_ILLUM_csw"; count = 50; };
      class _xx_avm224_M_6Rnd_60mm_SMOKE_csw { magazine = "avm224_M_6Rnd_60mm_SMOKE_csw"; count = 200; };
    };
    class TransportWeapons {
      class _xx_avm224_W_M224_mortar_carry { weapon = "avm224_W_M224_mortar_carry"; count = 2; };
    };
    class TransportItems {
      class _xx_ACE_artilleryTable { weapon = "ACE_artilleryTable"; count = 2; };
    };
  };

  // ---------------------------------------------------------------------------
  //  Rifle Ammo Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_rifle: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Rifle Ammo)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_rifle.paa"
    };
    class TransportMagazines {
      class _xx_OPTRE_32Rnd_762x51_Mag { magazine = "OPTRE_32Rnd_762x51_Mag"; count = 75; };
      class _xx_OPTRE_32Rnd_762x51_Mag_Tracer { magazine = "OPTRE_32Rnd_762x51_Mag_Tracer"; count = 75; };
      class _xx_OPTRE_36Rnd_95x40_Mag { magazine = "OPTRE_36Rnd_95x40_Mag"; count = 25; };
      class _xx_OPTRE_36Rnd_95x40_Mag_Tracer { magazine = "OPTRE_36Rnd_95x40_Mag_Tracer"; count = 25; };
      class _xx_OPTRE_60Rnd_5x23mm_Mag { magazine = "OPTRE_60Rnd_5x23mm_Mag"; count = 25; };
      class _xx_12Rnd_8Gauge { magazine = "12Rnd_8Gauge"; count = 25; };
      class _xx_OPTRE_4Rnd_145x114_APFSDS_Mag { magazine = "OPTRE_4Rnd_145x114_APFSDS_Mag"; count = 10; };

    };
    class TransportWeapons {};
    class TransportItems {};
  };

  // ---------------------------------------------------------------------------
  //  MG Ammo Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_mg: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (MG Ammo)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_gunner.paa"
    };
    class TransportMagazines {
      class _xx_twelfth_100Rnd_95x40_Box { magazine = "twelfth_100Rnd_95x40_Box"; count = 10; };
      class _xx_twelfth_100Rnd_95x40_Box_T { magazine = "twelfth_100Rnd_95x40_Box_T"; count = 10; };
      class _xx_twelfth_M739_SAW_200Rnd_Drum { magazine = "twelfth_M739_SAW_200Rnd_Drum"; count = 10; };
      class _xx_twelfth_M739_SAW_200Rnd_Box { magazine = "twelfth_M739_SAW_200Rnd_Box"; count = 10; };
      class _xx_OPTRE_200Rnd_762x51_M118_M247A1_Box { magazine = "OPTRE_200Rnd_762x51_M118_M247A1_Box"; count = 10; };
      class _xx_OPTRE_400Rnd_762x51_M118_M247A1_Box { magazine = "OPTRE_400Rnd_762x51_M118_M247A1_Box"; count = 5; };
      class _xx_ACE_SpareBarrel { magazine = "ACE_SpareBarrel"; count = 5; };
      class _xx_OPTRE_60Rnd_762x51_Mag { magazine = "OPTRE_60Rnd_762x51_Mag"; count = 25; };
      class _xx_twelfth_60Rnd_762x51_Mag_T { magazine = "twelfth_60Rnd_762x51_Mag_T"; count = 25; };

    };
    class TransportWeapons {};
    class TransportItems {
      class _xx_ACE_WaterBottle { name = "ACE_WaterBottle"; count = 10; };
    };
  };

  // ---------------------------------------------------------------------------
  //  Equipment Supply Pod
  // ---------------------------------------------------------------------------
  class twelfth_supply_pod_eq: twelfth_supply_pod_empty {
    displayName = "[12th] Supply Pod (Equipment)";
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_supply_pods\data\pod_co_equipment.paa"
    };
    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {
      class _xx_ToolKit { name = "ToolKit"; count = 5; };
      class _xx_ACE_DefusalKit { name = "ACE_DefusalKit"; count = 5; };
      class _xx_ACE_wirecutter { name = "ACE_wirecutter"; count = 5; };
      class _xx_ItemcTab { name = "ItemcTab"; count = 10; };
      class _xx_ItemAndroid { name = "ItemAndroid"; count = 10; };
      class _xx_ItemMicroDAGR { name = "ItemMicroDAGR"; count = 10; };
      class _xx_ACRE_PRC343 { name = "ACRE_PRC343"; count = 10; };
      class _xx_ACRE_PRC148 { name = "ACRE_PRC148"; count = 10; };
      class _xx_ACRE_PRC117F { name = "ACRE_PRC117F"; count = 2; };
      class _xx_ACRE_VHF30108SPIKE { name = "ACRE_VHF30108SPIKE"; count = 2; };
      class _xx_ACRE_VHF30108MAST { name = "ACRE_VHF30108MAST"; count = 2; };
      class _xx_Laserbatteries { name = "Laserbatteries"; count = 2; };
    };
  };

  /*
    Optional: If you define more pods (like DMR, or other specialized containers),
    replicate the pattern above, changing the textures and transport contents.
  */

  // ---------------------------------------------------------------------------
  //  Module Logic for Pelican Supply Drop
  // ---------------------------------------------------------------------------
  /*
    This section integrates your pods into the "Module_OPTRE_PelicanSupplyDrop"
    from the OPTRE or a similar mod, letting mission makers pick them in Eden.
  */
  class Logic;
  class Module_F: Logic {
    class Arguments {};
    class ModuleDescription {};
  };

  class Module_OPTRE_PelicanSupplyDrop: Module_F {
    class Arguments {
      class box1 {
        displayName = "Supply Pod 1";
        description = "Type of box required.";
        defaultValue = "rdm";
        typeName = "STRING";
        /*
          The 'values' array enumerates all possible supply pod classes 
          for the drop-down. We add references to our 12th supply pods at
          the bottom, letting you pick them in Eden's module interface.
        */
        class values {
          class n1 { name = "none"; value = "none"; };
          class n2 { name = "Random Supply Pod"; value = "rdm"; default = 1; };
          class n3 { name = "Sniper [OLD] Supply Pod"; value = "OPTRE_Ammo_SupplyPod_Sniper"; };
          class n4 { name = "Medical Supply Pod"; value = "OPTRE_Ammo_SupplyPod_Medical"; };
          class n5 { name = "MA5B Supply Pod"; value = "OPTRE_Ammo_SupplyPod_AR"; };
          class n6 { name = "LMG Supply Pod"; value = "OPTRE_Ammo_SupplyPod_LMG"; };
          class n7 { name = "SMG Supply Pod"; value = "OPTRE_Ammo_SupplyPod_SMG"; };
          class n8 { name = "Pistol Supply Pod"; value = "OPTRE_Ammo_SupplyPod_Pistol"; };
          class n9 { name = "Shotgun Supply Pod"; value = "OPTRE_Ammo_SupplyPod_Shotgun"; };
          class n10 { name = "Launcher Supply Pod"; value = "OPTRE_Ammo_SupplyPod_Launcher"; };
          class n11 { name = "DMR Supply Pod"; value = "OPTRE_Ammo_SupplyPod_DMR"; };
          class n12 { name = "BR Supply Pod"; value = "OPTRE_Ammo_SupplyPod_BR"; };
          class n13 { name = "MA5K Supply Pod"; value = "OPTRE_Ammo_SupplyPod_MA5K"; };
          class n14 { name = "SRS99C Supply Pod"; value = "OPTRE_Ammo_SupplyPod_SRS99C"; };
          class n15 { name = "MA5BAC Supply Pod"; value = "OPTRE_Ammo_SupplyPod_ARC"; };
          class n16 { name = "MA5BAC Supply Pod"; value = "OPTRE_Ammo_SupplyPod_ARC_GL"; };
          class n17 { name = "M37 Supply Pod"; value = "OPTRE_Ammo_SupplyPod_37"; };
          class n18 { name = "M37GL Supply Pod"; value = "OPTRE_Ammo_SupplyPod_37_GL"; };
          class n19 { name = "MA5BGL Supply Pod"; value = "OPTRE_Ammo_SupplyPod_AR_GL"; };
          class n20 { name = "CUSTOM Supply Pod"; value = "OPTRE_Ammo_SupplyPod_Empty"; };
          class n21 { name = "[12th] Medical Supply Pod"; value = "twelfth_supply_pod_medical"; };
          class n23 { name = "[12th] Explosives Supply Pod"; value = "twelfth_supply_pod_ex"; };
          class n25 { name = "[12th] Launcher Supply Pod"; value = "twelfth_supply_pod_at"; };
          class n26 { name = "[12th] Mortar Supply Pod"; value = "twelfth_supply_pod_mortar"; };
          class n27 { name = "[12th] Rifle Supply Pod"; value = "twelfth_supply_pod_rifle"; };
          class n28 { name = "[12th] Machine Gun Supply Pod"; value = "twelfth_supply_pod_mg"; };
          class n29 { name = "[12th] Equipment Supply Pod"; value = "twelfth_supply_pod_eq"; };
        };
      };
    };
  };
};
