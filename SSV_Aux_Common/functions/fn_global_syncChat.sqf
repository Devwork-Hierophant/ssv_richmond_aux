/*
	Purpose: Puts message in system chat, globally if desired

	Made by: Silence

    Arguments:
    _message	<STRING>
    _global	    <BOOL>
	
	Example:
	[ "This message was sent from fn_global_syncChat!" ] call SSV_Aux_fnc_global_syncChat;
*/

params ["_message", ["_global", true]];

if (_global) exitWith {
    [_message] remoteExec ["systemChat"];
};

systemChat _message;