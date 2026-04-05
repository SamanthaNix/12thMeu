/*
  ==============================================================================
  config_macros.hpp

  This file contains macro definitions used throughout the config for brevity.
  It helps avoid repetitive code. For instance, using `COMMON_SIGHTS` in multiple
  weapon configs ensures a consistent set of attachments.

  If you add new attachments, simply update the macros here.
  ==============================================================================
*/
// Start Attachment Macros
#define COMMON_SIGHTS {"optic_arco_ak_blk_f", "optic_dms", "optic_aco_grn", "optic_aco", "optic_arco_blk_f", "optic_holosight_blk_f", "optic_mrco", "optic_khs_blk", "optic_hamr", "optic_sos", "optic_lrps", "optic_nightstalker", "optic_erco_blk_f", "optic_ams", "optic_yorris", "optic_ico_01_black_f", "optic_aco_smg", "optic_aco_grn_smg", "optic_holosight_smg_blk_f", "optic_mrd_black", "optic_tws", "optic_nvs", "ace_optic_arco_2d", "ace_optic_arco_pip", "ace_optic_lrps_2d", "ace_optic_lrps_pip", "ace_optic_sos_2d", "ace_optic_sos_pip", "ace_optic_mrco_2d", "ace_optic_hamr_2d", "ace_optic_hamr_pip", "OPTRE_M7_Sight", "OPTRE_HMG38_CarryHandle", "OPTRE_M12_Optic", "OPTRE_M12_Optic_Red", "OPTRE_M12_Optic_Green", "OPTRE_M6C_Scope", "OPTRE_M6G_Scope", "Optre_Recon_Sight", "Optre_Recon_Sight_Red", "Optre_Recon_Sight_Green", "Optre_Recon_Sight_Desert", "Optre_Recon_Sight_UNSC", "Optre_Recon_Sight_Snow", "OPTRE_BR45_Scope", "OPTRE_BR55HB_Scope", "OPTRE_BR55HB_Scope_Grey", "OPTRE_BMR_Scope", "OPTRE_M392_Scope", "OPTRE_M393_Scope", "OPTRE_M393_ACOG", "OPTRE_M393_EOTECH", "OPTRE_SRM_Sight", "OPTRE_SRS99C_Scope", "OPTRE_SRS99_Scope", "OPTRE_M73_SmartLink", "OPTRE_MA5_SmartLink", "OPTRE_MA5C_SmartLink", "OPTRE_MA5_BUIS", "19_UNSC_br_scope", "19_UNSC_evosd", "19_UNSC_evo","MA6_SmartLink","MA6_K_SmartLink","TCP_optic_M11VERO_Blue","TCP_optic_M11VERO","TCP_optic_M27RCO","TCP_optic_M43RCO","TCP_optic_M27RCO_CRS","TCP_optic_M27RCO_CRS_CUP","TCP_optic_M27RCO_CUP","TCP_optic_EVOSD","TCP_optic_M5BSLSV_Blue","TCP_optic_M5BSLSV","TCP_optic_M81ERO_Blue","TCP_optic_M81ERO","TCP_optic_EVOSJ","TCP_optic_EVOSJ1","TCP_optic_M43RCO_CRS","TCP_optic_M43RCO_CRS_CUP","TCP_optic_M43RCO_CUP"}
#define COMMON_BR_SIGHTS {"OPTRE_M7_Sight", "OPTRE_M12_Optic", "OPTRE_M12_Optic_Red", "OPTRE_M12_Optic_Green", "Optre_Recon_Sight", "Optre_Recon_Sight_Red", "Optre_Recon_Sight_Green", "Optre_Recon_Sight_Desert", "Optre_Recon_Sight_UNSC", "Optre_Recon_Sight_Snow", "OPTRE_BR55HB_Scope", "19_UNSC_br_scope", "19_UNSC_evo"}
#define COMMON_RAIL_ATTACHMENTS "TCP_acc_flashlight_M6G","TCP_acc_pointer_lam_M6G","TCP_acc_pointer_lam_M6C2","OPTRE_BMR_Laser","OPTRE_BMR_MEQ_Flashlight","OPTRE_BMR_Vis_Red_Laser","OPTRE_BMR_Flashlight","OPTRE_BMR_Flashlight_Laser","OPTRE_BMR_Flashlight_Vis_Red_Laser", "ACE_acc_pointer_red", "ACE_acc_pointer_green", "ACE_acc_pointer_green_IR", "acc_pointer_IR", "OPTRE_M12_Laser","OPTRE_M12_Flashlight","OPTRE_M12_Vis_Red_Laser","ACE_SPIR","ACE_SPIR_Medium","ACE_SPIR_Narrow","ACE_SPIR_LR","ACE_SPIR_LR_Medium","ACE_SPIR_LR_Narrow"
#define COMMON_LIGHT_BIPOD {"bipod_01_F_blk", "bipod_02_F_blk", "bipod_03_F_blk","TCP_bipod_01"}
#define COMMON_MEDIUM_BIPOD {"bipod_01_F_blk", "bipod_02_F_blk", "bipod_03_F_blk", "dzn_tripod_rifle","TCP_bipod_01"}
#define COMMON_HEAVY_BIPOD {"bipod_01_F_blk", "bipod_02_F_blk", "bipod_03_F_blk", "12th_MG_Tripod"}
// Start Magazine Macros
// Start Rifle Macros
#define COMMON_MA5C_MAGAZINES {"OPTRE_32Rnd_762x51_Mag", "OPTRE_32Rnd_762x51_Mag_Tracer", "OPTRE_32Rnd_762x51_Mag_UW" }
#define COMMON_LMG_MAGAZINES {"twelfth_100Rnd_762x51_Box", "twelfth_100Rnd_762x51_Box_T", "twelfth_200Rnd_762x51_Box", "twelfth_200Rnd_762x51_Box_T", "OPTRE_32Rnd_762x51_Mag", "OPTRE_32Rnd_762x51_Mag_Tracer_Yellow", "OPTRE_32Rnd_762x51_Mag_Tracer", "OPTRE_32Rnd_762x51_Mag_UW", "twelfth_M739_SAW_200rnd_Box", "twelfth_M739_SAW_200rnd_Drum"}
#define COMMON_BR_MAGAZINES {"OPTRE_36Rnd_95x40_Mag", "OPTRE_36Rnd_95x40_Mag_Tracer", "twelfth_br_36Rnd_UW"}
#define COMMON_SMG_MAGAZINES {"twelfth_m7_60rnd_UW", "twelfth_m7_48rnd_UW", "twelfth_m7_60rnd", "twelfth_m7_60rnd_T", "twelfth_m7_48rnd", "twelfth_m7_48rnd_T"}
// Start Secondary Macros
#define COMMON_M6_MAGAZINES {"OPTRE_8Rnd_127x40_Mag", "OPTRE_8Rnd_127x40_Mag_Tracer", "OPTRE_16Rnd_127x40_Mag", "OPTRE_16Rnd_127x40_Mag_Tracer"}
// Start 40mm Macros
#define COMMON_GL_MAGS {"M319_HE_Grenade_Shell", "M319_HEDP_Grenade_Shell", "M319_HEAT_Grenade_Shell", "M319_Smoke", "M319_Smoke_Orange", "M319_Smoke_Green", "M319_Smoke_Red", "1Rnd_HE_Grenade_shell", "UGL_FlareWhite_F", "UGL_FlareGreen_F", "UGL_FlareRed_F", "UGL_FlareYellow_F", "UGL_FlareCIR_F", "1Rnd_Smoke_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeYellow_Grenade_shell", "1Rnd_SmokePurple_Grenade_shell", "1Rnd_SmokeBlue_Grenade_shell", "1Rnd_SmokeOrange_Grenade_shell", "3Rnd_UGL_FlareWhite_F", "3Rnd_UGL_FlareGreen_F", "3Rnd_UGL_FlareRed_F", "3Rnd_UGL_FlareYellow_F", "3Rnd_UGL_FlareCIR_F", "3Rnd_Smoke_Grenade_shell", "3Rnd_SmokeRed_Grenade_shell", "3Rnd_SmokeGreen_Grenade_shell", "3Rnd_SmokeYellow_Grenade_shell", "3Rnd_SmokePurple_Grenade_shell", "3Rnd_SmokeBlue_Grenade_shell", "3Rnd_SmokeOrange_Grenade_shell", "OPTRE_signalSmokeB", "OPTRE_signalSmokeG", "OPTRE_signalSmokeO", "OPTRE_signalSmokeP", "OPTRE_signalSmokeR", "OPTRE_signalSmokeY", "twelfth_40mm_heat", "ACE_HuntIR_M203"}
// Tripod/Deployed MG Macros for animations
#define DEPLOYED_GESTURE_GPMG \
	dzn_MG_Tripod_deployedGesture[] = {"dzn_MG_Tripod_GestureHoldType1","dzn_MG_Tripod_GestureHoldCrouchType1","dzn_MG_Tripod_GestureHoldProneType1"}

#define RELOAD_EH \
	class EventHandlers: EventHandlers \
	{ \
		class dzn_MG_Tripod \
		{ \
			reload = "_this call dzn_MG_Tripod_fnc_handleReloadEH"; \
			reloaded = "_this call dzn_MG_Tripod_fnc_handleReloadedEH"; \
		}; \
	}    