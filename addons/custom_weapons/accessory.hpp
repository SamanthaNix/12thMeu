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
	displayName = "Tri-Sight Prototype Optics";
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
	scope = 2;
	author = "SamanthaNix";
	displayName = "Tri-Sight Prototype Optics V2";
	descriptionShort = "Tri-sight developed in conjunction with the prototype Laser";
	picture="\x\12thMEU\addons\Custom_Weapons\data\SightPreview.paa";
	model = "\x\12thMEU\addons\Custom_Weapons\data\PrototypeScope.p3d";
};