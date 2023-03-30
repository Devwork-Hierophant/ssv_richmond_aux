class CfgPatches
{
	class SSV_Aux_Ship
	{
		units[] =
		{
			"SSV_Aux_Izmail",
			"SSV_Aux_Kilimanjaro",
			"SSV_Aux_Alamo"
		};
		weapons[] =
		{
			""
		};
		magazines[] = {""};
		requiredVersion = 0.1;
		requiredAddons[] = {"SSV_Aux_Common"};
		name = "SSV Aux - Ship";
		author = "SSV";
	};
};

class CfgFunctions 
{
	
    class SSV_Aux
    {
		
        class functions
        {
			
            class ship_alarm
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_alarm.sqf";
            };

            class ship_camera_clear
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_camera_clear.sqf";
            };

            class ship_camera
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_camera.sqf";
            };

            class ship_destroy
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_destroy.sqf";
            };
			
            class ship_handleIntoTurret
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_handleIntoTurret.sqf";
            };

            class ship_init
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_init.sqf";
            };

            class ship_model 
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_model.sqf";
            };

            class ship_move
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_move.sqf";
            };

            class ship_moveIntoTurret
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_moveIntoTurret.sqf";
            };
			
            class ship_turrets 
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_turrets.sqf";
            };
			
        };
		
    };
	
};

class CfgEditorSubcategories
{
	class SSV_Aux_Frigate
	{
		displayName = "Frigates";
	};
	class SSV_Aux_Dreadnought
	{
		displayName = "Dreadnoughts";
	};
};

class cfgAmmo
{
	class DemoCharge_Remote_Ammo;

	class SSV_Aux_Ship_Explode : DemoCharge_Remote_Ammo
	{
		scope = 1;
		craterEffects = "HeavyBombCrater";
		craterWaterEffects = "ImpactEffectsWater";
		effectsFire = "CannonFire";
		effectsMissile = "CruiseMissile";
		effectsMissileInit = "RocketBackEffectsRPG";
		effectsSmoke = "SmokeShellWhite";
		explosionEffects = "HeavyBombExplosion";
		explosionDir = "explosionDir";
		explosionAngle = 60;
		explosionEffectsDir = "explosionDir";
		explosionPos = "explosionPos";
		explosionSoundEffect = "DefaultExplosion";
		explosionType = "explosive";
	};
};

class cfgVehicles
{
	class B_T_VTOL_01_armed_F;
	class B_T_VTOL_01_infantry_F;
	class B_Plane_Fighter_01_F;
	class B_AAA_System_01_F;

	class SSV_Aux_Ship_Base : B_Plane_Fighter_01_F
	{
		author = "SSV";
		aileronSensitivity = 0.45; // 0.5 is blackfish default
		elevatorSensitivity = 0.45; // 0.5 is blackfish default
		faction = "MEOP_human";
		editorSubcategory = "SSV_Aux_Frigate";
		editorPreview = "";
		transportSoldier = 3;
		scope = 0;
		// model = ""; // test
		class Sounds {}; // clear sounds

		class ACE_SelfActions
		{
			class SSV_Aux_Ship_Camera_Enter
			{
				condition = "alive _target";
				displayName = "Enter Camera";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[_target] call SSV_Aux_fnc_ship_camera";
			};
			class SSV_Aux_Ship_Camera_Leave
			{
				condition = "alive _target";
				displayName = "Leave Camera";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[(_this select 0), _player, -2] call SSV_Aux_fnc_ship_handleIntoTurret";
			};
			class SSV_Aux_Ship_Stop
			{
				condition = "alive _target";
				displayName = "Stop Ship (Instant)";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "_target enableSimulation false";
			};
			class SSV_Aux_Ship_Start
			{
				condition = "alive _target";
				displayName = "Start Ship (Instant)";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "_target enableSimulation true";
			};
			class SSV_Aux_Ship_Impulse_Stop
			{
				condition = "alive _target";
				displayName = "Stop Ship Impulse";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "_target setVariable [""ssv_aux_ship_move"", false]";
			};
			class SSV_Aux_Ship_Impulse_Start
			{
				condition = "alive _target";
				displayName = "Start Ship Impulse";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "_target setVariable [""ssv_aux_ship_move"", true]";
			};
			class SSV_Aux_Ship_Impulse_Up
			{
				condition = "alive _target";
				displayName = "Ship Impulse Up";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "_target setPos (_target modelToWorld [0,0,300]); _target setVariable [""ssv_aux_ship_move"", true]";
			};
			class SSV_Aux_Ship_Destruct
			{
				condition = "alive _target";
				displayName = "Trigger Destruct Sequence";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[_target] spawn SSV_Aux_fnc_ship_destroy";
			};
			class SSV_Aux_Ship_Turret_1
			{
				condition = "alive _target && {typeOf _target isEqualTo ""SSV_Aux_Izmail""}";
				displayName = "Left Turret";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[(_this select 0), _player, 0] call SSV_Aux_fnc_ship_handleIntoTurret";
			};
			class SSV_Aux_Ship_Turret_2
			{
				condition = "alive _target && {typeOf _target isEqualTo ""SSV_Aux_Izmail""}";
				displayName = "Right Turret";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[(_this select 0), _player, 1] call SSV_Aux_fnc_ship_handleIntoTurret";
			};
		};
	};

	class SSV_Aux_Turret : B_AAA_System_01_F
	{
		displayName = "Frigate MIS";
		scope = 1;
		class ACE_SelfActions
		{
			class SSV_Aux_Ship_Turret_Return
			{
				condition = "alive _target";
				displayName = "Return To Ship";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[(_this select 0), _player, -1] call SSV_Aux_fnc_ship_handleIntoTurret; [(_target getVariable ""ssv_aux_ship"")] call SSV_Aux_fnc_ship_camera";
			};
		};
	};

	class SSV_Aux_Izmail : SSV_Aux_Ship_Base
	{
		displayName = "Izmail-Class Frigate";
		maxSpeed = 150;
		stallSpeed = 0;
		cameraCoords[] = {-25,-120,20};
		turretCount = 2;
		scope = 2;
		class Sounds {}; // clear sounds
		// hiddenSelectionsTextures[] = {"", "", "", "", ""}; // clear textures
	};

	class SSV_Aux_Kilimanjaro : SSV_Aux_Ship_Base
	{
		author = "SSV";
		displayName = "Kilimanjaro-Class Dreadnought";
		maxSpeed = 150;
		stallSpeed = 0;
		turretCount = 0;
		cameraCoords[] = {-60,-250,50};
		aileronSensitivity = 0.4; // 0.5 is blackfish default
		elevatorSensitivity = 0.4; // 0.5 is blackfish default
		editorSubcategory = "SSV_Aux_Dreadnought";
		transportSoldier = 6;
		scope = 2;
	};

	class SSV_Aux_Alamo : SSV_Aux_Izmail
	{
		author = "SSV";
		displayName = "Alamo-Class Frigate";
		turretCount = 0;
	};
};

class Extended_Init_EventHandlers 
{
	class SSV_Aux_Izmail
	{
		class SSV_Aux_Ship_Init
		{
			// init = "[(_this select 0), ""Land_MEOP_build_Ship_Izmail""] call SSV_Aux_fnc_ship_init";
			init = "[(_this select 0), ""Land_BellTower_02_V1_F""] call SSV_Aux_fnc_ship_init"; // debug purposes
		};
	};
	class SSV_Aux_Kilimanjaro
	{
		class SSV_Aux_Ship_Init
		{
			init = "[(_this select 0), ""MEOP_st_Al_Kili_Dread""] call SSV_Aux_fnc_ship_init";
		};
	};
	class SSV_Aux_Alamo
	{
		class SSV_Aux_Ship_Init
		{
			init = "[(_this select 0), ""MEOP_st_Al_Alamo_Frig_byEuderion""] call SSV_Aux_fnc_ship_init";
		};
	};
};