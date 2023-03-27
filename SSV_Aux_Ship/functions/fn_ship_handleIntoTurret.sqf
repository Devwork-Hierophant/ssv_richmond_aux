params ["_vehicle", "_unit", "_turret"];

switch (_turret) do 
{
    case 0: 
    {
        [_vehicle, _unit] call SSV_Aux_fnc_ship_camera_clear; 

        [(_vehicle getVariable "ssv_aux_ship_turret_1"), _unit] spawn SSV_Aux_fnc_ship_moveIntoTurret;
    };

    case 1: 
    {
        [_vehicle, _unit] call SSV_Aux_fnc_ship_camera_clear; 
        
        [(_vehicle getVariable "ssv_aux_ship_turret_2"), _unit] spawn SSV_Aux_fnc_ship_moveIntoTurret;
    };

    case -1: 
    {
        private _cam = ( _vehicle getVariable ["ssv_aux_ship_camera", objNull] );

        _unit moveInAny (_vehicle getVariable ["ssv_aux_ship", objNull]);
    };

    case -2:
    {
        [_vehicle, _unit] call SSV_Aux_fnc_ship_camera_clear;
    };
};