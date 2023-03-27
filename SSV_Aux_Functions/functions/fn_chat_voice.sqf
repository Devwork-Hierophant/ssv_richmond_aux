/*
	Purpose: Plays sound

	Made by: Silence

    Arguments:
    _object	<OBJECT>
	_sound	<STRING>
	_global	<BOOL>
	
	Example:
	[ player, "", true ] call SSV_Aux_fnc_chat_voice;

	// only use sounds in cfgSounds please
*/

params ["_object", "_sound", "_global"];

if (is3DEN) exitWith {};

// diag_log format ["Sound playing is %1", _sound];

if (_global) exitWith {
	private _maxDistance = [(configFile >> "cfgSounds" >> _sound), "maxDistance", 40] call BIS_fnc_returnConfigEntry;
	[ _object, [_sound, _maxDistance, 1] ] remoteExec ["say"];
};

_object say _sound;