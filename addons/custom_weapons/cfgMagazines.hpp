
class CfgMagazines
{
	class Default;

	class CA_Magazine;

	class LLRLaserMag: CA_Magazine 
	{
		mass=50;
		ace_disableRepacking = 1;
		scope = 2;
		displayName = "Liquid Magazine";
		displayNameShort = "[12th] LLR Magazine";
		picture="\x\12thMEU\addons\custom_weapons\data\MagazinePreview_ca.paa";
		ammo = "StandardLiquidLaserAmmo";
		count = 3; 
		initSpeed = 2000; /// standard muzzle speed
		tracersEvery = 1;
		descriptionShort = "Magazine for LLR <br />Rounds: 3"; /// on mouse-over in Inventory
		magazineGroup[]	= {"Liquid_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
	class CompressedLaserMag: CA_Magazine 
	{
		mass=50;
		ace_disableRepacking = 1;
		scope = 2;
		displayName = "Compressed Liquid Magazine";
		displayNameShort = "[12th] C-LLR Mag";
		picture="\x\12thMEU\addons\custom_weapons\data\MagazinePreview_ca.paa";
		ammo = "CompressedLiquidLaserAmmo";
		count = 1; 
		initSpeed = 3000; /// standard muzzle speed
		tracersEvery = 1;
		descriptionShort = "Compressed Mag <br />Rounds: 1"; /// on mouse-over in Inventory
		magazineGroup[]	= {"Liquid_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
};
