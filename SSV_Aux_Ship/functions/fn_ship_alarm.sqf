params ["_vehicle"];

while {alive _vehicle} do {
    _vehicle engineOn false;
    [_vehicle, "SSV_Aux_Ship_Alarm", true] call SSV_Aux_fnc_playSound;
    uiSleep 13.512; // how long the sound is
};