/*
	 * Loads an object into the nearest compatible vehicle with ViV enabled.
	 *
	 * params:
	 * 0: Cargo object <OBJECT>
	 *
	 * Returns:
	 * <BOOL> true when cargo was loaded, false otherwise.
 */
params ["_cargo"];

if (isNull _cargo) exitWith {
	false
};
if !(isNull (isVehicleCargo _cargo)) exitWith {
	false
};

private _vehicles = nearestObjects [_cargo, ["Car", "Plane", "Helicopter"], 15];
if (_vehicles isEqualTo []) exitWith {
	hint "No nearby vehicle can transport cargo.";
	false
};

private _loaded = false;
private _spaceBlocked = false;
private _vicCount = count _vehicles;

private _i = 0;
// Iterate vehicles using a while loop so we can stop once cargo is loaded.
while { (_i < _vicCount) && !(_loaded) } do {
	private _countVics = _vehicles select _i;
	if (vehicleCargoEnabled _countVics) then {
		private _check = _countVics canVehicleCargo _cargo; // returns [canCarry, hasSpace]
		// switch expects a scalar — switch on true so cases can be boolean expressions
		if (_check isEqualTo [true, true]) then {
			_countVics setVehicleCargo _cargo;
			_loaded = true;
		} else {
			_spaceBlocked = true;
		};
	};
	_i = _i + 1;
};

if (!_loaded) then {
	if (_spaceBlocked) then {
		hint "Vehicle does not have enough free space for cargo.";
	} else {
		hint "Cargo is too large or no nearby vehicle can transport cargo.";
	};
};

_loaded