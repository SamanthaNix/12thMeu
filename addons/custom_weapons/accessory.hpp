class ACE_optic_LRPS_2D;
class ItemCore;
class InventoryMuzzleItem_Base_F;
class InventoryItem_Base_F;
class InventoryOpticsItem_Base_F;
class OPTRE_SRS99C_Scope;

class PrototypeOptics: ACE_optic_LRPS_2D
{
	scope = 2;
	author = "SamanthaNix";
	displayName = "[12th] Tri-Sight Prototype Optics";
	descriptionShort = "Tri-sight developed in conjunction with the prototype Laser";
	picture="\x\12thMEU\addons\Custom_Weapons\data\SightPreview.paa";
	model = "\x\12thMEU\addons\Custom_Weapons\data\PrototypeScope.p3d";
/* 	class ItemInfo: InventoryOpticsItem_Base_F
	{
		mass = 2;
		opticType = 1;
		optics = 1;
		modelOptics = "x\12thMEU\addons\Custom_Weapons\data\PrototypeScope.p3d";
		class OpticsModes
		{
			class PrototypeScope
			{
				ACE_ScopeAdjust_Horizontal[] = {-8,8};
				ACE_ScopeAdjust_HorizontalIncrement = 0.1;
				ACE_ScopeAdjust_Vertical[] = {0,27};
				ACE_ScopeAdjust_VerticalIncrement = 0.1;
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.0555;			
				opticsZoomMax = 1;
				opticsZoomInit = 0.5;
				discreteinitIndex = 0;
				discreteDistance[] = {100,300,400,500,600,700,800,900,1000,1500,2000};
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 10000;
				discreteFov[] = {0.1,0.01};
				modelOptics[] = {"x\12thMEU\addons\Custom_Weapons\data\Scope_2x.p3d"};
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal","NVG","Ti"};
				thermalMode[]={1,0};
			};
		};
	};
	intertia = 0.1; */
};
class PrototypeOpticsV2: OPTRE_SRS99C_Scope
{
	mass=16;
	scope = 2;
	author = "SamanthaNix";
	displayName = "[12th] Tri-Sight Prototype Optics V2";
	descriptionShort = "Tri-sight developed in conjunction with the prototype Laser";
	picture="\x\12thMEU\addons\Custom_Weapons\data\SightPreview.paa";
	model = "\x\12thMEU\addons\Custom_Weapons\data\PrototypeScope.p3d";
};

class optic_DMS {
	class ItemInfo;
};
class twelfth_G82_sight : optic_DMS {
	model = "x\12thMEU\addons\custom_weapons\G82\G82_Scope.p3d";
	author = "Rex";
	scope = 2;
	scopeArsenal = 2;
	DisplayName = "[12th] G82 Optic";
	baseWeapon = "twelfth_G82_sight";
	class ItemInfo : ItemInfo
	{	
	class OpticsModes
		{
			class EVOSD
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsZoomMin = 0.083333336;
				opticsZoomMax = 0.25;
				opticsZoomInit = 0.25;
				discreteDistance[] = {100,};
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1200;
				discreteFOV[] = {0.25,0.125,0.083333336};
				discreteInitIndex = 0;
				modelOptics[] = {"\A3\Weapons_F_EPA\acc\reticle_marksman_F","\A3\Weapons_F_EPA\acc\reticle_marksman_z_F"};
				memoryPointCamera = "opticView";
				visionMode[] = {};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
			};
		};
	};
};
class optic_tws;
class XR704_Scope:optic_tws{
	model = "x\12thMEU\addons\custom_weapons\XR-704\XR_704_Scope.p3d";
	author = "Sammy";
	scope = 2;
	scopeArsenal = 2;
	DisplayName = "XR-704 Optic";
	baseWeapon = "XR704_Scope";
};