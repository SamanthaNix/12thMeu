/*
  ==============================================================================
  config_magazines.hpp

  This file defines all magazine classes. Each class can inherit from an ArmA
  base magazine or a modded base magazine. The main differences typically are
  capacity, ammo type, display name, and mass.

  Key Properties:
    - `count`: number of rounds.
    - `ammo`: the type of CfgAmmo it fires.
    - `initspeed`: muzzle velocity in m/s (some parent classes also set this).
    - `mass`: used by ACE to represent weight. (Bigger number = heavier)
    - `scope`: 
        2 = Public, visible in Arsenal.
        1 = Hidden in-game, but accessible by script.
        0 = Not visible/hidden, used internally.

  Keep consistent naming so players/devs can easily find the correct magazine!
  ==============================================================================
*/
class CfgMagazineWells
{
  class CBA_Carl_Gustaf
  {
    twelfth_MAAWS_ammo[] =
    {
      "twelfth_HEAT_95"
    };
  };
};


class CfgMagazines
{
  // Forward declarations (inheritance targets)
  class OPTRE_32Rnd_762x51_Mag;         // Base class for 7.62x51mm magazine
  class OPTRE_100Rnd_762x51_Box_Tracer; // Base class for 7.62 Boxes
  class OPTRE_100Rnd_762x51_Box;        // Base class for 7.62 Boxes w/ tracers
  class OPTRE_36Rnd_95x40_Mag_Tracer;   // Base class for 9.5 Boxes
  class OPTRE_36Rnd_95x40_Mag;          // Base class for 9.5x40mm magazine
  class OPTRE_400Rnd_762x51_Box_Tracer; // Base class for 7.62x51mm tracer box
  class OPTRE_60Rnd_5x23mm_Mag;         // Base class for 5x23mm magazine
  class OPTRE_60Rnd_5x23mm_Mag_Tracer;
  class M319_HEAT_Grenade_Shell;        // Base class for 40mm HEAT shell
  class CA_LauncherMagazine;
  class RPG32_HE_F;
  class OPTRE_60Rnd_762x51_Mag; 		//Base class for MA5B 60round mag
  class MRAWS_HEAT_F;
  class OPTRE_M739_SAW_128rnd_Drum;
  class OPTRE_M739_SAW_192rnd_Box;
  class OPTRE_12Rnd_8Gauge_Slugs;
  class OPTRE_12Rnd_8Gauge_Pellets;

  // Training Magazine for BB
  class twelfth_20g_mag : OPTRE_32Rnd_762x51_Mag
  {
    displayName = "32Rnd .20g BB Cartridge";
    displaynameshort = ".20g BB";
    count = 32;           // Number of rounds in the magazine
    initspeed = 1500;     // Initial bullet speed in meters per second
    ammo = "twelfth_20g_bb"; // Type of ammo used
  };
  // Underwater BR magazine
  class twelfth_br_36Rnd_UW : OPTRE_36Rnd_95x40_Mag
  {
    author = "Weber";
    displayName = "36Rnd 9.5x40mm Magazine (Underwater)";
    count = 36;
    initspeed = 700;
    descriptionShort = "36 Round Magazine 9.5x40mm";
    mass = 10;
    ammo = "twelfth_95x40_UW"; // Underwater ammunition
  };
  // Underwater M7 60-round mag
  class twelfth_m7_60rnd_UW : OPTRE_60Rnd_5x23mm_Mag
  {
    picture = "\TCP\Weapons\Ammo\5x23\Ball\data\ui\icon_5x23mm_60rnd_CA.paa";
		modelSpecial = "\TCP\Weapons\Ammo\5x23\Ball\mag_5x23mm_60rnd.p3d";
    author = "Weber";
    displayName = "60Rnd 5x23mm Magazine (Underwater)";
    count = 60;
    initspeed = 700;
    descriptionShort = "60 Round Magazine 5x23mm (Increased Muzzle Velocity)";
    mass = 6;
    ammo = "twelfth_5x23mm_UW"; // Underwater ammunition
  };
  // Underwater M7 48-round mag
  class twelfth_m7_48rnd_UW : OPTRE_60Rnd_5x23mm_Mag
  {
    picture = "\TCP\Weapons\Ammo\5x23\Ball\data\ui\icon_5x23mm_48rnd_CA.paa";
		modelSpecial = "\TCP\Weapons\Ammo\5x23\Ball\mag_5x23mm_48rnd.p3d";
    author = "Weber";
    displayName = "48Rnd 5x23mm Magazine (Underwater)";
    count = 48;
    initspeed = 700;
    descriptionShort = "48 Round Magazine 5x23mm (Increased Muzzle Velocity)";
    mass = 6;
    ammo = "twelfth_5x23mm_UW"; // Underwater ammunition
  };
  // M7 60-round mag
  class twelfth_m7_60rnd : OPTRE_60Rnd_5x23mm_Mag
  {
    picture = "\TCP\Weapons\Ammo\5x23\Ball\data\ui\icon_5x23mm_60rnd_CA.paa";
		modelSpecial = "\TCP\Weapons\Ammo\5x23\Ball\mag_5x23mm_60rnd.p3d";
    author = "Weber";
    displayName = "60Rnd 5x23mm Magazine";
    count = 60;
    initspeed = 700;
    descriptionShort = "60 Round Magazine 5x23mm (Increased Muzzle Velocity)";
    mass = 6;
  };
  // M7 48-round mag
  class twelfth_m7_48rnd : OPTRE_60Rnd_5x23mm_Mag
  {
    picture = "\TCP\Weapons\Ammo\5x23\Ball\data\ui\icon_5x23mm_48rnd_CA.paa";
		modelSpecial = "\TCP\Weapons\Ammo\5x23\Ball\mag_5x23mm_48rnd.p3d";
    author = "Weber";
    displayName = "48Rnd 5x23mm Magazine";
    count = 48;
    initspeed = 700;
    descriptionShort = "48 Round Magazine 5x23mm (Increased Muzzle Velocity)";
    mass = 6;
  };
    // M7 60-round mag Tracer
  class twelfth_m7_60rnd_T : OPTRE_60Rnd_5x23mm_Mag_Tracer
  {
    picture = "\TCP\Weapons\Ammo\5x23\Ball\data\ui\icon_5x23mm_60rnd_CA.paa";
		modelSpecial = "\TCP\Weapons\Ammo\5x23\Ball\mag_5x23mm_60rnd.p3d";
    author = "Weber";
    displayName = "60Rnd 5x23mm Magazine (Tracer)";
    count = 60;
    initspeed = 700;
    descriptionShort = "60 Round Magazine 5x23mm (Increased Muzzle Velocity)";
    mass = 6;
  };
  // M7 48-round mag Tracer
  class twelfth_m7_48rnd_T : OPTRE_60Rnd_5x23mm_Mag_Tracer
  {
    picture = "\TCP\Weapons\Ammo\5x23\Ball\data\ui\icon_5x23mm_48rnd_CA.paa";
		modelSpecial = "\TCP\Weapons\Ammo\5x23\Ball\mag_5x23mm_48rnd.p3d";
    author = "Weber";
    displayName = "48Rnd 5x23mm Magazine (Tracer)";
    count = 48;
    initspeed = 700;
    descriptionShort = "48 Round Magazine 5x23mm (Increased Muzzle Velocity)";
    mass = 6;
  };
  // Custom 40mm HEAT magazine
  class twelfth_40mm_heat : M319_HEAT_Grenade_Shell
  {
    scope = 2;
    displayName = "[12th] 40mm HEAT";
    displaynameshort = "40mm HEAT";
    ammo = "twelfth_40mmG_HEAT"; // 40mm HEAT grenade
    author = "Waylen";        // Nerd (your mother - waylen)
    mass = 8;
  };
  // M96 LAW rocket magazine
  class twelfth_m96_magazine: RPG32_HE_F 
  {
    scope = 2;
    allowedSlots[] = {};
    displayName = "M96 HEAT Disposable Rockets";
    displaynameshort = "HEAT";
    descriptionShort = "High Explosive Anti Tank<br/>Un-guided";
    ammo = "twelfth_m96_rocket_heat"; 
    picture = "\DMNS\Weapons\Launchers\icons\gear_rpg32_rocket_ca.paa";
    model = "\a3\weapons_f\ammo\rocket_01_f.p3d";
    count = 1;
    mass = 45;
    initSpeed = 650;
    
  };
  // MG Belts
  class twelfth_100Rnd_762x51_Box: OPTRE_100Rnd_762x51_Box 
  {
    scope = 2;
    author = "Waylen";
    displayName = "100rnd 7.62x51mm Box";
    count = 100;
    mass = 40; // 4 lbs
    lastRoundsTracer = 20; 
    ACE_isBelt = 1; 
  };

  class twelfth_100Rnd_762x51_Box_T: OPTRE_100Rnd_762x51_Box_Tracer 
  {
    scope = 2;
    author = "Waylen";
    displayName = "100rnd 7.62x51mm Box (T)";
    picture = "\TCP\Weapons\Ammo\762x51\Ball\data\ui\icon_762x51mm_100rnd_CA.paa";
		model = "\TCP\Weapons\Ammo\762x51\Ball\mag_762x51mm_100rnd.p3d";
		modelSpecial = "\TCP\Weapons\Ammo\762x51\Ball\mag_762x51mm_100rnd.p3d";
    count = 100;
    mass = 26; 
    lastRoundsTracer = 100; 
    ACE_isBelt = 1; 
  };

  class twelfth_200Rnd_762x51_Box: OPTRE_100Rnd_762x51_Box 
  {
    scope = 2;
    author = "Waylen";
    displayName = "200rnd 7.62x51mm Box";
    count = 200;
    mass = 60; // 6 lbs
    lastRoundsTracer = 40; 
    ACE_isBelt = 1; 
  };

  class twelfth_200Rnd_762x51_Box_T: OPTRE_100Rnd_762x51_Box_Tracer 
  {
    scope = 2;
    author = "Waylen";
    displayName = "200rnd 7.62x51mm Box (T)";
    picture = "\TCP\Weapons\Ammo\762x51\Ball\data\ui\icon_762x51mm_200rnd_CA.paa";
		model = "\TCP\Weapons\Ammo\762x51\Ball\mag_762x51mm_200rnd.p3d";
		modelSpecial = "\TCP\Weapons\Ammo\762x51\Ball\mag_762x51mm_200rnd.p3d";
    count = 200;
    mass = 32;
    lastRoundsTracer = 200; 
    ACE_isBelt = 1; 
  };

  class twelfth_400Rnd_762x51_Box: OPTRE_100Rnd_762x51_Box 
  {
    scope = 2;
    author = "Waylen";
    displayName = "400rnd 7.62x51mm Box";
    count = 400;
    mass = 90; // 9 lbs
    lastRoundsTracer = 40; 
    ACE_isBelt = 1; 
  };

  class twelfth_400Rnd_762x51_Box_T: OPTRE_100Rnd_762x51_Box_Tracer 
  {
    scope = 2;
    author = "Waylen";
    displayName = "400rnd 7.62x51mm Box (T)";
    count = 400;
    mass = 90; // 9 lbs
    lastRoundsTracer = 400; 
    ACE_isBelt = 1; 
  };
  // 9.5x40mm box mag
  class twelfth_100Rnd_95x40_Box: OPTRE_36Rnd_95x40_Mag_Tracer
  {
    scope = 2;
    author = "Waylen";
    displayName = "100rnd 9.5x40mm Box";
    count = 100;
    mass = 50; // 4.5 lbs
    lastRoundsTracer = 100; 
    ACE_isBelt = 1; 
  };

  class twelfth_100Rnd_95x40_Box_T: OPTRE_36Rnd_95x40_Mag_Tracer
  {
    scope = 2;
    author = "Waylen";
    displayName = "100rnd 9.5x40mm Box (T)";
    count = 100;
    mass = 50; // 4.5 lbs
    lastRoundsTracer = 100; 
    ACE_isBelt = 1; 
  };
  
  //60 round 7.62x51 Tracer magazine
  class twelfth_60Rnd_762x51_Mag_T: OPTRE_60Rnd_762x51_Mag
  {
	  scope = 2;
	  author = "Sammy";
	  displayName = "60Rnd 7.62x51mm Tracer";
	  tracersEvery=1;
  };

  class twelfth_HEAT_95: MRAWS_HEAT_F
  {
    scope = 2;
    author = "Waylen";
    displayName = "MAAWS HEAT 95 Round";
    mass = 50;
    ammo = "twelfth_MAAWS_HEAT";  
  };
  //200 Round SAW mag
  class twelfth_M739_SAW_200rnd_Drum: OPTRE_M739_SAW_128rnd_Drum{
	  scope = 2;
	  author = "Sammy";
	  count=200;
	  displayName = "200Rnd 7.62x51mm Tracer Drum";
  };
  class twelfth_M739_SAW_200rnd_Box: OPTRE_M739_SAW_192rnd_Box{
	  scope = 2;
	  author = "Sammy";
	  count=200;
    mass = 32;
	  displayName = "200Rnd 7.62x51mm Tracer Box";
  };

  //56 round 9.5 magazine
   class twelfth_56Rnd_95x40_Mag: OPTRE_36Rnd_95x40_Mag{
    scope = 2;
    author = "Rex";
    displayName = "56rnd 9.5x40mm Box";
    count = 56;
    mass = 28;
  };

  class twelfth_56Rnd_95x40_Mag_T: OPTRE_36Rnd_95x40_Mag_Tracer{
    scope = 2;
    author = "Rex";
    displayName = "56rnd 9.5x40mm Box (T)";
    count = 56;
    mass = 28; 
  };
// shot shells
  class twelfth_12rnd_8ga_b : OPTRE_12Rnd_8Gauge_Pellets{
    scope = 2;
    author = "Rex";
    displayName = "12Rnd 8 Gauge Buckshot";
    model = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
		modelSpecial = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
    count = 12;
    mass = 16;
  };

  class twelfth_12rnd_8ga_s : OPTRE_12Rnd_8Gauge_Slugs{
    scope = 2;
    author = "Rex";
    displayName = "12Rnd 8 Gauge Slugs";
    model = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
		modelSpecial = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
    count = 12;
    mass = 16;
  };

    class twelfth_6rnd_8ga_b : OPTRE_12Rnd_8Gauge_Pellets{
    scope = 2;
    author = "Rex";
    displayName = "6Rnd 8 Gauge Buckshot";
    model = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
		modelSpecial = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
    count = 6;
    mass = 8;
  };

  class twelfth_6rnd_8ga_s : OPTRE_12Rnd_8Gauge_Slugs{
    scope = 2;
    author = "Rex";
    displayName = "6Rnd 8 Gauge Slugs";
    model = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
		modelSpecial = "\TCP\Weapons\Ammo\8Gauge\Pellets\mag_8Gauge_1Rnd_Pellets.p3d";
    count = 6;
    mass = 8;
  };

};