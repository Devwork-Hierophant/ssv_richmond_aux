addMissionEventHandler ["HandleChatMessage", 
{
	params ["_channel", "_owner", "_from", "_text", "_person", "_name", "_strID", "_forcedDisplay", "_isPlayerMessage", "_sentenceType", "_chatMessageType"];
    if ("/me" in _text) then {
        private _textTrimmed = _text select [4]; // cut out the /me text
        [_person, _textTrimmed, 5] remoteExec ["SSV_Aux_fnc_chat_text"];
        true
    };
}];