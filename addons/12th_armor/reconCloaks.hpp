class ReconCloaks_H_Hood_oli;
class ReconCloaks_H_SniperHood_mcam;
//Forest camo
class twelfth_ReconCloaks_H_Hood_Forest: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Forest)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};
class twelfth_ReconCloaks_H_SniperHood_Forest: ReconCloaks_H_SniperHood_mcam{
    author = "Sammy";
    displayName = "[12th] Sniper Hood (Forest)";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_forest_CA.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_forest_CA.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Camo.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};
//winter camo
class twelfth_ReconCloaks_H_Hood_Winter: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Winter)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};

class twelfth_ReconCloaks_H_SniperHood_Winter: ReconCloaks_H_SniperHood_mcam{
    author = "Sammy";
    displayName = "[12th] Sniper Hood (Winter)";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_winter_CA.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_winter_CA.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Camo.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};
//desert camo
class twelfth_ReconCloaks_H_Hood_Desert: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Desert)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_desert_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_desert_CO.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};
class twelfth_ReconCloaks_H_SniperHood_Desert: ReconCloaks_H_SniperHood_mcam{
    author = "Sammy";
    displayName = "[12th] Sniper Hood (Desert)";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_desert_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_desert_CA.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_desert_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_desert_CA.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Camo.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};

//Black
class twelfth_ReconCloaks_H_Hood_Black: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Black)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\ReconCloaks\reconcloaks_characters\Headgear\Data\H_ReconCloak_blk_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass=40;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\ReconCloaks\reconcloaks_characters\Headgear\Data\H_ReconCloak_blk_CO.paa"};
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
        modelSides[] = {6};
        class HitpointsProtectionInfo{
            class Head {
            hitpointName="HitHead";
            armor=20;
            passThrough=0.1;
            };
        };
    };
};


//NVG recon hoods
class OPTRE_NVGT_C;
class OPTRE_NVG_MVI;

//Forest
class twelfth_ReconCloaks_H_Hood_Down_WHOT_Forest: OPTRE_NVGT_C
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Forest, Down, WHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

class twelfth_ReconCloaks_H_Hood_Down_RHOT_Forest: OPTRE_NVG_MVI
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Forest, Down, RHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

//Desert
class twelfth_ReconCloaks_H_Hood_Down_WHOT_Desert: OPTRE_NVGT_C
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Desert, Down, WHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_Desert_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_Desert_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

class twelfth_ReconCloaks_H_Hood_Down_RHOT_Desert: OPTRE_NVG_MVI
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Desert, Down, RHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_Desert_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_Desert_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

//Winter

class twelfth_ReconCloaks_H_Hood_Down_WHOT_Winter: OPTRE_NVGT_C
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Winter, Down, WHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

class twelfth_ReconCloaks_H_Hood_Down_RHOT_Winter: OPTRE_NVG_MVI
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Forest, Down, RHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

//Black


class twelfth_ReconCloaks_H_Hood_Down_WHOT_Black: OPTRE_NVGT_C
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Black, Down, WHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\ReconCloaks\reconcloaks_characters\Headgear\Data\H_ReconCloak_blk_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\ReconCloaks\reconcloaks_characters\Headgear\Data\H_ReconCloak_blk_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};

class twelfth_ReconCloaks_H_Hood_Down_RHOT_Black: OPTRE_NVG_MVI
{
    author = "OokamiJamie";
    displayName = "Recon Hood (Black, Down, RHOT)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\ReconCloaks\reconcloaks_characters\Headgear\Data\H_ReconCloak_blk_CO.paa"};
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
    picture = "\ReconCloaks\reconcloaks_characters\Headgear\Data\icon\H_ReconCloak_oli_ico_CA.paa";
    class ItemInfo: ItemInfo
    {
        uniformModel = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\ReconCloaks\reconcloaks_characters\Headgear\Data\H_ReconCloak_blk_CO.paa"};
        modelOff = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak_Down.p3d";
        mass= 1;
    };
};