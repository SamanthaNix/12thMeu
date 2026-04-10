#pragma hemtt suppress pw3_padded_arg config


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

	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class AnimationSources;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Components;
				class ViewGunner;
			};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitBody;
		};
		class ViewCargo;
	};

	class Dingo_Base_F: Car_F
	{
		class EventHandlers;
		class VehicleTransport;
		class ViewOptics;
		class ViewCargo;
		class Sounds
		{
			class Engine;
			class Movement;
		};
		class NewTurret;
		class AnimationSources;
	};


	class SMT_DingoHull: Dingo_Base_F
	{
		author="SamanthaNix";
		model = "\x\12thMEU\addons\Dingo\Dingo.p3d";
		picture	= "\x\12thMEU\addons\Dingo\Data\preview.paa"; /// just some icon in command bar

		//Editor stuff
		editorPreview = "\x\12thMEU\addons\Dingo\Data\preview.paa";
		Icon	= "\A3\Weapons_F\Data\placeholder_co.paa"; /// icon in map

		displayName = "Dingo Hull"; /// displayed in Editor

		
		//Ace stuff
		ace_repair_spareWheels = 1;
		ace_cargo_space = 6;  // Cargo space your vehicle has
        ace_cargo_hasCargo = 1;
		ace_vehicle_damage_detonationDuringFireProb = 0;
		ace_cookoff_canHaveFireJet = 0;
		//Component selection
		class AnimationSources: AnimationSources
		{
			class hideUnitAffilSelect
			{
				author = "Sammy";
				displayName = "Hide Unit Affiliation";
				source = "user";
				useSource = 1;
				initPhase = 1;
				animPeriod = 0.5;
			};
			class hideAllDecalSelect
			{
				author = "Sammy";
				displayName = "Hide Decals";
				source = "user";
				useSource = 1;
				initPhase = 1;
				animPeriod = 0.5;
			};
			class hideRollCageSelect {
				author = "Sammy";
				displayName = "Hide Roll Cage";
				source = "user";
				useSource = 1;
				initPhase = 1;
				animPeriod = 0.5;
			};
		};
		animationList[] = {
			"hideUnitAffilSelect",0, // never hide by default
			"hideAllDecalSelect",0, // never hide by default
			"hideRollCageSelect",0.5
		};	
		class UserActions
		{
			class PressXToFlipTheThing
			{
				displayName = "Flip Vehicle";
				displayNameDefault = "Flip Vehicle";
				radius = 5;
				position = "";
				onlyForPlayer = 1;
				condition = "(alive this) AND !(canMove this) AND (count crew this == 0 || isAutonomous this) AND (simulationEnabled this) AND ((locked this) < 2)";
				statement = "[this] call bis_fnc_unflipVehicle";
			};
		};

		//ACRE stuff
		class AcreIntercoms
		{
			class Intercom_1 
			{                            
                displayName = "Crew intercom";
                shortName = "Crew";
                allowedPositions[] = {"crew"};
                disabledPositions[] = {{"Turret", {0,0}}};
                limitedPositions[] = {{"cargo", "all"}};
                numLimitedPositions = 1;
                masterPositions[] = {"commander"};
                connectedByDefault = 1;
			};
		};
		acre_hasInfantryPhone = 1; // 1 - enabled, 0 - disabled (default: 0)
        acre_infantryPhoneDisableRinging = 0;   // If set to 1, the ringing funtionality will not be available (default: 0)
        acre_infantryPhoneCustomRinging[] = {}; // An array used in order to override the default sound for the ringing functionality (default: {})
        // List of intercom names (intercom_1, intercom_2) or "all" in order to specify which intercom networks the phone can connect to
        acre_infantryPhoneIntercom[] = {"all"};
        acre_infantryPhoneControlActions[] = {"intercom_1"}; // Only those units in "intercom_1" can have access to ringing functionality
        // Here a custom function can be defined that is called when the infantry phone is picked up, put back, given to another unit or the intercom network is switched
        acre_eventInfantryPhone = QFUNC(noApiFunction);
		class AcreRacks 
		{
           class Rack_1 
		   {
               displayName = "Dash"; 
               shortName = "Dash";
               componentName = "ACRE_VRC103";
               allowedPositions[] = {"driver", "commander"};
               disabledPositions[] = {};
               defaultComponents[] = {};
               mountedRadio = "ACRE_PRC117F";               
               isRadioRemovable = 0;
               intercom[] = {"intercom_1"};                   
           };
		};

		//TFAR
		tf_hasLRradio = 1;
		tf_isolatedAmount = 0.3;

		//hand anims
		driverLeftHandAnimName 	= "drivewheel"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "drivewheel";




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

		transportMaxBackpacks 	= 4; /// just some backpacks fit the trunk by default
		transportSoldier 		= 4; /// number of cargo except driver
		

		wheelDamageRadiusCoef = 0.75;
		wheelDestroyRadiusCoef = 0.6127954;			/// for tweaking of rims size to fit ground
		maxFordingDepth 		= 1.5;			/// how high water would damage the engine of the car
		waterResistance 		= 1;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.3;			/// multiplier of damage to crew of the vehicle => low number means better protection

		class TransportItems /// some first aid kits in trunk according to safety regulations
		{
			//item_xx(FirstAidKit,4);
		};

		class Turrets{}; /// doesn't have any gunner nor commander
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel	{armor=0.2; passThrough=0;}; /// it is easier to destroy wheels than hull of the vehicle
			class HitLBWheel: HitLF2Wheel	{armor=0.2; passThrough=0;};

			class HitRFWheel: HitRFWheel	{armor=0.2; passThrough=0;};
			class HitRBWheel: HitRF2Wheel 	{armor=0.2; passThrough=0;};

			class HitFuel 			{armor=0.50; material=-1; name="FuelTank"; visual=""; passThrough=0.2;}; /// correct points for fuel tank, some of the damage is aFRLied to the whole
			class HitEngine 		{armor=0.50; material=-1; name="Engine"; visual=""; passThrough=0.2;};
			class HitBody: HitBody 	{name = "body"; visual="camo1"; passThrough=1;}; /// all damage to the hull is aFRLied to total damage

		};

		driverAction 		= "driver_offroad01"; /// what action is going the driver take inside the vehicle. Non-existent action makes the vehicle inaccessible
		cargoAction[] 		= {"passenger_low01", "passenger_generic01_leanleft", "passenger_generic01_foldhands"}; /// the same of all the crew
		getInAction 		= "GetInLow"; 		/// how does driver look while getting in
		getOutAction 		= "GetOutLow"; 		/// and out
		cargoGetInAction[] 	= {"GetInLow"}; 	/// and the same for the rest, if the array has fewer members than the count of crew, the last one is used for the rest
		cargoGetOutAction[] = {"GetOutLow"}; 	/// that means all use the same in this case

		#include "sound.hpp"	/// sounds are in a separate file to make this one simple
		#include "physx.hpp"	/// PhysX settings are in a separate file to make this one simple

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

		/// memory points where do tracks of the wheel appear
		// front left track, left offset
		memoryPointTrackFLL = "TrackFLL";
		// front left track, right offset
		memoryPointTrackFLR = "TrackFLR";
		// back left track, left offset
		memoryPointTrackBLL = "TrackBLL";
		// back left track, right offset
		memoryPointTrackBLR = "TrackBLR";
		// front right track, left offset
		memoryPointTrackFRL = "TrackFRL";
		// front right track, right offset
		memoryPointTrackFRR = "TrackFRR";
		// back right track, left offset
		memoryPointTrackBRL = "TrackBRL";
		// back right track, right offset
		memoryPointTrackBRR = "TrackBRR";

		class Damage /// damage changes material in specific places (visual in hitPoint)
		{
			tex[]={};
			mat[]=
			{
				"A3\data_f\glass_veh_int.rvmat", 		/// material mapped in model
				"A3\data_f\Glass_veh_damage.rvmat", 	/// changes to this one once damage of the part reaches 0.5
				"A3\data_f\Glass_veh_damage.rvmat",		/// changes to this one once damage of the part reaches 1

				"A3\data_f\glass_veh.rvmat",			/// another material
				"A3\data_f\Glass_veh_damage.rvmat",		/// changes into different ones
				"A3\data_f\Glass_veh_damage.rvmat"
			};
		};

		class Exhausts /// specific exhaust effects for the car
		{
			class Exhaust1 /// the car has two exhausts - each on one side
			{
				position 	= "exhaust1_pos";  		/// name of initial memory point
				direction 	= "exhaust1_dir";	/// name of memory point for exhaust direction
				effect 		= "ExhaustsEffect";	/// what particle effect is it going to use
			};

		};

		class Reflectors	/// only front lights are considered to be reflectors to save CPU
		{
			class LightCarHeadL01 	/// lights on each side consist of two bulbs with different flares
			{
				color[] 		= {1900, 1800, 1700};		/// approximate colour of standard lights
				ambient[]		= {5, 5, 5};				/// nearly a white one
				position 		= "LightCarHeadL01";		/// memory point for start of the light and flare
				direction 		= "LightCarHeadL01_end";	/// memory point for the light direction
				hitpoint 		= "Light_L";				/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection 		= "Light_L";				/// selection for artificial glow around the bulb, not much used any more
				size 			= 1;						/// size of the light point seen from distance
				innerAngle 		= 100;						/// angle of full light
				outerAngle 		= 179;						/// angle of some light
				coneFadeCoef 	= 10;						/// attenuation of light between the above angles
				intensity 		= 1;						/// strength of the light
				useFlare 		= 1;						/// does the light use flare?
				dayLight 		= 0;					/// switching light off during day saves CPU a lot
				flareSize 		= 1.0;						/// how big is the flare

				class Attenuation
				{
					start 			= 1.0;
					constant 		= 0;
					linear 			= 0;
					quadratic 		= 0.25;
					hardLimitStart 	= 30;		/// it is good to have some limit otherwise the light would shine to infinite distance
					hardLimitEnd 	= 70;		/// this allows adding more lights into scene
				};
			};

			class LightCarHeadL02: LightCarHeadL01
			{
				position 	= "LightCarHeadL02";
				direction 	= "LightCarHeadL02_end";
				FlareSize 	= 0.5;						/// side bulbs aren't that strong
			};

			class LightCarHeadR01: LightCarHeadL01
			{
				position 	= "LightCarHeadR01";
				direction 	= "LightCarHeadR01_end";
				hitpoint 	= "Light_R";
				selection 	= "Light_R";
			};

			class LightCarHeadR02: LightCarHeadR01
			{
				position 	= "LightCarHeadR02";
				direction 	= "LightCarHeadR02_end";
				FlareSize 	= 0.5;
			};
		};
		class EventHandlers: EventHandlers
		{
			init = "if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;};";
		};
		aggregateReflectors[] = {{"LightCarHeadL01", "LightCarHeadL02"}, {"LightCarHeadR01", "LightCarHeadR02"}}; 

		hiddenSelections[] = {"camo1","camo7","camo11","camo8","camo10"}; ///we want to allow changing the color of this selection
		hiddenSelectionsTextures[]={"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa","x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa","x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa","x\12thMEU\addons\dingo\data\textures\standard\decals_ca.paa","#(rgb,8,8,3)color(0.18039216,0.18039216,0.18039216,1)"};	 /// we could use any texture to cover the car
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};

		class textureSources
		{
			class Dingo_Camo_standard // Source class
			{
				displayName="Default"; // name displayed, among other, from the garage
				author="SamanthaNix"; // Author of the skin
				hiddenSelections[] = {"camo1","camo7","camo11","camo8","camo10"};
				textures[]=// List of textures, in the same order as the hiddenSelections definition
				{
					"x\12thMEU\addons\dingo\data\textures\standard\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\standard\turret_co.paa"
				};
			};
			class Dingo_Camo_winter:Dingo_Camo_standard
			{
				displayName="Winter";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\dingo\data\textures\winter\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\winter\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\winter\turret_co.paa"
				};
			};
			class Dingo_Camo_forest:Dingo_Camo_standard
			{
				displayName="Forest";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\dingo\data\textures\forest\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\forest\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\forest\turret_co.paa"
				};
			};
			class Dingo_Camo_TCP:Dingo_Camo_standard
			{
				displayName="TCP";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\dingo\data\textures\TCP\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\TCP\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\TCP\turret_co.paa"
				};
			};
			class Dingo_Camo_OPTRE:Dingo_Camo_standard
			{
				displayName="OPTRE";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\dingo\data\textures\OPTRE\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\OPTRE\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\OPTRE\turret_co.paa"
				};
			};
			class Dingo_Camo_Black:Dingo_Camo_standard
			{
				displayName="Black";
				author="SamanthaNix";
				textures[]=
				{
					"x\12thMEU\addons\dingo\data\textures\black\Chassis_co.paa",
					"x\12thMEU\addons\dingo\data\textures\black\Modules_co.paa",
					"x\12thMEU\addons\dingo\data\textures\black\turret_co.paa"
				};
			};
		};
	};
	class SMT_DingoCargo: SMT_DingoHull
	{
    	editorCategory="ED_SMT_Faction";
    	editorSubcategory="EDS_SMT_faction_Dingo";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage=1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		displayName="M18-C IMV Cargo";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		textureList[]=
		{
			"Dingo_Camo_standard", 0.2,
			"Dingo_Camo_winter",0.2,
			"Dingo_Camo_forest",0.2,
			"Dingo_Camo_TCP",0.2,
			"Dingo_Camo_OPTRE",0.2,
			"Dingo_Camo_Black",0.2
		};
		class VehicleTransport
		{
			class Carrier
			{
				cargoBayDimensions[]		= { "VTV_limit_1", "VTV_limit_2" };	// Memory points in model defining cargo space
				// or
				//cargoBayDimensions[]		= { {-1.3,2.1,0.27}, {1.41,4.1,3.9} };			// alternatively, positions in model space (since 2.08)

				disableHeightLimit			= 1;								// If set to 1 disable height limit of transported vehicles
				maxLoadMass					= 5000;							// Maximum cargo weight (in Kg) which the vehicle can transport
				cargoAlignment[]			= { "front", "center" };				// Array of 2 elements defining alignment of vehicles in cargo space.
																		// Possible values are left, right, center, front, back. Order is important.

				cargoSpacing[]				= { 0, 0.15, 0 };					// Offset from X,Y,Z axes (in metres)

				exits[]						= { "VTV_exit_1", "VTV_exit_2" };	// Memory points in model defining loading ramps, could have multiple
				// or
				// exits[]					= { {5,0,0}, {5,10,0} };			// alternatively, positions in model space (since 2.08)

				unloadingInterval			= 2;								// Time between unloading vehicles (in seconds)
				loadingDistance				= 10;								// Maximal distance for loading in exit point (in meters).
				loadingAngle				= 60;								// Maximal sector where cargo vehicle must be to for loading (in degrees).
				parachuteClassDefault		= "B_Parachute_02_F";				// Type of parachute used when dropped in air. Can be overridden by parachuteClass in Cargo.
				parachuteHeightLimitDefault	= 50;								// Minimal height above terrain when parachute is used. Can be overridden by parachuteHeightLimit in Cargo.

				class CargoTypeWhitelist										// Whitelist. If this isn't empty, only listed vehicles (isKindOf) can load into (since 2.10)
				{
 			
				};
			};
			class Cargo
			{
				parachuteClass			= "B_Parachute_02_F";	// Type of parachute used when dropped in air. When empty then parachute is not used.
				parachuteHeightLimit	= 40;				// Minimal height above terrain when parachute is used.
				canBeTransported		= 1;				// 0 (false) / 1 (true)

				dimensions[]			= { "BBox_1_1_pos", "BBox_1_2_pos" };	// Memory-point-based override of automatic bounding box
				// or
				// dimensions[]			= { { 0,0,0 }, { 3,2,1.5 } };			// alternatively, positions in model space (since 2.08)

				rotation = -90;								// (optional) Defines in which direction the vehicle gets rotated when its loaded into ViV cargo and will only fit when rotated
													// Only -90 and 90 are supported. Since v2.08
			};
		};
	};
	class SMT_DingoRCWS_minigun: SMT_DingoHull
	{
    	editorCategory = "ED_SMT_Faction";
    	editorSubcategory="EDS_SMT_faction_Dingo";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage = 1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator = 2;		// scope 2 means it's available in Zeus mode (0 means hidden)
		displayName = "M18-C2 IMV Cargo (Minigun)";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		cargoAction[] 		= {"passenger_low01", "passenger_generic01_foldhands"};
		model = "x\12thMEU\addons\Dingo\dingoRCWS_minigun.p3d";
		ace_cargo_space = 3;
		transportSoldier = 2;
		driverCanFire = 0;

		class AnimationSources: AnimationSources
		{
			class barrelRotation {
				source = "ammo";
				weapon = "M134_minigun";
			};
			class zaslehRot {
				source = "ammoRandom";
				weapon = "M134_minigun";
			};
			class zaslehHide
			{
				source = "reload";
				weapon = "M134_minigun";
			};
		};
		class Turrets: Turrets {
			class MainTurret {
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
				canEject = 1;
				canHideGunner = -1;
				canUseScanners = 1;
				castGunnerShadow = 1;
				commanding = 1;
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
				class GunClouds: WeaponCloudsGun {
					access = 0;
					cloudletAccY = 0.4;
					cloudletAlpha = 1;
					cloudletAnimPeriod = 1;
					cloudletColor[] = {1,1,1,0};
					cloudletDuration = 0.3;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 1;
					cloudletGrowUp = 1;
					cloudletMaxYSpeed = 0.8;
					cloudletMinYSpeed = 0.2;
					cloudletShape = "cloudletClouds";
					cloudletSize = 1;
					deltaT = 0;
					initT = 0;
					interval = 0.05;
					size = 3;
					sourceSize = 0.5;
					class Table {};
					timeToLive = 0;
				};
				gunEnd = "chamber";
				class GunFire: WeaponFireGun {
					access = 0;
					cloudletAccY = 0;
					cloudletAlpha = 1;
					cloudletAnimPeriod = 1;
					cloudletColor[] = {1,1,1,0};
					cloudletDuration = 0.2;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 0.5;
					cloudletGrowUp = 0.2;
					cloudletMaxYSpeed = 100;
					cloudletMinYSpeed = -100;
					cloudletShape = "cloudletFire";
					cloudletSize = 1;
					deltaT = -3000;
					initT = 4500;
					interval = 0.01;
					size = 3;
					sourceSize = 0.5;
					class Table {};
					timeToLive = 0;
				};
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
				gunnerName = "RCWS Gunner";
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
				LODTurnedIn = -1;
				LODTurnedOut = -1;
				magazines[] = {"5000Rnd_762x51_Yellow_Belt"};
				maxCamElev = 90;
				maxElev = 60;
				maxHorizontalRotSpeed = 1.2;
				maxOutElev = 20;
				maxOutTurn = 60;
				maxTurn = 360;
				maxVerticalRotSpeed = 1.2;
				memoryPointGun = "muzzle";
				memoryPointGunnerOptics = "PIP0_dir";
				memoryPointGunnerOutOptics = "";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				memoryPointsGetInGunnerPrecise = "";
				class MGunClouds: WeaponCloudsMGun {
					access = 0;
					cloudletAccY = 0;
					cloudletAlpha = 0.3;
					cloudletAnimPeriod = 1;
					cloudletColor[] = {1,1,1,0};
					cloudletDuration = 0.05;
					cloudletFadeIn = 0;
					cloudletFadeOut = 0.1;
					cloudletGrowUp = 0.05;
					cloudletMaxYSpeed = 100;
					cloudletMinYSpeed = -100;
					cloudletShape = "cloudletClouds";
					cloudletSize = 1;
					deltaT = 0;
					initT = 0;
					interval = 0.02;
					size = 0.3;
					sourceSize = 0.02;
					class Table {};
					timeToLive = 0;
				};
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
				soundElevation[] = {"",0.00316228,1};
				soundServo[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",0.177828,1,10};
				soundServoVertical[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",0.177828,1,10};
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
				turretInfoType = "RscOptics_crows";
				class Turrets {};
				class TurretSpec {
					showHeadPhones = 0;
				};
				usePip = 1;
				class ViewGunner {
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
				};
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
				weapons[] = {"M134_minigun"};
			};
		};
		class RenderTargets
		{
			class Gunner_display
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="PIP0_pos";
					pointDirection="PIP0_dir";
					renderVisionMode=2;
					renderQuality=2;
					fov=0.34999999;
					turret[]={0};
				};
				BBoxes[]=
				{
					"PIP_0_TL",
					"PIP_0_TR",
					"PIP_0_BL",
					"PIP_0_BR"
				};
			};
		};
	};
	class SMT_DingoRCWS_autocannon: SMT_DingoRCWS_minigun {
		displayName = "M18-C3 IMV Cargo (Autocannon)";
		class Turrets: Turrets {
			class MainTurret {
				body = "mainTurret";
				gun = "mainGun";
				gunBeg = "muzzle";
				gunEnd = "chamber";
				gunnerName = "$STR_POSITION_GUNNER";
				class HitPoints: HitPoints {};
				inGunnerMayFire = 1;
				initCamElev = 0;
				initElev = 0;
				initOutElev = 0;
				initOutTurn = 0;
				initTurn = 0;
				magazines[] = {"200Rnd_127x99_mag_Tracer_Red","200Rnd_127x99_mag_Tracer_Red"};
				maxCamElev = 90;
				maxElev = 60;
				maxHorizontalRotSpeed = 1.2;
				maxOutElev = 20;
				maxOutTurn = 60;
				maxTurn = 360;
				minCamElev = -90;
				minElev = -25;
				minOutElev = -4;
				minOutTurn = -60;
				minTurn = -360;
				weapons[] = {"HMG_127"};
			};
		};
	};
	class SMT_DingoTroop: SMT_DingoHull
	{
    	editorCategory="ED_SMT_Faction";
    	editorSubcategory="EDS_SMT_faction_Dingo";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage=1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;	
		displayName="M18-T IMV Troop";
		model = "x\12thMEU\addons\Dingo\DingoTroop.p3d";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		transportMaxBackpacks 	= 5; /// just some backpacks fit the trunk by default
		transportSoldier 		= 10; /// number of cargo except driver
		textureList[]=
		{
			"Dingo_Camo_standard", 0.2,
			"Dingo_Camo_winter",0.2,
			"Dingo_Camo_forest",0.2,
			"Dingo_Camo_TCP",0.2,
			"Dingo_Camo_OPTRE",0.2,
			"Dingo_Camo_Black",0.2
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass			= "B_Parachute_02_F";	// Type of parachute used when dropped in air. When empty then parachute is not used.
				parachuteHeightLimit	= 40;				// Minimal height above terrain when parachute is used.
				canBeTransported		= 1;				// 0 (false) / 1 (true)

				dimensions[]			= { "BBox_1_1_pos", "BBox_1_2_pos" };	// Memory-point-based override of automatic bounding box
				// or
				// dimensions[]			= { { 0,0,0 }, { 3,2,1.5 } };			// alternatively, positions in model space (since 2.08)

				rotation = -90;								// (optional) Defines in which direction the vehicle gets rotated when its loaded into ViV cargo and will only fit when rotated
													// Only -90 and 90 are supported. Since v2.08
			};
		};
	};
	/*class SMT_DingoRCWS_minigun_troop:SMT_DingoRCWS_minigun{
		displayName="M18-T2 IMV Troop (Minigun)";
		model = "x\12thMEU\addons\Dingo\DingoRCWSTroop_minigun.p3d";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		transportMaxBackpacks 	= 5; /// just some backpacks fit the trunk by default
		transportSoldier 		= 10; /// number of cargo except driver
	};*/
	class SMT_DingoMed: SMT_DingoHull
	{
    	editorCategory="ED_SMT_Faction";
    	editorSubcategory="EDS_SMT_faction_Dingo";
		side	= 1; 			/// civilian car should be on civilian side
		faction	= "BLU_F";		/// and with civilian faction
		forceInGarage=1;
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;	
		displayName="M18-M IMV Medivac";
		model = "x\12thMEU\addons\Dingo\DingoMed.p3d";
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		transportMaxBackpacks 	= 10; /// just some backpacks fit the trunk by default
		transportSoldier 		= 4; /// number of cargo except driver
		textureList[]=
		{
			"Dingo_Camo_standard", 0.2,
			"Dingo_Camo_winter",0.2,
			"Dingo_Camo_forest",0.2,
			"Dingo_Camo_TCP",0.2,
			"Dingo_Camo_OPTRE",0.2,
			"Dingo_Camo_Black",0.2
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass			= "B_Parachute_02_F";	// Type of parachute used when dropped in air. When empty then parachute is not used.
				parachuteHeightLimit	= 40;				// Minimal height above terrain when parachute is used.
				canBeTransported		= 1;				// 0 (false) / 1 (true)

				dimensions[]			= { "BBox_1_1_pos", "BBox_1_2_pos" };	// Memory-point-based override of automatic bounding box
				// or
				// dimensions[]			= { { 0,0,0 }, { 3,2,1.5 } };			// alternatively, positions in model space (since 2.08)

				rotation = -90;								// (optional) Defines in which direction the vehicle gets rotated when its loaded into ViV cargo and will only fit when rotated
													// Only -90 and 90 are supported. Since v2.08
			};
		};
	};
};