params ["_unit", "_anim", ["_global", false]];

if (_global) exitWith {
    [_unit, _anim] remoteExec ["switchMove"];
};

_unit switchMove _anim;