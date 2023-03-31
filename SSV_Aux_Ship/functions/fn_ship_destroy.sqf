params ["_vehicle"];

if !(isServer) exitWith {};

[_vehicle] spawn SSV_Aux_fnc_ship_alarm;

_vehicle setVariable ["ssv_aux_ship_move", false];

_vehicle setVariable ["ssv_aux_ship_down", true];

_vehicle setDamage 0.1;

_vehicle allowDamage false;

// private _particleFire = "test_EmptyObjectForFireBig" createVehicle [0,0,0];
// private _particleSmoke = "test_EmptyObjectForSmoke" createVehicle [0,0,0];

// _particleFire setPosATL getPosATL _vehicle;
// _particleFire attachTo [_vehicle, [0, 5, 0]];

// _particleSmoke setPosATL getPosATL _vehicle;
// _particleSmoke attachTo [_vehicle, [0, 5, 0]];

for "_i" from 1 to 10 do
{
    _vehicle setDamage ( (damage _vehicle) + 0.02 );

    private _bomb = selectRandom ["Bomb_04_F", "Bomb_03_F"] createVehicle [0,0,0];
    _bomb setPosATL (_vehicle modelToWorld [0, 10, 5]);
    _bomb setDir getDir _vehicle;
    _bomb setDamage 1;
    _bomb setVelocity [0,0,0];

    uiSleep 1;
};

waitUntil {(getPosATL _vehicle) select 2 <= 100};

// for "_u" from 1 to 5 do
// {
// };

private _soundObject = "#particlesource" createVehicle [0,0,0];
_soundObject setPosATL getPosATL _vehicle;
_soundObject allowDamage false;
_soundObject enableSimulation false;

[_vehicle] remoteExec ["SSV_Aux_fnc_ship_delete", _vehicle];

private _bomb = "SSV_Aux_Ship_Explode" createVehicle [0,0,0];
_bomb setPosATL (_soundObject modelToWorld [0, -5, -3]);
// _bomb setDir getDir _vehicle;
_bomb setDamage 1;

// deleteVehicle _particleFire;
// deleteVehicle _particleSmoke;

private _vehiclePos = getPosATL _soundObject;

// [_vehicle] call SSV_Aux_fnc_ship_delete;

[_soundObject, "SSV_Aux_Ship_Explosion", true] call SSV_Aux_fnc_playSound;

for "_w" from 1 to 100 do
{
    private _debris = selectRandom ["Land_HistoricalPlaneDebris_03_F", "Land_HistoricalPlaneDebris_01_F", "Land_HistoricalPlaneWreck_02_wing_left_F", "Land_HistoricalPlaneDebris_04_F"] createVehicle [0,0,0];
    _debris setPosATL _vehiclePos;
    _debris setPosATL (_debris modelToWorld [random 10, random 10, random 10]);
    _debris setDir random 90;
};