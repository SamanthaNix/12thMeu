class ReconCloaks_H_Hood_oli;
class ReconCloaks_H_SniperHood_mcam;
//Forest camo
class 12th_ReconCloaks_H_Hood_Forest: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Forest)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass = 8;
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
class 12th_ReconCloaks_H_SniperHood_Forest: ReconCloaks_H_SniperHood_mcam{
    author = "Sammy";
    displayName = "[12th] Sniper Hood (Forest)";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_forest_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_forest_CA.paa"};
    class ItemInfo: ItemInfo
    {
        mass = 8;
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
class 12th_ReconCloaks_H_Hood_Winter: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Winter)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass = 8;
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

class 12th_ReconCloaks_H_SniperHood_Winter: ReconCloaks_H_SniperHood_mcam{
    author = "Sammy";
    displayName = "[12th] Sniper Hood (Winter)";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_winter_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_winter_CA.paa"};
    class ItemInfo: ItemInfo
    {
        mass = 8;
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
class 12th_ReconCloaks_H_Hood_Desert: ReconCloaks_H_Hood_oli{
    author = "Sammy";
    displayName = "[12th] Recon Hood (Desert)";
    model = "\ReconCloaks\reconcloaks_characters\Headgear\H_ReconCloak.p3d";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_desert_CO.paa"};
    class ItemInfo: ItemInfo
    {
        mass = 8;
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
class 12th_ReconCloaks_H_SniperHood_Desert: ReconCloaks_H_SniperHood_mcam{
    author = "Sammy";
    displayName = "[12th] Sniper Hood (Desert)";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\x\12thMEU\addons\12th_armor\reconcloaks\H_ReconCloak_desert_CO.paa","\x\12thMEU\addons\12th_armor\reconcloaks\ghillie_leaves_desert_CA.paa"};
    class ItemInfo: ItemInfo
    {
        mass = 8;
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