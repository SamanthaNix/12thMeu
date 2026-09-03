
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
	class Commando_20Rnd_65_Mag;
	class twelfth_G82_35Rnd_Mag : Commando_20Rnd_65_Mag {
		mass = 12;
		scope = 2;
		displayName = "35Rnd 6.5 Creedmoor Magazine";
		displayNameShort = "G82 Mag";
		descriptionShort = "35 Round Magazine";
		count = 35;
	};

	class twelfth_G82_35Rnd_Mag_T : Commando_20Rnd_65_Mag {
		mass = 12;
		scope = 2;
		displayName = "35Rnd 6.5 Creedmoor Magazine Tracer";
		displayNameShort = "G82 Mag T";
		descriptionShort = "35 Round Magazine";
		count = 35;
		tracersEvery = 3;
	};
	class 7rnd_408_Mag;
	class 408CT_6Rnd_Mag :7rnd_408_Mag {
		scope = 2;
		mass = 12;
		count = 6;
		DisplayName = "6Rnd .408 Chey Tac";
		displayNameShort = "6Rnd .408 CT";
		descriptionShort = "6 Round Chey Tac";
	};
	class 408CT_6Rnd_Mag_T :408CT_6Rnd_Mag {
		tracersEvery =1;
		DisplayName = "6Rnd .408 Chey Tac Tracer";
		displayNameShort = "6Rnd .408 CT-T";
		descriptionShort = "6 Round Chey Tac Tracer";
	};
};
