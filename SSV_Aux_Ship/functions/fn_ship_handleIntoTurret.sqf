params ["_vehicle", "_unit", "_turret"];

switch (_turret) do 
{
    case 0: {[(_vehicle getVariable "ssv_aux_ship_turret_1"), _unit] spawn SSV_Aux_fnc_ship_moveIntoTurret};
    case 1: {[(_vehicle getVariable "ssv_aux_ship_turret_2"), _unit] spawn SSV_Aux_fnc_ship_moveIntoTurret};

    case -1: 
    {
        private _cam = ( _vehicle getVariable ["ssv_aux_ship_camera", objNull] );

        // objNull remoteControl driver _vehicle;

        // _unit switchCamera "internal";

        _unit moveInAny (_vehicle getVariable ["ssv_aux_ship", objNull]);

        if (_cam isEqualTo objNull) exitWith {};

        _cam cameraEffect ["terminate","back"];
        camDestroy _cam;
    };
};