params ["_vehicle"];

private _turrets = [( configFile >> "cfgVehicles" >> (typeOf _vehicle) ), "turretCount", 0] call BIS_fnc_returnConfigEntry;

if (_turrets isEqualTo 0) exitWith {};

// turret 1

private _turret_1 = "SSV_Aux_Turret" createVehicle [0,0,0];
createVehicleCrew _turret_1;

_turret_1 attachTo [_vehicle,[-12,0,-3.5]];
[_turret_1, -5, -30] call BIS_fnc_setPitchBank;

// turret 2

private _turret_2 = "SSV_Aux_Turret" createVehicle [0,0,0];
createVehicleCrew _turret_2;

_turret_2 attachTo [_vehicle,[12,0,-3.5]];
[_turret_2, 5, 30] call BIS_fnc_setPitchBank;

// set vars

deleteVehicleCrew _turret_1;
deleteVehicleCrew _turret_2;

_vehicle setVariable ["ssv_aux_ship_turret_1", _turret_1, true];
_vehicle setVariable ["ssv_aux_ship_turret_2", _turret_2, true];

_turret_1 setVariable ["ssv_aux_ship", _vehicle, true];
_turret_2 setVariable ["ssv_aux_ship", _vehicle, true];