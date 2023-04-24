class CfgPatches
{
	class SSV_Aux_Props
	{
		units[] =
		{
			"Land_Tablet_01_F",
			"SSV_Prop_SmallBox",
			"SSV_Prop_SmallBox_Metro",
			"SSV_Prop_LargeBox",
			"SSV_Prop_LargeBox_Metro",
			"SSV_Prop_MedicArm",
			"SSV_Prop_MedicArm_Metro",
			"SSV_Prop_MedicBox",
			"SSV_Prop_ArmorBox",
			"SSV_Prop_Crate",
			"SSV_Prop_Crate_Biohazard",
			"SSV_Prop_Barrel",
			"SSV_Prop_Barrel_Metro",
			"SSV_Prop_Barrel_Biohazard",
			"SSV_Prop_Fridge",
			"SSV_Prop_LabEquipment",
			"SSV_Drone_Cargo",
			"SSV_Drone_Cargo_Metro"
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
		hiddenSelections[] = {"drone_arms", "drone_head"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\cargo_drone\cargo_drone_co.paa", "ssv_aux_props\textures\cargo_drone\cargo_drone_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\cargo_drone\cargo_drone.rvmat", "ssv_aux_props\textures\cargo_drone\cargo_drone.rvmat"};
		displayName = "Cargo Drone";
	};

	class SSV_Drone_Cargo_Metro : SSV_Drone_Cargo
	{
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\cargo_drone\metro\cargo_drone_co.paa", "ssv_aux_props\textures\cargo_drone\metro\cargo_drone_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\cargo_drone\metro\cargo_drone.rvmat", "ssv_aux_props\textures\cargo_drone\metro\cargo_drone.rvmat"};
		displayName = "Cargo Drone (Metropolitan)";
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
		hiddenSelections[] = {"med_arm"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\medic_arm\med_arm_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\medic_arm\med_arm.rvmat"};
		displayName = "Surgical Arm";
	};
	class SSV_Prop_MedicArm_Metro : SSV_Prop_MedicArm
	{
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\medic_arm\metro\med_arm_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\medic_arm\metro\med_arm.rvmat"};
		displayName = "Surgical Arm (Metropolitan)";
	};

	class SSV_Prop_Crate : SSV_Prop_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\crate";
		hiddenSelections[] = {"crate_bottom", "crate_top"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\crate\crate_bottom_co.paa", "ssv_aux_props\textures\crate\crate_top_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\crate\crate_bottom.rvmat", "ssv_aux_props\textures\crate\crate_top.rvmat"};
		displayName = "Crate";
	};
	class SSV_Prop_Crate_Biohazard : SSV_Prop_Crate
	{
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\crate\biohazard\crate_bottom_co.paa", "ssv_aux_props\textures\crate\biohazard\crate_top_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\crate\biohazard\crate_bottom.rvmat", "ssv_aux_props\textures\crate\biohazard\crate_top.rvmat"};
		displayName = "Crate (Biohazard)";
	};

	class SSV_Prop_Barrel : SSV_Prop_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\barrel";
		hiddenSelections[] = {"barrel"};
		hiddenSelectionsTextures[] = {"SSV_Aux_Props\textures\barrel\barrel_co.paa"};
		hiddenSelectionsMaterials[] = {"SSV_Aux_Props\textures\barrel\barrel.rvmat"};
		displayName = "Barrel";
	};
	class SSV_Prop_Barrel_Metro : SSV_Prop_Barrel
	{
		hiddenSelectionsTextures[] = {"SSV_Aux_Props\textures\barrel\metro\barrel_co.paa"};
		hiddenSelectionsMaterials[] = {"SSV_Aux_Props\textures\barrel\metro\barrel.rvmat"};
		displayName = "Barrel (Metropolitan)";
	};
	class SSV_Prop_Barrel_Biohazard : SSV_Prop_Barrel
	{
		hiddenSelectionsTextures[] = {"SSV_Aux_Props\textures\barrel\biohazard\barrel_co.paa"};
		hiddenSelectionsMaterials[] = {"SSV_Aux_Props\textures\barrel\biohazard\barrel.rvmat"};
		displayName = "Barrel (Biohazard)";
	};

	class SSV_Prop_SmallBox : SSV_Prop_Cargo_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\small_box";
		hiddenSelections[] = {"small_box"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\small_box\small_box_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\small_box\small_box.rvmat"};
		displayName = "Small Storage Box";
	};
	class SSV_Prop_SmallBox_Metro : SSV_Prop_SmallBox
	{
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\small_box\metro\small_box_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\small_box\metro\small_box.rvmat"};
		displayName = "Small Storage Box (Metropolitan)";
	};

	class SSV_Prop_LargeBox : SSV_Prop_Cargo_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\box";
		hiddenSelections[] = {"box"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\box\box_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\box\box.rvmat"};
		displayName = "Large Storage Box";
	};
	class SSV_Prop_LargeBox_Metro : SSV_Prop_LargeBox
	{
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\box\metro\box_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\box\metro\box.rvmat"};
		displayName = "Large Storage Box (Metropolitan)";
	};

	class SSV_Prop_Fridge : SSV_Prop_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\fridge";
		hiddenSelections[] = {"cloth", "fridge"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\portable_fridge\cloth_co.paa", "ssv_aux_props\textures\portable_fridge\fridge_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\portable_fridge\cloth.rvmat", "ssv_aux_props\textures\portable_fridge\fridge.rvmat"};
		displayName = "Portable Fridge";
	};

	class SSV_Prop_LabEquipment : SSV_Prop_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "SSV_Aux_Props\lab_equipment";
		hiddenSelections[] = {"lab_equipment"};
		hiddenSelectionsTextures[] = {"ssv_aux_props\textures\lab_equipment\lab_equipment_co.paa"};
		hiddenSelectionsMaterials[] = {"ssv_aux_props\textures\lab_equipment\lab_equipment.rvmat"};
		displayName = "Lab Equipment";
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