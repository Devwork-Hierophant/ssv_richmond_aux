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
			
            class ship_camera
            {
                file = "\SSV_Aux_Ship\functions\fn_ship_camera.sqf";
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

class cfgVehicles
{
	class B_T_VTOL_01_armed_F;
	class B_T_VTOL_01_infantry_F;
	class B_Plane_Fighter_01_F;
	class B_AAA_System_01_F;

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
				statement = "[(_this select 0), _player, -1] call SSV_Aux_fnc_ship_handleIntoTurret";
			};
		};
	};

	class SSV_Aux_Izmail : B_Plane_Fighter_01_F
	{
		author = "SSV";
		displayName = "Izmail-Class Frigate";
		maxSpeed = 150;
		stallSpeed = 0;
		cameraCoords[] = {-25,-120,20};
		turretCount = 2;
		aileronSensitivity = 0.45; // 0.5 is blackfish default
		elevatorSensitivity = 0.45; // 0.5 is blackfish default
		faction = "MEOP_human";
		editorSubcategory = "SSV_Aux_Frigate";
		editorPreview = "";
		transportSoldier = 3;
		// model = ""; // test
		class Sounds {}; // clear sounds
		class ACE_SelfActions
		{
			class SSV_Aux_Ship_Camera
			{
				condition = "alive _target";
				displayName = "Swap To Camera";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[_target] call SSV_Aux_fnc_ship_camera";
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
			class SSV_Aux_Ship_Turret_1
			{
				condition = "alive _target";
				displayName = "Left Turret";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[(_this select 0), _player, 0] call SSV_Aux_fnc_ship_handleIntoTurret";
			};
			class SSV_Aux_Ship_Turret_2
			{
				condition = "alive _target";
				displayName = "Right Turret";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[(_this select 0), _player, 1] call SSV_Aux_fnc_ship_handleIntoTurret";
			};
		};
		// hiddenSelectionsTextures[] = {"", "", "", "", ""}; // clear textures
	};
	class SSV_Aux_Kilimanjaro : B_Plane_Fighter_01_F
	{
		author = "SSV";
		displayName = "Kilimanjaro-Class Dreadnought";
		maxSpeed = 150;
		stallSpeed = 0;
		turretCount = 0;
		cameraCoords[] = {-60,-250,50};
		aileronSensitivity = 0.4; // 0.5 is blackfish default
		elevatorSensitivity = 0.4; // 0.5 is blackfish default
		faction = "MEOP_human";
		editorSubcategory = "SSV_Aux_Dreadnought";
		editorPreview = "";
		transportSoldier = 6;
		class Sounds {}; // clear sounds
		class ACE_SelfActions
		{
			class SSV_Aux_Ship_Camera
			{
				condition = "alive _target";
				displayName = "Swap To Camera";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[_target] call SSV_Aux_fnc_ship_camera";
			};
		};
	};
	class SSV_Aux_Alamo : SSV_Aux_Izmail
	{
		author = "SSV";
		displayName = "Alamo-Class Frigate";
		turretCount = 0;
		class Sounds {}; // clear sounds
		// class ACE_SelfActions {}; // clear actions
		class ACE_SelfActions
		{
			class SSV_Aux_Ship_Camera
			{
				condition = "alive _target";
				displayName = "Swap To Camera";
				// icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				statement = "[_target] call SSV_Aux_fnc_ship_camera";
			};
		};
	};
};

class Extended_Init_EventHandlers 
{
	class SSV_Aux_Izmail
	{
		class SSV_Aux_Ship_Init
		{
			init = "[(_this select 0), ""Land_MEOP_build_Ship_Izmail""] call SSV_Aux_fnc_ship_init";
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