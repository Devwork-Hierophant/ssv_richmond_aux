params ["_vehicle", "_unit"];

private _cam = ( _vehicle getVariable ["ssv_aux_ship_camera", objNull] );

if (_cam isEqualTo objNull) exitWith {false};

_cam cameraEffect ["terminate","back"];
camDestroy _cam;

_unit switchCamera "Internal";

true