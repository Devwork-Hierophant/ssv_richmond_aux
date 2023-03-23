params ["_vehicle"];

[
    {
        private _vehicle = (_this select 0);

        private _cam = "camera" camCreate (position _vehicle);

        _vehicle setVariable ["ssv_aux_ship_camera", _cam, true];

        _cam camSetFocus [50, 1];

        _cam CamSetTarget _vehicle;
        _cam CamCommit 0;
        _cam switchCamera "EXTERNAL";
        
        private _cameraCoords = [( configFile >> "cfgVehicles" >> (typeOf _vehicle) ), "cameraCoords", []] call BIS_fnc_returnConfigEntry;

        _cam attachTo [_vehicle, _cameraCoords];

        showCinemaBorder false;
        // cameraEffectEnableHUD true;

        // showHUD [
        //     false, // scriptedHUD
        //     true, // info
        //     true, // radar
        //     true, // compass
        //     true, // direction
        //     false, // menu
        //     false, // group
        //     false, // cursors
        //     true, // panels
        //     false, // kills
        //     true  // showIcon3D
        // ];

        // doesn't work
    },
    [_vehicle],
    0.5
] call CBA_fnc_waitAndExecute;