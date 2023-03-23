class CfgPatches
{
	class SSV_Aux_Common
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
		requiredAddons[] = {"A3_Data_F_AoW_Loadorder"};
		name = "SSV Aux - Common";
		author = "SSV";
	};
};

class CfgFunctions 
{
	
    class SSV_Aux
    {
		
        class functions 
        {
			
            class global_syncAnim 
            {
                file = "\SSV_Aux_Common\functions\fn_global_syncAnim.sqf";
            };
			
            class global_syncChat 
            {
                file = "\SSV_Aux_Common\functions\fn_global_syncChat.sqf";
            };
			
        };
		
    };
	
};