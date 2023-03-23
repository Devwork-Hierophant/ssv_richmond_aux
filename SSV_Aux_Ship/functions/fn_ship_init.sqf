params ["_vehicle", "_shipType"];

if (is3DEN) exitWith {};

// _vehicle hideObjectGlobal true;

private _ship = [_vehicle, _shipType] call SSV_Aux_fnc_ship_model;

// _ship setVariable ["ssv_aux_ship", _vehicle, true];

// {
//     if (_x != driver _vehicle) then {
//         _vehicle deleteVehicleCrew _x
//     };
// } forEach crew _vehicle;

// [_vehicle] spawn SSV_Aux_fnc_ship_move;
[_vehicle] call SSV_Aux_fnc_ship_turrets;
// [_vehicle] call SSV_Aux_fnc_ship_camera;

// _ship setPos (_vehicle modelToWorld [0,0,10]);