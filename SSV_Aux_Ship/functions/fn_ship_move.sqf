params ["_vehicle"];

_vehicle setVelocity [0,0,0];
_vehicle engineOn false;

while {alive _vehicle} do {

	if (_vehicle getVariable ["ssv_aux_ship_move", false]) then
	{

		private _vel = velocity _vehicle; 
		private _dir = direction _vehicle; 
		private _speed = 25;
		private _desiredSpeed = 100;


		if (speed _vehicle < _desiredSpeed) then { 
	
			private _velocity = [ 
				(sin _dir * _speed), 
				(cos _dir * _speed), 
				(_vel select 2) 
			];
			
			_vehicle setVelocity _velocity;
			
		};
		
		uiSleep 3;

	};

	if (_vehicle getVariable ["ssv_aux_ship_down", false]) then
	{

		private _vel = velocity _vehicle;
		private _dir = direction _vehicle;
		private _speed = 25;
	
		private _velocity = [ 
			(sin _dir * _speed),
			(cos _dir * _speed),
			-15
		];
		
		_vehicle setVelocity _velocity;
			
		uiSleep 1;

	};

};