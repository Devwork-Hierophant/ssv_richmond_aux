class CfgPatches
{
	class SSV_Aux_Markers
	{
		units[] = {""};
		weapons[] = {""};
		magazines[] = {""};
		requiredVersion = 0.1;
		requiredAddons[] = {"SSV_Aux_Common"};
		name = "SSV Aux - Markers";
		author = "SSV";
	};
};

class CfgMarkerClasses
{
	class SSV_Markers
	{
		displayName="ME Markers";
	};
};

class cfgMarkers
{
	class Flag;
	class SSV_Marker_Alliance: Flag
	{
		scope = 1; //Accessibility 1=public, 0=private
		name = "Systems Alliance";
		icon = "\SSV_Aux_Markers\textures\alliance_ca.paa";
		texture = "\SSV_Aux_Markers\textures\alliance_ca.paa";
		color[] = {1, 1, 1, 1};
		shadow = 0;
		markerClass = "SSV_Markers";
		side = 2;
		size = 32;
		showEditorMarkerColor = 1; //Whether to show icon color in the editor
	};
	class SSV_Marker_N7: SSV_Marker_Alliance
	{
		name = "Systems Alliance N7";
		icon = "\SSV_Aux_Markers\textures\n7_ca.paa";
		texture = "\SSV_Aux_Markers\textures\n7_ca.paa";
	};
	class SSV_Marker_Cerberus: SSV_Marker_Alliance
	{
		name = "Cerberus";
		icon = "\SSV_Aux_Markers\textures\cerberus_ca.paa";
		texture = "\SSV_Aux_Markers\textures\cerberus_ca.paa";
	};
	class SSV_Marker_Geth: SSV_Marker_Alliance
	{
		name = "Geth";
		icon = "\SSV_Aux_Markers\textures\geth_ca.paa";
		texture = "\SSV_Aux_Markers\textures\geth_ca.paa";
	};
	class SSV_Marker_Reaper: SSV_Marker_Alliance
	{
		name = "Reaper";
		icon = "\SSV_Aux_Markers\textures\reaper_ca.paa";
		texture = "\SSV_Aux_Markers\textures\reaper_ca.paa";
	};
};