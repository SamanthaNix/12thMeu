// see http://community.bistudio.com/wiki/Sound for more details

class CfgSoundShaders
{
	//###################################### SHOTS ######################################
	class PrototypeLaser_01_Base_F_Closure_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }}; // you can use ogg/wss/ogg, ogg will have a small delay before playback (not too good for weapons/explosions)
		volume = 0.4466836;
		range = 5;
	};
 	class PrototypeLaser_01_Base_F_closeShot_SoundShader
	{
		samples[] = { {"x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1} };
		volume = 1.0;
		range = 200;
	};
	class PrototypeLaser_01_Base_F_midShot_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = 0.7943282;
		range = 1800;
		rangeCurve[] = { {0,0.2}, {50,1}, {300,0}, {1800,0} };
	};
	class PrototypeLaser_01_Base_F_distShot_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = 1.0;
		range = 1800;
		rangeCurve[] = { {0,0}, {50,0}, {300,1}, {1800,1} };
	};
 	// ###################################### TAILS ######################################
	/*class PrototypeLaser_01_Base_F_tailInterior_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = "interior";
		range = 500;
		limitation = 0;
	};
	class PrototypeLaser_01_Base_F_tailTrees_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = "(1-interior/1.4)*trees/3";
		range = 1800;
		limitation = 1;
	};
	class PrototypeLaser_01_Base_F_tailForest_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = "(1-interior/1.4)*forest/3";
		range = 1800;
		limitation = 1;
	};
	class PrototypeLaser_01_Base_F_tailMeadows_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = "(1-interior/1.4)*(meadows/2 max sea/2)/3";
		range = 1800;
		limitation = 1;
	};
	class PrototypeLaser_01_Base_F_tailHouses_SoundShader
	{
		samples[] = {{ "x\12thMEU\addons\Custom_Weapons\data\LaserFireSingle.ogg", 1 }};
		volume = "(1-interior/1.4)*houses/3";
		range = 1200;
		limitation = 1;
	};*/
};
