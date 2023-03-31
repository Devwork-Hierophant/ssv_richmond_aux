params ["_vehicle"];

// if !(isServer) exitWith {};

// private _ship = _vehicle getVariable ["ssv_aux_ship", objNull];

// private _turret_1 = _vehicle getVariable ["ssv_aux_ship_turret_1", objNull];
// private _turret_2 = _vehicle getVariable ["ssv_aux_ship_turret_2", objNull];

// detach _ship;
// detach (_vehicle getVariable ["ssv_aux_ship_turret_1", objNull]);
// detach (_vehicle getVariable ["ssv_aux_ship_turret_2", objNull]);

// _ship setPosATL [0,0,0];
// (_vehicle getVariable ["ssv_aux_ship_turret_1", objNull]) setPosATL [0,0,0];
// (_vehicle getVariable ["ssv_aux_ship_turret_2", objNull]) setPosATL [0,0,0];

// arma fuckery

// diag_log format ["%1, %2, %3, %4", _vehicle, _ship, _turret_1, _turret_2];

// deleteVehicle _ship;
// deleteVehicle _turret_1;
// deleteVehicle _turret_2;

_vehicle setVariable ["ssv_aux_ship_down", false];

_vehicle setPosATL [0,0,0];

[
    {
        (_this select 0) enableSimulationGlobal false;
    },
    [_vehicle],
    0.1
] call CBA_fnc_waitAndExecute;

// can't actually delete it or arma has a fit for some reason