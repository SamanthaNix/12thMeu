class CfgPatches {
  class 12th_items {
    units[] = {};
    weapons[] = {};           // No specific weapons defined in this config
    ammo[] = {};              // No specific ammo defined in this config
    magazines[] = {};
    requiredVersion = 0.1;    // Minimum required version of the game
    requiredAddons[] = {};
  };
};


class CfgFunctions{
    class SMT
    {
        tag = "SMT";
        class Misc
        {
            class LoadIntoNearestVehicle
            {
                description = "Misc - Load object into nearest compatible vehicle cargo";
                file = "x\12thMEU\addons\functions\fn_loadIntoNearestVehicle.sqf";
            };
        };
    };
};

class CfgVehicles{
    class ThingX;
    class UserActions;

    class Items_base_F : ThingX
    {
        class UserActions : UserActions
        {
            class SMT_LoadIntoNearestVehicle
            {
                displayName = "Load into Vehicle";
                displayNameDefault = "Load into Vehicle";
                textToolTip = "Load this pallet into the nearest compatible vehicle";
                position = "";
                showWindow = 0;
                radius = 5;
                priority = 3;
                onlyForPlayer = 1;
                condition = "(vehicle player == player) AND (isNull (isVehicleCargo this)) AND (({vehicleCargoEnabled _x} count (nearestObjects [this, [""Car"", ""Plane"", ""Helicopter""], 25])) > 0)";
                statement = "[this] call SMT_fnc_LoadIntoNearestVehicle;";
            }; 
        };
    };

    class ReammoBox_F : ThingX
    {
        class UserActions : UserActions
        {
            class SMT_LoadIntoNearestVehicle
            {
                displayName = "Load into Vehicle";
                displayNameDefault = "Load into Vehicle";
                textToolTip = "Load this pallet into the nearest compatible vehicle";
                position = "";
                showWindow = 0;
                radius = 5;
                priority = 3;
                onlyForPlayer = 1;
                condition = "(vehicle player == player) AND (isNull (isVehicleCargo this)) AND (({vehicleCargoEnabled _x} count (nearestObjects [this, [""Car"", ""Plane"", ""Helicopter""], 25])) > 0)";
                statement = "[this] call SMT_fnc_LoadIntoNearestVehicle;";
            }; 
        };
    };
};
