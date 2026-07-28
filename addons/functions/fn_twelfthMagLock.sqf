params ["_pelican", "_veh", ["_loaded", false]];

switch true do
{
    //--- TODO: Move to individual configs using class and offset array parameter
    case ((_veh isKindOf "TCP_M12A_LAAG_M41_base") OR (_veh isKindOf "TCP_M12A_ALIM_M68A_base") OR (_veh isKindOf "TCP_M12A_ALIM_M68B_base") OR (_veh isKindOf "TCP_M831A_base")):
    {
        _veh attachTo [_pelican, [0, -4.5, -0.5]];
        _loaded = true;
    };

    case (_veh isKindOf "TCP_M12A_unarmed_base"):
    {
        _veh attachTo [_pelican, [0, -4.5, 0.50]];
        _loaded = true;
    };
    case (_veh isKindOf "SMT_DingoHull"):
    {
        _veh attachTo [_pelican, [0, -5, 0]];
        _loaded = true;
    };
};

if (_loaded) then
{
    _pelican setVariable ["OPTRE_Pelican_AttachedToVehiclesEffect", [vehicle player], true];
    titleText ["-------------------------------------------<br/><t color='#ff0000' size='1.5'>VEHICLE LOADED!</t><br/>-------------------------------------------<br/>", "PLAIN DOWN", -1, true, true];
    playSound "FD_Finish_F";
} else
{
    [_pelican, _veh] call compile preprocessFileLineNumbers "OPTRE_FunctionsLibrary\Functions\PelicanMagLiftSystem\fn_PelicanLoadValidate.sqf";
};
