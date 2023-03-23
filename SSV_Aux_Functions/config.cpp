class CfgPatches
{
	class SSV_Aux_Functions
	{
		units[] =
		{
			""
		};
		weapons[] =
		{
			""
		};
		magazines[] = {""};
		requiredVersion = 0.1;
		requiredAddons[] = {"SSV_Aux_Common"};
		name = "SSV Aux - Functions";
		author = "SSV";
	};
};

class CfgFunctions 
{
	
    class SSV_Aux
    {
		
        class functions 
        {
			
            class chat_init
            {
                file = "\SSV_Aux_Functions\functions\fn_chat_init.sqf";
            };

            class chat_text 
            {
                file = "\SSV_Aux_Functions\functions\fn_chat_text.sqf";
            };

            class chat_voice
            {
                file = "\SSV_Aux_Functions\functions\fn_chat_voice.sqf";
            };

            class dice_roll 
            {
                file = "\SSV_Aux_Functions\functions\fn_dice_roll.sqf";
            };
			
            class question_add 
            {
                file = "\SSV_Aux_Functions\functions\fn_question_add.sqf";
            };
			
        };
		
    };
	
};

class cfgVehicles 
{
  	class Man;
  	class CAManBase : Man 
	{
		class ACE_SelfActions 
		{
			class ACE_Equipment 
			{
				class SSV_Aux_RollDice 
				{
					displayName = "Roll Dice";
					condition = "alive _player";
					// exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
					statement = "[_player] call SSV_Aux_fnc_dice_roll";
					showDisabled = 0;
					icon = "SSV_Aux_Functions\ui\dice_ca.paa";
				};
				// class SSV_Aux_RPChat
				// {
				// 	displayName = "RP Chat";
				// 	condition = "alive _player";
				// 	// exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
				// 	statement = "[_player, ""Test""] call SSV_Aux_fnc_chat_text";
				// 	showDisabled = 0;
				// 	icon = "SSV_Aux_Functions\ui\chat_ca.paa";
				// };
			};
    	};
		class ACE_Actions
		{
			class SSV_Aux_Questions
			{
				condition = "alive _player";
				displayName = "Questioning";
				distance = 3;
				exceptions[] = {"isNotInside","isNotSitting"};
				icon = "\a3\ui_f\data\IGUI\Cfg\Actions\periscopedepth_on_ca.paa";
				selection = "spine2";
			};
		};
	};
};

class Extended_InitPost_EventHandlers 
{
    class CAManBase 
	{
		class SSV_Aux_Chat_Init 
		{
			init = "call SSV_Aux_fnc_chat_init";
		};
    };
};