class CfgPatches
{
	class SSV_Aux_Props
	{
		units[] =
		{
			"Land_Tablet_01_F",
			"SSV_Prop_SmallBox",
			"SSV_Prop_LargeBox",
			"SSV_Prop_MedicBox",
			"SSV_Prop_ArmorBox",
			"SSV_Drone_Cargo"
		};
		weapons[] =
		{
			""
		};
		magazines[] = {""};
		requiredVersion = 0.1;
		requiredAddons[] = {"SSV_Aux_Common", "A3_Structures_F_Heli_Items_Electronics"};
		name = "SSV Aux - Props";
		author = "SSV";
	};
};

class cfgVehicleClasses
{
	class SSV_Props
	{
		displayName = "ME Props";
	};
};

class CfgEditorCategories
{
	class SSV_Props
	{
		displayName = "SSV Props"; // Name visible in the list
	};
};

class CfgEditorSubcategories
{
	class SSV_Aux_Drones
	{
		displayName = "Drones";
	};
};

class cfgVehicles
{
	class Thing;
	class SSV_Prop_Base : Thing
	{
		destrType = "DestructNo";
		editorCategory = "SSV_Props";
		vehicleClass="SSV_Props";
	};

	class I_supplyCrate_F;
	class SSV_Prop_Cargo_Base : I_supplyCrate_F
	{
		scope = 0;
		destrType = "DestructNo";
		editorCategory = "SSV_Props";
		vehicleClass="SSV_Props";
		class TransportBackpacks {};
		class TransportItems {};
		class TransportMagazines {};
		class TransportWeapons {};
		// clear items
	};

	class B_UAV_01_F;
	class SSV_Drone_Base : B_UAV_01_F
	{
		scope = 0;
		faction = "MEOP_human";
		editorSubcategory = "SSV_Aux_Drones";
		aileronSensitivity = 0.6; // 0.5 is blackfish default
		elevatorSensitivity = 0.6; // 0.5 is blackfish default
	};

	class SSV_Drone_Cargo : SSV_Drone_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\cargo_drone";
		displayName = "Cargo Drone";
	};

	class Land_Tablet_01_F : SSV_Prop_Base
	{ // override
		scope = 2;
		scopeCurator = 2;
		editorCategory = "SSV_Props";
		vehicleClass="SSV_Props";
		model = "SSV_Aux_Props\data_pad";
		displayName = "Data Pad";
	};
	class SSV_Prop_MedicArm : SSV_Prop_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\medic_arm";
		displayName = "Surgical Arm";
	};
	class SSV_Prop_SmallBox : SSV_Prop_Cargo_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\small_box";
		displayName = "Small Storage Box";
	};
	class SSV_Prop_LargeBox : SSV_Prop_Cargo_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\box";
		displayName = "Large Storage Box";
	};
	class SSV_Prop_MedicBox : SSV_Prop_Cargo_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\medic_box";
		displayName = "Medical Box";
	};
	class SSV_Prop_ArmorBox : SSV_Prop_Cargo_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\armor_box";
		displayName = "Armor Box";
	};
};