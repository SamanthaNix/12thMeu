/*
  ==============================================================================
  config_weapons.hpp

  This file defines our custom weapons, including rifles, SMGs, machine guns,
  launchers, etc. Each class typically inherits from a known parent mod/class
  like OPTRE_MA5C or 19_UNSC_M6C. Then we override properties such as
  displayName, magazines[], attachments, etc.

  Key Points:
    - `scope` and `scopeArsenal` control how the weapon appears in the editor/arsenal.
    - `baseWeapon` is the "root" weapon that is recognized by the Arsenal.
    - `magazines[]` sets which magazines the weapon can use.
    - `class WeaponSlotsInfo` controls attachable items (muzzle, optics, etc.)
    - The macros from config_macros.hpp (e.g. COMMON_SIGHTS) reduce repetition.
  ==============================================================================
*/
// Predeclaring references for weapon states, attachments, etc.
  class Mode_SemiAuto;
  class Mode_Burst;
  class Mode_FullAuto;
  class WeaponSlotsInfo; // Base class for weapon slots
  class MuzzleSlot;      // Base class for muzzle attachments
  class CowsSlot;
  class PointerSlot;     // Base class for pointer attachments
  class UnderBarrelSlot; // Base class for underbarrel attachments
  class FullAuto;        // Base class for full-auto fire mode
  class Single;

class CfgWeapons
{
  // Base classes from external mods or vanilla A3
  class Launcher;        // Base class for launcher weapons
  class OPTRE_MA37K;
  class OPTRE_MA5C;
  class OPTRE_MA5CGL;
  class OPTRE_MA5K;
  class OPTRE_BR45;
  class OPTRE_Commando;
  class OPTRE_M247;
  class OPTRE_M247A1;
  class OPTRE_M247A1_Stripped;
  class OPTRE_M319;
  class OPTRE_M319N;
  class OPTRE_M301UGL; // Base class for our UGLs
  class OPTRE_M73;
  class DMNS_M96_LAW;
  class GL_3GL_F;                   // Base class for grenade launchers
  class UGL_F;
  class InventoryOpticsItem_Base_F; // Base class for optics
  class OPTRE_M6C;
  class OPTRE_M7;
  class OPTRE_M7_Folded;
  class OPTRE_M90A;
  class OPTRE_MA5B;
  class launch_MRAWS_base_F;
  class InventoryUnderItem_Base_F;
  class dzn_MG_Tripod_Universal;
  class dzn_MG_Tripod_Universal_Carry;
  class ACE_SPIR;
  class ACE_optic_Hamr_2D;
  class optic_DMS;
  class OPTRE_M739_SAW_Foregrip_Black_F;
  class OPTRE_M247a1_Flashhider;
  class EventHandlers;
  class Dmns_M33_T;
  class OPTRE_M250;
  class OPTRE_BR55HB;
  class OPTRE_BR45_black;
  class OPTRE_BR45GL_black;
  class OPTRE_M392_DMR;

  //TCP Class definitions
  //Pistols
  class TCP_hgun_Pistol_M6C2;
  class TCP_hgun_Pistol_M6G;
  class TCP_hgun_Pistol_M6G2;
  /*
    =============================================================================
    MG Tripod Definitions
    =============================================================================
  */
  class 12th_MG_Tripod_Carry: dzn_MG_Tripod_Universal_Carry{
    displayName = "[12th] MG Tripod";
    author = "10Dozen, Waylen";
    scope = 2;
    scopeArsenal = 2;
    class WeaponSlotsInfo: WeaponSlotsInfo
		{
			allowedSlots[]={};
			mass=100;
		};
		dzn_MG_Tripod_AttachItems[]=
		{
			"12th_MG_Tripod"
		};
  };

  class 12th_MG_Tripod: dzn_MG_Tripod_Universal{
    displayName = "[12th] MG Tripod";
    author = "10Dozen, Waylen";
    scope = 2;
    scopeArsenal = 2;
    class ItemInfo: InventoryUnderItem_Base_F
		{
			allowedSlots[]={};
			deployedPivot="bipod";
			hasBipod="true";
			mass=250;
			soundBipodDeploy[]=
			{
				"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",
				0.70794576,
				1,
				20
			};
			soundBipodFold[]=
			{
				"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",
				0.70794576,
				1,
				20
			};
			soundBipodDown[]=
			{
				"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",
				0.70794576,
				1,
				20
			};
			soundBipodUp[]=
			{
				"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",
				0.70794576,
				1,
				20
			};
		};
    inertia=2;
		dzn_MG_Tripod_CarryItem="12th_MG_Tripod_Carry";
		dzn_MG_Tripod_CarryItemUniversal="12th_MG_Tripod_Carry";
  };
  /*
    =============================================================================
    M96 LAW (Disposable Launcher) Definition
    =============================================================================
    We define multiple states: normal backpack state, ready-to-fire, and used.
  */
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };

    class twelfth_m96: Launcher_Base_F { // launcher when on back
      author = "DemonicOnPC; Waylen";
      scope = 2;
      scopeArsenal = 2;
      baseWeapon = "twelfth_m96";
      displayName = "[12th] M96 LAW - Mk VI"; // usual displayName
      //displayName = "[12th] M96 LAW - Mk VI (B)"; // debug displayname

      magazines[] = { "CBA_FakeLauncherMagazine" }; // When stowed/backpacked, it does not carry a real rocket.

      model = "\Foundries\Weapons\Launchers\DMNS_M96_LAW_loaded.p3d";
      picture = "\Foundries\Weapons\Launchers\Data\Law_Icon.paa";
      UiPicture = "\Foundries\Weapons\Launchers\Data\Law_Icon.paa";
      handAnim[] = {
          "OFP2_ManSkeleton",
          "\A3\Weapons_F_Exp\Launchers\RPG7\Data\Anim\RPG7V.rtm"
      };
      hiddenSelections[] = { "camo1", "camo2" };
      hiddenSelectionsTextures[] = {
          "\Foundries\Weapons\Launchers\Data\M96_Tube_co.paa",
          "\Foundries\Weapons\Launchers\Data\M96_body_co.paa"
      };

      reloadAction = "GestureReloadRPG7";
      recoil = "recoil_nlaw";
      maxZeroing = 500;
      shotPos = "muzzlePos2";
      shotEnd = "muzzleEnd2";
      modes[] = { "Single" };

      class Single: Mode_SemiAuto {
        sounds[] = { "StandardSound" };

        class BaseSoundModeType {};
        class StandardSound: BaseSoundModeType {
            begin1[] = { "\A3\Sounds_F\arsenal\weapons\Launchers\NLAW\nlaw", 1.99526, 1, 1800 };
            soundBegin[] = { "begin1", 1 };
        };

        reloadSpeed = 10;
        recoil = "recoil_single_nlaw";
        aiRateOfFire = 7;
        aiRateOfFireDistance = 500;
        minRange = 25;
        minRangeProbab = 0.8;
        midRange = 50;
        midRangeProbab = 0.8;
        maxRange = 790;
        maxRangeProbab = 0.8;
      };

      class GunParticles {
          class effect1 {
              positionName = "muzzleEnd2";
              directionName = "muzzlePos2";
              effectName = "RocketBackEffectsNLAWNT";
          };
      };

      drySound[] = { "\A3\Sounds_F\arsenal\weapons\Launchers\NLAW\Dry_NLAW", 0.177828, 1, 15 };
      changeFiremodeSound[] = { "\A3\sounds_f\dummysound", 0.562341, 1, 20 };
      modelOptics = "-";

      class OpticsModes {
        class irons {
          opticsID = 1;
          useModelOptics = 0;
          opticsPPEffects[] = {};
          opticsZoomMin = 0.375;
          opticsZoomMax = 1.25;
          opticsZoomInit = 0.75;
          visionMode[] = {};
          opticsFlare = 0;
          opticsDisablePeripherialVision = 0;
          distanceZoomMin = 300;
          distanceZoomMax = 300;
          cameraDir = "look";
          discreteDistance[] = { 300 };
          discreteDistanceInitIndex = 0;
          discreteDistanceCameraPoint[] = { "eye_300" };
        };
      };

      canLock = 0;
      ballisticsComputer = 0;
      inertia = 1;
      aimTransitionSpeed = 0.5;
      dexterity = 1;

      class WeaponSlotsInfo: WeaponSlotsInfo {
          class CowsSlot: CowsSlot {
            linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
            displayName = "$STR_A3_CowsSlot0";
            compatibleItems[] = COMMON_SIGHTS;
            iconPosition[] = { 0.5, 0.3 };
          };
          mass = 125; // launcher + rocket (100 + 45)
      };

      class ItemInfo {
          priority = 3;
      };
      descriptionShort = "A 66mm single-use RPG, effective against medium armor";
    };
  // Ready state: actual loaded launcher in hands
    class twelfth_m96_READY: twelfth_m96{
        displayName = "[12th] M96 LAW - Mk VI";
        //displayName = "[12th] M96 LAW - Mk VI (R)"; // debug displayName
        scope = 1;
        scopeArsenal = 1;
        baseWeapon = "twelfth_m96";
        magazines[] = { "twelfth_m96_magazine" };
        magazineReloadTime = 0.1;
        reloadMagazineSound[] = {"",1,1};

        class EventHandlers {
          fired = "_this call CBA_fnc_firedDisposable";
        };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 125; // launcher mass + rocket (100 + 45)
        };
    };

    class twelfth_m96_USED: twelfth_m96{ // fired launcher
        displayName = "[12th] M96 LAW - Mk VI (Used)";
        scope = 1;
        scopeArsenal = 1;
        baseWeapon = "twelfth_m96_USED";

        magazines[] = { "CBA_FakeLauncherMagazine" };
        weaponPoolAvailable = 0;

        model = "\Foundries\Weapons\Launchers\DMNS_M96_LAW_Used.p3d";

        class WeaponSlotsInfo: WeaponSlotsInfo{
            mass = 80; // launcher mass (100)
        };
    };
  /*
    =============================================================================
    MAAWS Config
    =============================================================================
  */

    // ACE buddy loading compat

	  class Weapon_launch_MRAWS_green_F
	  {
	  	ace_reloadlaunchers_enabled=1;
	  };
	  class Weapon_launch_MRAWS_olive_F
	  {
	  	ace_reloadlaunchers_enabled=1;
	  };
	  class Weapon_launch_MRAWS_sand_F
	  {
	  	ace_reloadlaunchers_enabled=1;
	  };

    // class definitions

    class twelfth_MAAWS_base: launch_MRAWS_base_F
    {
	    author = "Waylen";
	    displayName = "[12th] MAAWS (Green)";
	    baseWeapon = "twelfth_MAAWS_base";
	    scope = 2;
	    hiddenSelectionsTextures[] =
      {
        "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_darkgreen_01_F_co",
        "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_02_F_co"
      };

      class WeaponSlotsInfo: WeaponSlotsInfo
      {
        mass = 65;
      };
    };

    class twelfth_MAAWS_olive: twelfth_MAAWS_base {
	    author = "Waylen";
	    displayName = "[12th] MAAWS (Olive)";
	    baseWeapon = "twelfth_MAAWS_olive";
	    scope = 2;
	    hiddenSelectionsTextures[] =
      {
			  "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_olive_01_F_co",
			  "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_02_F_co"
      };
    };

    class twelfth_MAAWS_sand: twelfth_MAAWS_base {
	    author = "Waylen";
	    displayName = "[12th] MAAWS (Sand)";
	    baseWeapon = "twelfth_MAAWS_sand";
	    scope = 2;
	    hiddenSelectionsTextures[] =
      {
			  "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_sand_01_F_co",
			  "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_02_F_co"
      };
    };

  /*
    =============================================================================
    Sidearms, SMGs, Shotguns, and other small arms
    =============================================================================
  */
  // **ANY COMMON_MACRO_NAME CAN BE FOUND IN macros.hpp**


    class twelfth_M6C2 : TCP_hgun_Pistol_M6C2
  {
    scope = 2;
    scopeArsenal = 2;
    author = "Sammy";
    displayName = "[12th] M6C2";
    baseWeapon = "twelfth_M6C2";
    //magazines[] = COMMON_M6_MAGAZINES;
  };  
  class twelfth_M6G : TCP_hgun_Pistol_M6G
  {
    scope = 2;
    scopeArsenal = 2;
    author = "Sammy";
    displayName = "[12th] M6G";
    baseWeapon = "twelfth_M6G";
    //magazines[] = COMMON_M6_MAGAZINES;
  };
  class twelfth_M6G2 : TCP_hgun_Pistol_M6G2
  {
    scope = 2;
    scopeArsenal = 2;
    author = "Sammy";
    displayName = "[12th] M6G2";
    baseWeapon = "twelfth_M6G2";
    //magazines[] = COMMON_M6_MAGAZINES;
  };
  class twelfth_M6C : OPTRE_M6C
  {
    scope = 2;
    scopeArsenal = 2;
    author = "Weber";
    displayName = "[12th] M6C";
    baseWeapon = "twelfth_M6C";
    magazines[] = COMMON_M6_MAGAZINES;
  };

  class twelfth_M7_Test : OPTRE_M7
  {
    model = "\TCP\Weapons\SMGs\M7\M7.p3d";
    author = "Weber";
    scope = 2;
    scopeArsenal = 2;
    displayName = "[12th] M7";
    baseWeapon = "twelfth_M7_Test";
    picture = "\TCP\Weapons\SMGs\M7\data\ui\icon_SMG_M7_X_ca.paa";
		pictureWire = "\TCP\Weapons\SMGs\M7\data\ui\icon_SMG_M7_W_ca.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\TCP\Weapons\SMGs\M7\data\camo\default\M7_CO.paa"};
    handAnim[] = {"OFP2_ManSkeleton","\TCP\Weapons\SMGs\M7\data\anim\M7_handAnim.rtm"};
    magazines[] = COMMON_SMG_MAGAZINES;
    class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
			};
			class CowsSlot: CowsSlot {

      };
			class PointerSlot: PointerSlot {
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS,"TCP_acc_pointer_lam_M7"};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				compatibleitems[] = {};
			};
		};
  };

  class twelfth_M7_Test_Folded : OPTRE_M7_Folded
  {
    author = "Weber";
    scope = 2;
    scopeArsenal = 2;
    displayName = "[12th] M7 Folded";
    baseWeapon = "twelfth_M7_Test_Folded";
    magazines[] = {};
  };

  class twelfth_M90 : OPTRE_M90A
  {
    model = "\TCP\Weapons\Shotguns\M45\M45.p3d";
    author = "Weber";
    scope = 2;
    scopeArsenal = 2;
    displayName = "[12th] M45";
    baseWeapon = "twelfth_M90";
    picture = "\TCP\Weapons\Shotguns\M45\data\ui\icon_srifle_M45_X_ca.paa";
		pictureWire = "\TCP\Weapons\Shotguns\M45\data\ui\icon_srifle_M45_W_ca.paa";
		hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"\TCP\Weapons\Shotguns\M45\data\camo\default\M45_01_CO.paa","\TCP\Weapons\Shotguns\M45\data\camo\default\M45_02_CO.paa"};
    magazines[] = {"twelfth_12rnd_8ga_b", "twelfth_12rnd_8ga_s", "twelfth_6rnd_8ga_b", "twelfth_6rnd_8ga_s"};
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class PointerSlot: PointerSlot {
				compatibleitems[] = {"TCP_acc_flashlight_M45"};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				compatibleitems[] = {"TCP_bipod_sideSaddle_M45_Mixed","TCP_bipod_sideSaddle_M45_Pellets","TCP_bipod_sideSaddle_M45_Slugs"};
			};
      class MuzzleSlot: MuzzleSlot {
        compatibleitems[] = {};
			};
		};
  };
  /*
    =============================================================================
    Assault Rifles
    =============================================================================
  */

	class twelfth_MA5C: OPTRE_MA5C {
	author = "Waylen";
	scope = 2;
	scopeArsenal = 2;
	displayName = "[12th] MA5C Assault Rifle";
	baseWeapon = "twelfth_MA5C";
	canShootInWater = 1;
	magazines[] = COMMON_MA5C_MAGAZINES;

		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
        compatibleitems[] = COMMON_SIGHTS;
      };
			class PointerSlot: PointerSlot {
        compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				compatibleitems[] = {};
			};
		};
	};

	class twelfth_MA5CGL: OPTRE_MA5CGL {
		author = "Waylen";
		scope = 2;
		scopeArsenal = 2;
		canShootInWater = 1;
		displayName = "[12th] MA5CGL Assault Rifle";
		muzzles[] = { "this", "twelfth_M301UGL" };
		class twelfth_M301UGL: OPTRE_M301UGL {
			displayName = "M301 Grenade Launcher";
			descriptionShort = "M301 GL";
			magazines[] = COMMON_GL_MAGS;
		};
		baseWeapon = "twelfth_MA5CGL";
		magazines[] = COMMON_MA5C_MAGAZINES;

		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
			compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
      compatibleitems[] = COMMON_SIGHTS;
      };
			class PointerSlot: PointerSlot {
			compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
			compatibleitems[] = {};
			};
		};
	};

  class twelfth_MA37K: OPTRE_MA37K {
    author = "Waylen";
    scope = 2;
    scopeArsenal = 2;
    canShootInWater = 1;
    mass = 30;
    displayName = "[12th] MA37K Carbine";
    baseWeapon = "twelfth_MA37K";
    magazines[] = COMMON_MA5C_MAGAZINES;
    class WeaponSlotsInfo: WeaponSlotsInfo {
      mass = 30;
      class MuzzleSlot: MuzzleSlot {
          compatibleitems[] = { "OPTRE_MA37KSuppressor" };
      };
      class CowsSlot: CowsSlot {
        compatibleitems[] = COMMON_SIGHTS;
      };
      class PointerSlot: PointerSlot {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
      };
      class UnderBarrelSlot: UnderBarrelSlot {
          compatibleitems[] = {};
      };
    };
  };

    class twelfth_MA5K: OPTRE_MA5K {
    author = "Waylen";
    scope = 2;
    scopeArsenal = 2;
    canShootInWater = 1;
    mass = 30;
    handAnim[] = {"OFP2_ManSkeleton","\TCP\Weapons\Rifles\MA5K\data\anim\MA5K_handAnim.rtm"};
    displayName = "[12th] MA5K Carbine";
    baseWeapon = "twelfth_MA5K";
    model = "\TCP\Weapons\Rifles\MA5K\MA5K.p3d";
		picture = "\TCP\Weapons\Rifles\MA5K\data\ui\icon_arifle_MA5K_X_ca.paa";
		pictureWire = "\TCP\Weapons\Rifles\MA5K\data\ui\icon_arifle_MA5K_W_ca.paa";
    hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"TCP\Weapons\Rifles\MA5B\data\camo\default\MA5_CO.paa","\TCP\Weapons\Rifles\MA5K\data\camo\default\MA5K_CO.paa"};
    magazines[] = COMMON_MA5C_MAGAZINES;
    class WeaponSlotsInfo: WeaponSlotsInfo {
      mass = 30;
      class MuzzleSlot: MuzzleSlot {
          compatibleitems[] = { "OPTRE_MA5Suppressor" };
      };
      class CowsSlot: CowsSlot {
        compatibleitems[] = COMMON_SIGHTS;
        };
      class PointerSlot: PointerSlot {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
      };
      class UnderBarrelSlot: UnderBarrelSlot {
          compatibleitems[] = {};
      };
    };
  };

 // Training MA5A configuration

    class twelfth_MA5C_BB : OPTRE_MA5C
  {
    author = "Weber";
    scope = 2;
    scopeArsenal = 2;
    canShootInWater = 1;
    displayName = "[12th] Training MA5C";
    baseWeapon = "twelfth_MA5C_BB";
    magazines[] = {"twelfth_20g_mag"}; // Training ammunition magazine
  };

  class twelfth_MA5B : OPTRE_MA5B
  {
    author = "Weber";
    scope = 2;
    scopeArsenal = 2;
    canShootInWater = 1;
    displayName = "[12th] MA5B";
    baseWeapon = "twelfth_MA5B";
    magazines[] = {"OPTRE_60Rnd_762x51_Mag","twelfth_60Rnd_762x51_Mag_T", "OPTRE_32Rnd_762x51_Mag", "OPTRE_32Rnd_762x51_Mag_Tracer","OPTRE_32Rnd_762x51_Mag_UW"};
    modes[] = {"FullAuto", "Single"};
    class manual: Single {
      displayName = "Semi-Auto";
      burst = 1;
      
    };
  };
  /*
    =============================================================================
    BR and DMR
    =============================================================================
  */

    class twelfth_br55 : OPTRE_BR45_black
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      canShootInWater = 1;
      displayName = "[12th] BR45";
      baseWeapon = "twelfth_BR55";
      magazines[] = COMMON_BR_MAGAZINES;
      ace_overheating_barrelMass = 10;
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
        };
        class CowsSlot : CowsSlot
        {
          compatibleitems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
        };
      };
    };

    // Additional BR55 variants with grenade launchers

    class twelfth_br55_gl : OPTRE_BR45GL_black
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      canShootInWater = 1;
      displayName = "[12th] BR45 UGL";
      baseWeapon = "twelfth_BR55_gl";
      magazines[] = COMMON_BR_MAGAZINES;
      ace_overheating_barrelMass = 10;
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
        };
        class CowsSlot : CowsSlot
        {
          compatibleitems[] = COMMON_BR_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
        };
      };
    };

    class twelfth_BR55_HB : OPTRE_BR55HB
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      canShootInWater = 1;
      displayName = "[12th] BR55HB";
      baseWeapon = "twelfth_BR55_HB";
      magazines[] = COMMON_BR_MAGAZINES;
      ace_overheating_barrelMass = 10;
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
        };
        class CowsSlot : CowsSlot
        {
          compatibleitems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = {};
        };
      };
      class Single: Mode_SemiAuto
	    {
		    sounds[]=
		    {
		    	"StandardSound",
		    	"SilencedSound"
		    };
		    class BaseSoundModeType
		    {
		    	weaponSoundEffect="DefaultRifle";
		    	closure1[]={};
		    	closure2[]={};
		    	soundClosure[]=
		    	{
		    		"closure1",
		    		0.5,
		    		"closure2",
		    		0.5
		    	};
		    };
		    class StandardSound: BaseSoundModeType
		    {
		    	begin1[]=
		    	{
		    		"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_1.wss",
		    		1.2,
		    		1,
		    		2000
		    	};
		    	begin2[]=
		    	{
		    		"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_2.wss",
		    		1.2,
		    		1,
		    		2000
		    	};
		    	begin3[]=
		    	{
		    		"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_3.wss",
		    		1.2,
		    		1,
		    		2000
		    	};
		    begin4[]=
		    {
		    	"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_4.wss",
		    	1.2,
		    	1,
		    	2000
		    };
		    	soundBegin[]=
		    	{
		    		"begin1",
		    		0.1,
		    		"begin2",
		    		0.1,
		    		"begin3",
		    		0.1,
		    		"begin4",
		    		0.1
		    	};
		    	class SoundTails
		    	{
		    		class TailInterior
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_interior",
		    				2.2387211,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="interior";
		    		};
		    		class TailTrees
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_trees",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*trees";
		    		};
		    		class TailForest
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_forest",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*forest";
		    		};
		    		class TailMeadows
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_meadows",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*(meadows/2 max sea/2)";
		    		};
		    		class TailHouses
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_houses",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*houses";
		    		};
		    	};
		    };
		    class SilencedSound: BaseSoundModeType
		    {
		    	begin1[]=
		    	{
		    		"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_01",
		    		0.79432821,
		    		1,
		    		400
		    	};
		    	begin2[]=
		    	{
		    		"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_02",
		    		0.79432821,
		    		1,
		    		400
		    	};
		    	begin3[]=
		    	{
		    		"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_03",
		    		0.79432821,
		    		1,
		    		400
		    	};
		    	soundBegin[]=
		    	{
		    		"begin1",
		    		0.33000001,
		    		"begin2",
		    		0.33000001,
		    		"begin1",
		    		0.34
		    	};
		    	class SoundTails
		    	{
		    		class TailInterior
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_tail_interior",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="interior";
		    		};
		    		class TailTrees
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_trees",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*trees";
		    		};
		    		class TailForest
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_forest",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*forest";
		    		};
		    		class TailMeadows
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_meadows",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*(meadows/2 max sea/2)";
		    		};
		    		class TailHouses
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_houses",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*houses";
		    		};
		    	};
		    };
		    reloadTime=0.1;
		    recoil="recoil_single_mx";
		    recoilProne="recoil_single_prone_mx";
		    dispersion=0.00005;
		    minRange=0;
		    minRangeProbab=0.80000001;
		    midRange=500;
		    midRangeProbab=0.89999998;
		    maxRange=1000;
		    maxRangeProbab=0.60000002;
		    aiRateOfFire=2;
		    aiRateOfFireDistance=20;
	    };
	    class Burst: Mode_Burst
	    {
		    sounds[]=
		    {
		    	"StandardSound",
		    	"SilencedSound"
		    };
		    class BaseSoundModeType
		    {
		    	weaponSoundEffect="DefaultRifle";
		    	closure1[]={};
		    	closure2[]={};
		    	soundClosure[]=
		    	{
		    		"closure1",
		    		0.5,
		    		"closure2",
		    		0.5
		    	};
		    };
		    class StandardSound: BaseSoundModeType
		    {
		    	begin1[]=
		    	{
		    		"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_1.wss",
		    		1.2,
		    		1,
		    		2000
		    	};
		    	begin2[]=
		    	{
		    		"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_2.wss",
		    		1.2,
		    		1,
		    		2000
		    	};
		    	begin3[]=
		    	{
		    		"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_3.wss",
		    		1.2,
		    		1,
		    		2000
		    	};
		    begin4[]=
		    {
		    	"\UNSC_F_Weapons\weapons\data\Sounds\UNSC_br55_4.wss",
		    	1.2,
		    	1,
		    	2000
		    };
		    	soundBegin[]=
		    	{
		    		"begin1",
		    		0.1,
		    		"begin2",
		    		0.1,
		    		"begin3",
		    		0.1,
		    		"begin4",
		    		0.1
		    	};
		    	class SoundTails
		    	{
		    		class TailInterior
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_interior",
		    				2.2387211,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="interior";
		    		};
		    		class TailTrees
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_trees",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*trees";
		    		};
		    		class TailForest
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_forest",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*forest";
		    		};
		    		class TailMeadows
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_meadows",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*(meadows/2 max sea/2)";
		    		};
		    		class TailHouses
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_houses",
		    				1,
		    				1,
		    				1800
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*houses";
		    		};
		    	};
		    };
		    class SilencedSound: BaseSoundModeType
		    {
		    	begin1[]=
		    	{
		    		"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_01",
		    		0.79432821,
		    		1,
		    		400
		    	};
		    	begin2[]=
		    	{
		    		"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_02",
		    		0.79432821,
		    		1,
		    		400
		    	};
		    	begin3[]=
		    	{
		    		"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_03",
		    		0.79432821,
		    		1,
		    		400
		    	};
		    	soundBegin[]=
		    	{
		    		"begin1",
		    		0.33000001,
		    		"begin2",
		    		0.33000001,
		    		"begin1",
		    		0.34
		    	};
		    	class SoundTails
		    	{
		    		class TailInterior
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_tail_interior",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="interior";
		    		};
		    		class TailTrees
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_trees",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*trees";
		    		};
		    		class TailForest
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_forest",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*forest";
		    		};
		    		class TailMeadows
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_meadows",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*(meadows/2 max sea/2)";
		    		};
		    		class TailHouses
		    		{
		    			sound[]=
		    			{
		    				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_houses",
		    				1,
		    				1,
		    				400
		    			};
		    			frequency=1;
		    			volume="(1-interior/1.4)*houses";
		    		};
		    	};
		    };
		    soundBurst=0;
		    burst=3;
		    reloadTime=0.08;
		    recoil="recoil_auto_mx";
		    recoilProne="recoil_auto_prone_mx";
		    dispersion=0.00005;
		    minRange=1;
		    minRangeProbab=0.80000001;
		    midRange=500;
		    midRangeProbab=0.89999998;
		    maxRange=1000;
		    maxRangeProbab=0.60000002;
		    aiRateOfFire=1;
		    aiRateOfFireDistance=10;
	    };
    };

    // commented out cus marksmen DO NOT need a GL lmfao
    //class twelfth_BR55_HB_gl : 19_UNSC_br55_HB_gl
    //{
    //  author = "Weber";
    //  scope = 2;
    //  scopeArsenal = 2;
    //  canShootInWater = 1;
    //  displayName = "[12th] BR55HB UGL";
    //  muzzles[] = {"this", "twelfth_M301UGL"}; // Attachments
    //  class twelfth_m301ugl : GL_3GL_F
    //  {
    //    displayName = "M301 Grenade Launcher";
    //    descriptionShort = "M301 GL";
    //    magazines[] = COMMON_GL_MAGS; // Grenade launcher mags
    //  };
    //  baseWeapon = "twelfth_BR55_HB_gl";
    //  magazines[] = COMMON_BR_MAGAZINES;
    //  class WeaponSlotsInfo : WeaponSlotsInfo
    //  {
    //    class MuzzleSlot : MuzzleSlot
    //    {
    //    };
    //    class CowsSlot : CowsSlot
    //    {
    //      compatibleitems[] = COMMON_BR_SIGHTS;
    //    };
    //    class PointerSlot : PointerSlot
    //    {
    //    };
    //    class UnderBarrelSlot : UnderBarrelSlot
    //    {
    //    };
    //  };
    //};
  /*
    =============================================================================
    Machine Guns
    =============================================================================
  */

    class twelfth_M392 : OPTRE_M392_DMR
    {
      model = "\TCP\Weapons\LongRangeRifles\M392\M392.p3d";
      author = "Rex";
      scope = 2;
      scopeArsenal = 2;
      canShootInWater = 1;
      displayName = "[12th] M392 DMR";
      baseWeapon = "twelfth_M392";
      picture = "\TCP\Weapons\LongRangeRifles\M392\data\ui\icon_srifle_M392_X_ca.paa";
		  pictureWire = "\TCP\Weapons\LongRangeRifles\M392\data\ui\icon_srifle_M392_W_ca.paa";
      hiddenSelections[] = {"camo","camo1"};
		  hiddenSelectionsTextures[] = {"\TCP\Weapons\LongRangeRifles\M392\data\camo\default\M392_01_CO.paa","\TCP\Weapons\LongRangeRifles\M392\data\camo\default\M392_02_CO.paa"};
      handAnim[] = {"OFP2_ManSkeleton","\TCP\Weapons\LongRangeRifles\M392\data\anim\M392_handAnim.rtm"};
      HUD_TotalPosibleBullet = 32; // Total possible bullets displayed in HUD
      magazines[] = COMMON_MA5C_MAGAZINES;
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_MEDIUM_BIPOD;
        };
      };
    };

	class twelfth_M739B: OPTRE_M739_SAW_Foregrip_Black_F
	{
	  author = "Sammy";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M739B SAW";
      baseWeapon = "twelfth_M739B";
	magazines[] = {"twelfth_M739_SAW_200rnd_Box", "twelfth_M739_SAW_200rnd_Drum", "OPTRE_32Rnd_762x51_Mag_UW", "OPTRE_60Rnd_762x51_Mag", "twelfth_60Rnd_762x51_Mag_T"};
	  class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {"OPTRE_M7_silencer"};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_MEDIUM_BIPOD;
        };
      };
	};

    // VK78 Commando configuration
    
    class twelfth_Commando : OPTRE_Commando
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] VK78 Commando";
      baseWeapon = "twelfth_Commando";
      hiddenSelections[] = {"camo1", "camo2"};
      /*hiddenSelectionsTextures[] = {
          "\x\12thMEU\addons\12th_weapons\data\Commando\Commando_co.paa",
          "\x\12thMEU\addons\12th_weapons\data\Commando\Commando2_co.paa"};*/ // Commented out until texture is made.
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {"OPTRE_M7_silencer"};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_LIGHT_BIPOD;
        };
      };
    };

    // M33-T Machine Gun configuration

    class twelfth_M33_T: Dmns_M33_T {
        author = "Jack, Waylen";
        displayName = "[12th] M33-T";
        baseWeapon = "twelfth_M33_T";
        magazines[] = COMMON_LMG_MAGAZINES;
        modes[] = { "FullAuto", "FullAutoFast" };
	      distanceZoomMin=100;
	      distanceZoomMax=700;
        maxZeroing=700;

        // Tripod compat
        DEPLOYED_GESTURE_GPMG;
        RELOAD_EH;

        ace_overheating_mrbs = 5500;
        ace_overheating_slowdownFactor = 1;
        ace_overheating_allowSwapBarrel = 1;
        ace_overheating_dispersion = 0.25;
        ace_overheating_jamTypesAllowed[] = {"Feed", "Fire", "Eject", "Extract"};
        ace_overheating_closedbolt = 1;
        ace_overheating_barrelMass = 3.5;

        class FullAuto: FullAuto {
            dispersion = 0.00116;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-06;
            reloadTime = 0.15;

            class BaseSoundModType {};
            class standardsound: BaseSoundModType {
                soundsetshot[] = {
                    "MMG01_Shot_SoundSet", "MMG01_Tail_SoundSet",
                    "MMG01_InteriorTail_SoundSet"
                };
            };
        };
      class FullAutoFast : FullAuto
      {
        reloadTime = 0.08; // 800 RPM
        textureType = "fastAuto";
        class BaseSoundModType
        {
        };
        class standardsound : BaseSoundModType
        {
          soundsetshot[] = {
              "MMG01_Shot_SoundSet", "MMG01_Tail_SoundSet",
              "MMG01_InteriorTail_SoundSet"
          };
        };
      };

        class WeaponSlotsInfo: WeaponSlotsInfo {
          class MuzzleSlot : MuzzleSlot
          {
            compatibleitems[] = {"OPTRE_MA5Suppressor"};
          };
          class CowsSlot : CowsSlot
          {
            compatibleItems[] = COMMON_SIGHTS;
          };
          class PointerSlot : PointerSlot
          {
            compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
          };
          class UnderBarrelSlot : UnderBarrelSlot
          {
            compatibleitems[] = COMMON_HEAVY_BIPOD;
          };
        };
    };

    class twelfth_M73H : OPTRE_M73
    {
      author = "Jack"; // Thank you!
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M73H";
      baseWeapon = "twelfth_M73H";
      magazines[] = {
          "twelfth_100Rnd_95x40_Box", "twelfth_100Rnd_95x40_Box_T",
          "OPTRE_36Rnd_95x40_Mag", "OPTRE_36Rnd_95x40_Mag_Tracer","twelfth_56Rnd_95x40_Mag","twelfth_56Rnd_95x40_Mag_T","twelfth_br_36Rnd_UW"
          };
	    distanceZoomMin=100;
	    distanceZoomMax=700;
      maxZeroing=700;




      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {"OPTRE_MA5Suppressor"};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_HEAVY_BIPOD;
        };
      };
    };

    class twelfth_M731 : OPTRE_M73
    {
      model = "\TCP\Weapons\Machineguns\M731\M731.p3d";
      author = "Rex"; 
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M731";
      baseWeapon = "twelfth_M731";
      handAnim[] = {"OFP2_ManSkeleton","\TCP\Weapons\Machineguns\M731\data\anim\M731_handAnim.rtm"};
      picture = "\TCP\Weapons\Machineguns\M731\data\ui\icon_lmg_M731_X_ca.paa";
		  pictureWire = "\TCP\Weapons\Machineguns\M731\data\ui\icon_lmg_M731_W_ca.paa";
      hiddenSelections[] = {"camo","camo1","camo2"};
		  hiddenSelectionsTextures[] = {"\TCP\Weapons\Machineguns\M731\data\camo\black\M731_01_CO.paa","\TCP\Weapons\Machineguns\M731\data\camo\black\M731_02_CO.paa","\TCP\Weapons\Machineguns\M731\data\camo\black\M731_03_CO.paa"};
      magazines[] = {"OPTRE_32Rnd_762x51_Mag", "OPTRE_32Rnd_762x51_Mag_Tracer", "OPTRE_32Rnd_762x51_Mag_UW", "twelfth_100Rnd_762x51_Box_T", "twelfth_200Rnd_762x51_Box_T", "twelfth_60Rnd_762x51_Mag_T", "OPTRE_60Rnd_762x51_Mag"};
	    distanceZoomMin=100;
	    distanceZoomMax=700;
      maxZeroing=700;




      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS,"TCP_acc_carryHandle_M731"};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_HEAVY_BIPOD;
        };
      };
    };

    // M247 GPMG configuration

    class twelfth_M247 : OPTRE_M247
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M247 GPMG";
      baseWeapon = "twelfth_M247";
      DEPLOYED_GESTURE_GPMG;
      RELOAD_EH;
      magazines[] = COMMON_LMG_MAGAZINES;
      modes[] = {"FullAuto", "FullAutoFast"};
      class FullAuto : FullAuto
      {
        dispersion = 0.00116;
        minRange = 0;
        minRangeProbab = 0.9;
        midRange = 15;
        midRangeProbab = 0.7;
        maxRange = 30;
        maxRangeProbab = 0.1;
        aiRateOfFire = 1e-06;
        reloadTime = 0.09;
      };
      class FullAutoFast : FullAuto
      {
        reloadTime = 0.07;
        textureType = "fastAuto";
      };
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {"OPTRE_MA5Suppressor"};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_HEAVY_BIPOD;
        };
      };
    };
	class twelfth_M247A1 : OPTRE_M247A1
    {
      author = "Sammy";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M247A1 GPMG";
      baseWeapon = "twelfth_M247A1";
      DEPLOYED_GESTURE_GPMG;
      RELOAD_EH;
      modes[] = {"FullAuto", "FullAutoFast"};
      class FullAuto : FullAuto
      {
        dispersion = 0.00116;
        minRange = 0;
        minRangeProbab = 0.9;
        midRange = 15;
        midRangeProbab = 0.7;
        maxRange = 30;
        maxRangeProbab = 0.1;
        aiRateOfFire = 1e-06;
        reloadTime = 0.09;
      };
      class FullAutoFast : FullAuto
      {
        reloadTime = 0.07;
        textureType = "fastAuto";
      };
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {"OPTRE_MA5Suppressor", "OPTRE_M247a1_Flashhider"};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_HEAVY_BIPOD;
        };
      };
    };
	class twelfth_M247A1_Stripped : OPTRE_M247A1_Stripped
    {
      author = "Sammy";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M247A1-L GPMG";
      baseWeapon = "twelfth_M247A1_Stripped";
      DEPLOYED_GESTURE_GPMG;
      RELOAD_EH;
      modes[] = {"FullAuto", "FullAutoFast"};
      class FullAuto : FullAuto
      {
        dispersion = 0.00116;
        minRange = 0;
        minRangeProbab = 0.9;
        midRange = 15;
        midRangeProbab = 0.7;
        maxRange = 30;
        maxRangeProbab = 0.1;
        aiRateOfFire = 1e-06;
        reloadTime = 0.09;
      };
      class FullAutoFast : FullAuto
      {
        reloadTime = 0.07;
        textureType = "fastAuto";
      };
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {"OPTRE_MA5Suppressor", "OPTRE_M247a1_Flashhider"};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_HEAVY_BIPOD;
        };
      };
    };

    class twelfth_M250 : OPTRE_M250 
    {
      author = "Rex";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M250";
      baseWeapon = "twelfth_M250";
     
      class WeaponSlotsInfo : WeaponSlotsInfo
      {
        class MuzzleSlot : MuzzleSlot
        {
          compatibleitems[] = {};
        };
        class CowsSlot : CowsSlot
        {
          compatibleItems[] = COMMON_SIGHTS;
        };
        class PointerSlot : PointerSlot
        {
          compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
        };
        class UnderBarrelSlot : UnderBarrelSlot
        {
          compatibleitems[] = COMMON_HEAVY_BIPOD;
        };
      };
    };

  /*
    =============================================================================
    Grenade Launchers
    =============================================================================
  */

    class twelfth_M319 : OPTRE_M319
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M319 Individual Grenade Launcher";
      baseWeapon = "twelfth_M319";
      magazines[] = COMMON_GL_MAGS;
    };

    class twelfth_M319N : OPTRE_M319N
    {
      author = "Weber";
      scope = 2;
      scopeArsenal = 2;
      displayName = "[12th] M319N Individual Grenade Launcher";
      baseWeapon = "twelfth_M319N";
      magazines[] = COMMON_GL_MAGS;
    };
  /*
    =============================================================================
    MA6 Variants
    =============================================================================
  */
	//Base MA6
	class twelfth_MA6: twelfth_MA5C {
		model="x\12thMEU\addons\12th_weapons\data\MA6\MA6.p3d";
		author = "Sammy";
		scope = 2;
		scopeArsenal = 2;
		displayName = "[12th] MA6 Assault Rifle";
		baseWeapon = "twelfth_MA6";
		canShootInWater = 1;
		magazines[] = COMMON_MA5C_MAGAZINES;
		handAnim[] = {"OFP2_ManSkeleton","x\12thMEU\addons\12th_weapons\data\MA6\animations\MA6.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_LIGHT_BIPOD;
			};
		};
	};

	//Carbine
	class twelfth_MA6_K: twelfth_MA37K {
		model="x\12thMEU\addons\12th_weapons\data\MA6_K\MA6_K.p3d";
		author = "Sammy";
		scope = 2;
		scopeArsenal = 2;
		displayName = "[12th] MA6-K Carbine";
		baseWeapon = "twelfth_MA6_K";
		canShootInWater = 1;
		magazines[] = COMMON_MA5C_MAGAZINES;
		handAnim[] = {"OFP2_ManSkeleton","x\12thMEU\addons\12th_weapons\data\MA6_K\animations\MA6_K.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_LIGHT_BIPOD;
			};
		};
	};

	//DM Rifle
	class twelfth_MA6_D: twelfth_M392 {
		model="x\12thMEU\addons\12th_weapons\data\MA6_D\MA6_D.p3d";
		author = "Sammy";
		scope = 2;
		scopeArsenal = 2;
		displayName = "[12th] MA6-D Marksman Rifle";
		baseWeapon = "twelfth_MA6_D";
		canShootInWater = 1;
		magazines[] = COMMON_MA5C_MAGAZINES;
		handAnim[] = {"OFP2_ManSkeleton","x\12thMEU\addons\12th_weapons\data\MA6\animations\MA6.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_MEDIUM_BIPOD;
			};
		};
	};

	// AR Rifle
	class twelfth_MA6_A_BOX: twelfth_M73H{
		model="x\12thMEU\addons\12th_weapons\data\MA6_A\MA6_A_BOX.p3d";
		author = "Sammy";
    mass = 160;
		displayName = "[12th] MA6-A Box";
		baseWeapon = "twelfth_MA6_A_BOX";
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_MEDIUM_BIPOD;
			};
		};
	};
	class twelfth_MA6_A_DRUM: twelfth_M73H{
		model="x\12thMEU\addons\12th_weapons\data\MA6_A\MA6_A_DRUM.p3d";
		author = "Sammy";
    mass = 160;
		displayName = "[12th] MA6-A Drum";
		baseWeapon = "twelfth_MA6_A_DRUM";
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_MEDIUM_BIPOD;
			};
		};
	};

  // IAR Rifle
  class twelfth_MA6_B: twelfth_MA5B {
		model="x\12thMEU\addons\12th_weapons\data\MA6_D\MA6_D.p3d";
		author = "Rex";
		scope = 2;
		scopeArsenal = 2;
		displayName = "[12th] MA6-B IAR";
		baseWeapon = "twelfth_MA6_B";
		canShootInWater = 1;
		magazines[] = {"OPTRE_60Rnd_762x51_Mag", "twelfth_60Rnd_762x51_Mag_T", "OPTRE_32Rnd_762x51_Mag", "OPTRE_32Rnd_762x51_Mag_Tracer", "OPTRE_32Rnd_762x51_Mag_UW" };
		handAnim[] = {"OFP2_ManSkeleton","x\12thMEU\addons\12th_weapons\data\MA6\animations\MA6.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_MEDIUM_BIPOD;
			};
		};
	};

  class twelfth_MA6_AL: twelfth_MA5B {
		model="x\12thMEU\addons\12th_weapons\data\MA6_D\MA6_D.p3d";
		author = "Rex";
		scope = 2;
		scopeArsenal = 2;
		displayName = "[12th] MA6-B H-IAR";
		baseWeapon = "twelfth_MA6_AL";
		canShootInWater = 1;
		magazines[] = {"twelfth_56Rnd_95x40_Mag", "twelfth_56Rnd_95x40_Mag_T", "OPTRE_36Rnd_95x40_Mag", "OPTRE_36Rnd_95x40_Mag_Tracer","twelfth_br_36Rnd_UW" };
		handAnim[] = {"OFP2_ManSkeleton","x\12thMEU\addons\12th_weapons\data\MA6\animations\MA6.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleitems[] = { "OPTRE_MA5Suppressor" };
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleitems[] = COMMON_SIGHTS;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleitems[] = {COMMON_RAIL_ATTACHMENTS};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				compatibleitems[] = COMMON_MEDIUM_BIPOD;
			};
		};
	};
  /*
    =============================================================================
    Custom Attachments
    =============================================================================
  */
	class MA6_K_SmartLink: ACE_optic_Hamr_2D{
		author = "Sammy";
		displayName = "[12th] MA6-K Smartlink";
		descriptionShort = "MA6-K Smartlink";
		model = "x\12thMEU\addons\12th_weapons\data\MA6_Smartlink\MA6_K_SmartLink.p3d";
	};
	class MA6_SmartLink: optic_DMS{
		author = "Sammy";
		displayName = "[12th] MA6 Smartlink";
		descriptionShort = "MA6 Smartlink";
		model = "x\12thMEU\addons\12th_weapons\data\MA6_Smartlink\MA6_SmartLink.p3d";
	};
/* 	class MA6_Flashlight: ACE_SPIR{
		author = "Sammy";
		class ItemInfo: InventoryUnderItem_Base_F
		{
			allowedSlots[]={};
		};
	}; */
};