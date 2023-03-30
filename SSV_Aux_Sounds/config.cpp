class CfgPatches
{
	class SSV_Aux_Sounds
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
		name = "SSV Aux - Sounds";
		author = "SSV";
	};
};

class CfgFunctions 
{
	
    class SSV_Aux
    {
		
        class functions 
        {
			
            class playSound 
            {
                file = "\SSV_Aux_Sounds\functions\fn_playSound.sqf";
            };
			
        };
		
    };
	
};

class CfgSounds 
{
	sounds[] = {};
	class SSV_Aux_Ship_Alarm 
	{
		name = "SSV_Aux_Ship_Alarm";
		maxDistance = 3500;
		sound[] = {"\SSV_Aux_Sounds\sounds\ship_alarm.ogg", 3000, 1.0, 100};
		titles[] = {0, ""};
	};
	class SSV_Aux_Ship_Explosion
	{
		name = "SSV_Aux_Ship_Explosion";
		maxDistance = 5500;
		sound[] = {"\SSV_Aux_Sounds\sounds\ship_explosion.ogg", 5000, 1.0, 100};
		titles[] = {0, ""};
	};
};