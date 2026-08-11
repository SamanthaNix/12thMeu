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
	class LandVehicle;
	class Tank: LandVehicle {
		class NewTurret;
		class Sounds;
		class HitPoints;
	};

	class Tank_F: Tank {
		class AnimationSources;
		class Turrets {
			class MainTurret:NewTurret {
				class Turrets {
					class CommanderOptics;
				};
			};
		};
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints {
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds {
			class Engine;
			class Movement;
		};
	};

	class MBT_02_railgun_base_F: Tank_F {
		class HitPoints: HitPoints {
			class HitEngine;
			class HitHull;
			class HitLTrack;
			class HitRTrack;
		};
	};

	class SMT_Viper_Base_F: MBT_02_railgun_base_F {
		author = "SamanthaNix";
		model = "\x\12thMEU\addons\Viper\SMT_viper.p3d";
		picture	= "\x\12thMEU\addons\Viper\Data\preview.paa"; /// just some icon in command bar

		#include "pip.hpp"
		#include "sound.hpp"	/// sounds are in a separate file to make this one simple
		#include "physx.hpp"	/// PhysX settings are in a separate file to make this one simple

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

		//ACRE stuff
		class AcreRacks 
		{
			class Rack_1 
			{
				displayName = "Dash"; 
				shortName = "Dash";
				componentName = "ACRE_VRC103";
				allowedPositions[] = {"driver"};
				disabledPositions[] = {};
				defaultComponents[] = {};
				mountedRadio = "ACRE_PRC117F";               
				isRadioRemovable = 0;                 
			};
		};

		//TFAR
		tf_RadioType = "TFAR_rt1523g_big";
		tf_hasLRradio = 1;
		tf_isolatedAmount = 0.3;


		class TransportMagazines {};
		class TransportWeapons {};

		//Handling
		terrainCoef = 0;
		turnCoef = 4;
		precision = 10;
		brakeDistance = 3.0;
		acceleration = 30;
		fireResistance = 5;
		armor = 250;
		cost = 50000; /// how likely is the enemy going to target this vehicle

		transportMaxBackpacks 	= 2; /// just some backpacks fit the trunk by default
		transportSoldier 		= 0; /// number of cargo except driver

		maxFordingDepth 		= 2;			/// how high water would damage the engine of the car
		waterResistance 		= 10;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.3;			/// multiplier of damage to crew of the vehicle => low number means better protection

		driverAction 		= "driver_offroad01"; /// what action is going the driver take inside the vehicle. Non-existent action makes the vehicle inaccessible
		gunnerAction[] 		= {""}; /// the same of all the crew
		getInAction 		= "GetInLow"; 		/// how does driver look while getting in
		getOutAction 		= "GetOutLow"; 		/// and out



/* 		class UVAnimations{
			class TrackAnimation{
				type			= "translation";
				// name of source, either custom one, defined in AnimationSources class or regular model.cfg source
				// It can be animated with animateSource & value can be retrieved via animationSourcePhase
				source			= "time";
				sourceAddress	= "loop";
				// section name from model.cfg sections[] array
				section			= "camo3";
				minValue		= 0;
				maxValue		= 1;
				// Transformation of UV coordinates
				offset0[]		= { 0, 0 };
				offset1[]		= { 0, 1 };
			};
		}; */
		class AnimationSources : AnimationSources {

		};
		class PlayerSteeringCoefficients /// steering sensitivity configuration
		{
			 turnIncreaseConst 	= 0.3; // basic sensitivity value, higher value = faster steering
			 turnIncreaseLinear = 1.0; // higher value means less sensitive steering in higher speed, more sensitive in lower speeds
			 turnIncreaseTime 	= 1.0; // higher value means smoother steering around the center and more sensitive when the actual steering angle gets closer to the max. steering angle

			 turnDecreaseConst 	= 5.0; // basic caster effect value, higher value = the faster the wheels align in the direction of travel
			 turnDecreaseLinear = 3.0; // higher value means faster wheel re-centering in higher speed, slower in lower speeds
			 turnDecreaseTime 	= 0.0; // higher value means stronger caster effect at the max. steering angle and weaker once the wheels are closer to centered position

			 maxTurnHundred 	= 0.7; // coefficient of the maximum turning angle @ 100km/h; limit goes linearly to the default max. turn. angle @ 0km/h
		};

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
				ace_fcs_DistanceInterval = 5;
				ace_fcs_Enabled = 0;
				ace_fcs_MaxDistance = 5500;
				ace_fcs_MinDistance = 200;
				aggregateReflectors[] = {};
				allowLauncherIn = 0;
				allowLauncherOut = 0;
				allowTabLock = 1;
				animationSourceBody = "mainTurret";
				animationSourceCamElev = "camElev";
				animationSourceGun = "mainGun";
				animationSourceHatch = "hatchGunner";
				animationSourceStickX = "joystick_gunner_x";
				animationSourceStickY = "joystick_gunner_y";
				armorLights = 0.4;
				body = "mainTurret";
				class Components {};
				disableSoundAttenuation = 0;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;
				dontCreateAI = 0;
				ejectDeadGunner = 0;
				enableManualFire = 0;
				forceHideGunner = 0;
				forceNVG = 0;
				gun = "mainGun";
				gunBeg = "muzzle";
				gunEnd = "chamber";
				gunnerAction = "gunner_MRAP_01";
				gunnerCompartments = "Compartment1";
				gunnerDoor = "";
				gunnerFireAlsoInInternalCamera = 1;
				gunnerForceOptics = 0;
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				gunnerInAction = "ManActTestDriver";
				gunnerLeftHandAnimName = "";
				gunnerLeftLegAnimName = "";
				gunnerName = "Gunner";
				gunnerOpticsColor[] = {0,0,0,1};
				gunnerOpticsEffect[] = {};
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerOpticsShowCursor = 0;
				gunnerOutFireAlsoInInternalCamera = 1;
				gunnerOutForceOptics = 0;
				gunnerOutOpticsColor[] = {0,0,0,1};
				gunnerOutOpticsEffect[] = {};
				gunnerOutOpticsModel = "";
				gunnerOutOpticsShowCursor = 0;
				gunnerRightHandAnimName = "joystick_gunner";
				gunnerRightLegAnimName = "";
				gunnerType = "";
				gunnerUsesPilotView = 0;
				hasGunner = 1;
				hideWeaponsGunner = 1;
				class HitPoints: HitPoints {};
				inGunnerMayFire = 1;
				initCamElev = 0;
				initElev = 0;
				initOutElev = 0;
				initOutTurn = 0;
				initTurn = 0;
				isCopilot = 0;
				lockWhenDriverOut = 0;
				lockWhenVehicleSpeed = -1;
				//LODTurnedIn = -1;
				//LODTurnedOut = -1;
				maxCamElev = 90;
				maxElev = 60;
				maxHorizontalRotSpeed = 1.2;
				maxOutElev = 20;
				maxOutTurn = 60;
				maxTurn = 360;
				maxVerticalRotSpeed = 2.2;
				memoryPointGun = "muzzle";
				memoryPointGunnerOptics = "PIP0_dir";
				memoryPointGunnerOutOptics = "";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				memoryPointsGetInGunnerPrecise = "";
				minCamElev = -90;
				minElev = -50;
				minOutElev = -50;
				minOutTurn = -60;
				minTurn = -360;
				missileBeg = "spice rakety";
				missileEnd = "konec rakety";
				outGunnerMayFire = 1;
				playerPosition = 0;
				preciseGetInOut = 0;
				primary = 1;
				primaryGunner = 1;
				primaryObserver = 0;
				proxyIndex = 1;
				proxyType = "CPGunner";
				class Reflectors {};
				selectionFireAnim = "zasleh";
				showAllTargets = 0;
				showCrewAim = 0;
				showHMD = 0;
				slingLoadOperator = 0;
				stabilizedInAxes = 3;
				startEngine = 0;
				class TurnIn {
					turnOffset = 0;
				};
				class TurnOut {
					turnOffset = 0;
				};
				turretCanSee = 0;
				turretFollowFreeLook = 0;
				turretInfoType = "RscOptics_MBT_02_Railgun_gunner";
				class Turrets {};
				//class TurretSpec {
				//showHeadPhones = 0;
				//};
				usePip = 1;
				/*class ViewGunner {
					continuous = 0;
					initAngleX = -5;
					initAngleY = 0;
					initFov = 0.9;
					maxAngleX = 85;
					maxAngleY = 150;
					maxFov = 1.25;
					maxMoveX = 0;
					maxMoveY = 0;
					maxMoveZ = 0;
					minAngleX = -75;
					minAngleY = -150;
					minFov = 0.25;
					minMoveX = 0;
					minMoveY = 0;
					minMoveZ = 0;
					speedZoomMaxFOV = 0;
					speedZoomMaxSpeed = 1e+10;
				}; */
				viewGunnerInExternal = 1;
				viewGunnerShadow = 1;
				viewGunnerShadowAmb = 1;
				viewGunnerShadowDiff = 1;
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
				weapons[] = {"cannon_railgun"};
				magazines[] = { "60Rnd_75mm_RailGun_APFSDS_mag" };
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


		//camo
		hiddenSelections[] = {"camo1","camo2","unit"}; ///we want to allow changing the color of this selection
		hiddenSelectionsTextures[]={
			"x\12thMEU\addons\viper\data\textures\Chassis_co.paa",
			"x\12thMEU\addons\viper\data\textures\Turret_co.paa",
			"x\12thMEU\addons\smt_core\data\logo.paa",
			};
		class textureSources
		{
			class Viper_Camo_standard // Source class
			{
				displayName="Default"; // name displayed, among other, from the garage
				author="SamanthaNix"; // Author of the skin
				hiddenSelections[] = {"camo1","camo2","unit"};
				textures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\viper\data\textures\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\textures\Turret_co.paa",

				};
			};
			class Viper_Camo_winter:Viper_Camo_standard
			{
				displayName="Winter";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\winter\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\winter\Turret_co.paa"
				};
			};
			class Viper_Camo_forest:Viper_Camo_standard
			{
				displayName="Forest";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\forest\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\forest\Turret_co.paa"
				};
			};
			class Viper_Camo_TCP:Viper_Camo_standard
			{
				displayName="TCP";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\TCP\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\TCP\Turret_co.paa"
				};
			};
			class Viper_Camo_OPTRE:Viper_Camo_standard
			{
				displayName="OPTRE";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\OPTRE\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\OPTRE\Turret_co.paa"
				};
			};
			class Viper_Camo_Desert:Viper_Camo_standard
			{
				displayName="Desert";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\desert\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\desert\Turret_co.paa"
				};
			};
			class Viper_Camo_SMT:Viper_Camo_standard
			{
				displayName="SMT";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\SMT\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\SMT\Turret_co.paa"
				};
			};
			class Viper_Camo_Tan:Viper_Camo_standard
			{
				displayName="Tan";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\Tan\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\Tan\Turret_co.paa"
				};
			};
			class Viper_Camo_White:Viper_Camo_standard
			{
				displayName="White";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\viper\data\camo\White\Chassis_co.paa",
					"x\12thMEU\addons\viper\data\camo\White\Turret_co.paa"
				};
			};
		};
	};

	class SMT_Viper_200mm: SMT_Viper_Base_F {
		editorCategory = "ED_SMT_Faction";
		editorSubcategory="EDS_SMT_faction_Viper";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage = 1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator = 2;		// scope 2 means it's available in Zeus mode (0 means hidden)
		displayName = "M-700 Viper";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car

		weapons[] += {}; //TODO add gun
		magazines[] += {}; //TODO add gun mags
	};
	class SMT_Viper_200mm_20: SMT_Viper_Base_F {
		model = "\x\12thMEU\addons\Viper\SMT_viper20.p3d";
		editorCategory = "ED_SMT_Faction";
		editorSubcategory="EDS_SMT_faction_Viper";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage = 1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator = 2;		// scope 2 means it's available in Zeus mode (0 means hidden)
		displayName = "M-700 Viper 80%";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car

		weapons[] += {}; //TODO add gun
		magazines[] += {}; //TODO add gun mags
	};
};
