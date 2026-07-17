class CfgVehicles
{ 
	class AnimationSources;
	class ViewOptics;
	class Optics_Armored;
	class RCWSOptics;
	class Optics_Gunner_APC_01: Optics_Armored {
		class Wide;
		class Medium;
		class Narrow;
	};

	// class LandVehicle;
	// class Car: LandVehicle
	// {
	// 	class NewTurret;
	// };
	// class Car_F: Car
	// {
	// 	class AnimationSources;
	// 	class Turrets
	// 	{
	// 		class MainTurret: NewTurret
	// 		{
	// 			class Components;
	// 			class ViewGunner;
	// 		};
	// 	};
	// 	class HitPoints
	// 	{
	// 		class HitGlass1;
	// 		class HitGlass2;
	// 		class HitGlass3;
	// 		class HitGlass4;
	// 		class HitGlass5;
	// 		class HitGlass6;
	// 		class HitBody;
	// 	};
	// 	class ViewCargo;
	// };

  //VIPER START
  class LandVehicle {
    class NewTurret;
    class HitPoints;
  };
  class Tank: LandVehicle {
    class CargoLight {};
    class Components {
      class AITankSteeringComponent;
    };
    class HitPoints: HitPoints {
      class HitEngine;
      class HitHull;
      class HitLTrack;
      class HitRTrack;
    };
    class Turrets {
      class MainTurret: NewTurret{
        class Turrets {
          class CommanderOptics: NewTurret;
        };
      };
    };
    class ViewOptics {};
    class ViewPilot {};
  };

  class Tank_F: Tank {
    class CamShake;
    class Components {
      class VehicleSystemsDisplayManagerComponentLeft;
      class VehicleSystemsDisplayManagerComponentRight;
    };
    class EventYHandlers;
    class HitPoints: HitPoints {
      class HitEngine;
      class HitHull;
      class HitLTrack;
      class HitRTrack;
    };
    class NVGMarkers;
    class Turrets;
  };

  class MBT_01_base_F: Tank_F {
    class HitPoints: HitPoints {
      class HitEngine;
      class HitHull;
      class HitLTrack;
      class HitRTrack;
    };
  };

  class SMT_Viper_Base_F: MBT_01_base_F {
    author = "SamanthaNix";
		model = "\x\12thMEU\addons\Viper\SMT_viper.p3d";
		picture	= "\x\12thMEU\addons\Viper\Data\preview.paa"; /// just some icon in command bar

    #include "pip.hpp"

    //Editor stuff
		editorPreview = "\x\12thMEU\addons\Viper\Data\preview.paa";
		Icon	= "\A3\Weapons_F\Data\placeholder_co.paa"; /// icon in map
		displayName = "Viper Hull"; /// displayed in Editor

    //Ace stuff
		ace_repair_spareWheels = 0;
    ace_repair_spareTrack = 2;
		ace_cargo_space = 0;  // Cargo space your vehicle has
    ace_cargo_hasCargo = 0;
		ace_vehicle_damage_detonationDuringFireProb = 0;
		ace_cookoff_canHaveFireJet = 0;

    class Exhausts { /// specific exhaust effects for the car
			class Exhaust1 { // left exhaust pipes behind tank
				position 	= "exhaust1_pos";  		/// name of initial memory point
				direction 	= "exhaust1_dir";	/// name of memory point for exhaust direction
				effect 		= "ExhaustsEffect";	/// what particle effect is it going to use
			};
      class Exhaust2: Exhaust1 { // right exhaust pipes behind tank
				position 	= "exhaust2_pos";  		/// name of initial memory point
				direction 	= "exhaust2_dir";	/// name of memory point for exhaust direction
			};
      class EngineHeat1 { // left vent above engine bay
				position 	= "engineHeat1_pos";  		/// name of initial memory point
				direction 	= "engineHeat1_dir";	/// name of memory point for exhaust direction
				effect 		= "Refract";	/// what particle effect is it going to use
			};
      class EngineHeat2: EngineHeat1 { // right vent above engine bay
				position 	= "engineHeat2_pos";  		/// name of initial memory point
				direction 	= "engineHeat2_dir";	/// name of memory point for exhaust direction
			};
		};

    class HitPoints: HitPoints {
      class HitEngine;
      class HitHull;
      class HitLTrack;
      class HitRTrack;
    };

    class Turrets: Turrets {
      class MainTurret: MainTurret {

      };
    };

    // class MFD {
    //   class MFD_Gunner_Display_Left
    //   class MFD_Gunner_Display_Right
    //   class MFD_Vehicle_Status
    //   class MFD_Driver_Display {
    //     alpha = 0.5;
    //     class Bones{};
    //     borderBottom = 0;
    //     borderRight = 0;
    //     borderLeft = 0;
    //     borderTop = 0;

    //     topLeft
    //     topRight
    //     bottomLeft
    //     class Draw {
    //       alpha = 1;
    //       color = {1,1,1};
    //       condition = "on";
    //       class Driver_Speed {
            
    //       };
    //     };
    //   };
    //   class MFD_Ball_Turret_Display
    //   class MFD_Boot_Sequence
    // };

    // typicalCargo = ["B_Soldier_F"];

    // smoke GL
    smokeLauncherAngle = 120; // angle onto which distribute smokes
    smokeLauncherGrenadeCount = 6; // amount of smokes per salvo
    smokeLauncherOnTurret = 0; // 0 if on hull
    smokeLauncherVelocity = 14; // speed of smoke grenade, rest is on the weapon

    weapons[] = {"SmokeLauncher"};
    magazines[] = {"SmokeLauncherMag"};
  };

  class SMT_Viper_200mm: SMT_Viper_Base_F {
    editorCategory = "ED_SMT_Faction";
    editorSubcategory="EDS_SMT_faction_Viper";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage = 1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator = 2;		// scope 2 means it's available in Zeus mode (0 means hidden)
		displayName = "M18-C2 IMV Cargo (Minigun)";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car

    weapons[] += {}; //TODO add gun
    magazines[] += {}; //TODO add gun mags
  };
};