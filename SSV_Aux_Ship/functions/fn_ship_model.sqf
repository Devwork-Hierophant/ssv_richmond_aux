params ["_vehicle", "_shipType"];

private _ship = _shipType createVehicle [0,0,0];

_ship attachTo [_vehicle,[0,0,-4]];

_ship