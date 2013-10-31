$NetBSD: patch-src_atombios__output.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/atombios_output.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/atombios_output.c
@@ -234,7 +234,7 @@ atombios_output_dac_setup(xf86OutputPtr 
     data.exec.pspace = &disp_data;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Output DAC%d setup success\n", num);
+/*	ErrorF("Output DAC%d setup success\n", num); */
 	return ATOM_SUCCESS;
     }
 
@@ -298,7 +298,7 @@ atombios_output_tv_setup(xf86OutputPtr o
     data.exec.pspace = &disp_data;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Output TV setup success\n");
+/*	ErrorF("Output TV setup success\n"); */
 	return ATOM_SUCCESS;
     }
 
@@ -333,7 +333,7 @@ atombios_external_tmds_setup(xf86OutputP
     data.exec.pspace = &disp_data;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("External TMDS setup success\n");
+/*	ErrorF("External TMDS setup success\n"); */
 	return ATOM_SUCCESS;
     }
 
@@ -364,7 +364,7 @@ atombios_output_ddia_setup(xf86OutputPtr
     data.exec.pspace = &disp_data;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("DDIA setup success\n");
+/*	ErrorF("DDIA setup success\n"); */
 	return ATOM_SUCCESS;
     }
 
@@ -503,7 +503,7 @@ atombios_output_digital_setup(xf86Output
     data.exec.dataSpace = (void *)&space;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Output digital setup success\n");
+/*	ErrorF("Output digital setup success\n"); */
 	return ATOM_SUCCESS;
     }
 
@@ -826,7 +826,7 @@ atombios_output_dig_encoder_setup(xf86Ou
     data.exec.pspace = &disp_data;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Output DIG%d encoder setup success\n", radeon_output->dig_encoder);
+/*	ErrorF("Output DIG%d encoder setup success\n", radeon_output->dig_encoder); */
 	return ATOM_SUCCESS;
     }
 
@@ -1011,10 +1011,12 @@ atombios_output_dig_transmitter_setup(xf
     data.exec.pspace = &disp_data;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
+/*
 	if (IS_DCE32_VARIANT)
 	    ErrorF("Output UNIPHY%d transmitter setup success\n", num);
 	else
 	   ErrorF("Output DIG%d transmitter setup success\n", num);
+*/
 	return ATOM_SUCCESS;
     }
 
@@ -1299,7 +1301,7 @@ atombios_output_yuv_setup(xf86OutputPtr 
 
 	OUTREG(reg, temp);
 
-	ErrorF("crtc %d YUV %s setup success\n", radeon_crtc->crtc_id, enable ? "enable" : "disable");
+/*	ErrorF("crtc %d YUV %s setup success\n", radeon_crtc->crtc_id, enable ? "enable" : "disable"); */
 	return ATOM_SUCCESS;
     }
 
@@ -1357,7 +1359,7 @@ atombios_output_overscan_setup(xf86Outpu
     data.exec.pspace = &overscan_param;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Set CRTC %d Overscan success\n", radeon_crtc->crtc_id);
+/*	ErrorF("Set CRTC %d Overscan success\n", radeon_crtc->crtc_id); */
 	return ATOM_SUCCESS ;
     }
 
@@ -1414,13 +1416,13 @@ atombios_output_scaler_setup(xf86OutputP
 	    break;
 	}
 	disp_data.ucEnable = SCALER_ENABLE_MULTITAP_MODE;
-        ErrorF("Using TV scaler %x %x\n", disp_data.ucTVStandard, disp_data.ucEnable);
+/*        ErrorF("Using TV scaler %x %x\n", disp_data.ucTVStandard, disp_data.ucEnable); */
     } else if (radeon_output->active_device & (ATOM_DEVICE_CV_SUPPORT)) {
 	disp_data.ucTVStandard = ATOM_TV_CV;
 	disp_data.ucEnable = SCALER_ENABLE_MULTITAP_MODE;
-        ErrorF("Using CV scaler %x %x\n", disp_data.ucTVStandard, disp_data.ucEnable);
+/*        ErrorF("Using CV scaler %x %x\n", disp_data.ucTVStandard, disp_data.ucEnable); */
     } else if (radeon_output->Flags & RADEON_USE_RMX) {
-	ErrorF("Using RMX\n");
+/*	ErrorF("Using RMX\n"); */
 	if (radeon_output->rmx_type == RMX_FULL)
 	    disp_data.ucEnable = ATOM_SCALER_EXPANSION;
 	else if (radeon_output->rmx_type == RMX_CENTER)
@@ -1428,7 +1430,7 @@ atombios_output_scaler_setup(xf86OutputP
 	else if (radeon_output->rmx_type == RMX_ASPECT)
 	    disp_data.ucEnable = ATOM_SCALER_EXPANSION;
     } else {
-	ErrorF("Not using RMX\n");
+/*	ErrorF("Not using RMX\n"); */
 	if (IS_AVIVO_VARIANT)
 	    disp_data.ucEnable = ATOM_SCALER_DISABLE;
 	else
@@ -1442,10 +1444,10 @@ atombios_output_scaler_setup(xf86OutputP
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
 	if (radeon_output->active_device & (ATOM_DEVICE_CV_SUPPORT | ATOM_DEVICE_TV_SUPPORT)
 	    && info->ChipFamily >= CHIP_FAMILY_RV515 && info->ChipFamily <= CHIP_FAMILY_RV570) {
-	    ErrorF("forcing TV scaler\n");
+/*	    ErrorF("forcing TV scaler\n"); */
 	    atom_rv515_force_tv_scaler(output->scrn, radeon_crtc);
 	}
-	ErrorF("scaler %d setup success\n", radeon_crtc->crtc_id);
+/*	ErrorF("scaler %d setup success\n", radeon_crtc->crtc_id); */
 	return ATOM_SUCCESS;
     }
 
@@ -1548,10 +1550,12 @@ atombios_output_dpms(xf86OutputPtr outpu
 		reg = INREG(RADEON_BIOS_3_SCRATCH);
 		OUTREG(RADEON_BIOS_3_SCRATCH, reg & ~ATOM_S3_DFP2I_ACTIVE);
 	    }
-	    if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS)
+	    if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) != ATOM_SUCCESS)
+/*
 		ErrorF("Output %s enable success\n",
 		       device_name[radeon_get_device_index(radeon_output->active_device)]);
 	    else
+*/
 		ErrorF("Output %s enable failed\n",
 		       device_name[radeon_get_device_index(radeon_output->active_device)]);
 	    if (radeon_encoder->encoder_id == ENCODER_OBJECT_ID_INTERNAL_DDI)
@@ -1581,10 +1585,12 @@ atombios_output_dpms(xf86OutputPtr outpu
 		data.exec.pspace = &disp_data;
 
 		if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data)
-		    == ATOM_SUCCESS)
+		    != ATOM_SUCCESS)
+/*
 		    ErrorF("Output %s disable success\n",
 			   device_name[radeon_get_device_index(radeon_output->active_device)]);
 		else
+*/
 		    ErrorF("Output %s disable failed\n",
 			   device_name[radeon_get_device_index(radeon_output->active_device)]);
 	    }
@@ -1735,7 +1741,7 @@ atombios_set_output_crtc_source(xf86Outp
     data.exec.dataSpace = (void *)&space;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Set CRTC %d Source success\n", radeon_crtc->crtc_id);
+/*	ErrorF("Set CRTC %d Source success\n", radeon_crtc->crtc_id); */
 	return;
     }
 
@@ -2006,7 +2012,7 @@ atom_bios_dac_load_detect(atomBiosHandle
     data.exec.pspace = &dac_data;
 
     if (RHDAtomBiosFunc(atomBIOS->pScrn, atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Dac detection success\n");
+/*	ErrorF("Dac detection success\n"); */
 	return ATOM_SUCCESS ;
     }
 
@@ -2161,7 +2167,7 @@ RADEONDPEncoderService(xf86OutputPtr out
 
     RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data);
 
-    ErrorF("%s: %d %d\n", __func__, action, args.ucStatus);
+/*    ErrorF("%s: %d %d\n", __func__, action, args.ucStatus); */
     return args.ucStatus;
 }
 
@@ -2320,7 +2326,7 @@ atom_dp_i2c_address(I2CDevPtr dev, I2CSl
 static Bool
 atom_dp_i2c_start(I2CBusPtr bus, int timeout)
 {
-    ErrorF("%s\n", __func__);
+/*    ErrorF("%s\n", __func__); */
     return TRUE;
 }
 
@@ -2467,8 +2473,8 @@ atom_dp_get_link_status(xf86OutputPtr ou
 	xf86DrvMsg(pScrn->scrnIndex, X_INFO, "dp link status failed\n");
 	return FALSE;
     }
-    ErrorF("link status %02x %02x %02x %02x %02x %02x\n", link_status[0], link_status[1],
-	   link_status[2], link_status[3], link_status[4], link_status[5]);
+/*    ErrorF("link status %02x %02x %02x %02x %02x %02x\n", link_status[0], link_status[1],
+	   link_status[2], link_status[3], link_status[4], link_status[5]); */
 
     return TRUE;
 }
