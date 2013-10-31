$NetBSD: patch-src_atombios__crtc.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/atombios_crtc.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/atombios_crtc.c
@@ -87,7 +87,7 @@ atombios_lock_crtc(atomBiosHandlePtr ato
     data.exec.pspace = &crtc_data;
 
     if (RHDAtomBiosFunc(atomBIOS->pScrn, atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("%s CRTC %d success\n", lock? "Lock":"Unlock", crtc);
+/*	ErrorF("%s CRTC %d success\n", lock? "Lock":"Unlock", crtc); */
 	return ATOM_SUCCESS ;
     }
 
@@ -110,7 +110,7 @@ atombios_enable_crtc(atomBiosHandlePtr a
     data.exec.pspace = &crtc_data;
 
     if (RHDAtomBiosFunc(atomBIOS->pScrn, atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("%s CRTC %d success\n", state? "Enable":"Disable", crtc);
+/*	ErrorF("%s CRTC %d success\n", state? "Enable":"Disable", crtc); */
 	return ATOM_SUCCESS ;
     }
 
@@ -133,7 +133,7 @@ atombios_enable_crtc_memreq(atomBiosHand
     data.exec.pspace = &crtc_data;
 
     if (RHDAtomBiosFunc(atomBIOS->pScrn, atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("%s CRTC memreq %d success\n", state? "Enable":"Disable", crtc);
+/*	ErrorF("%s CRTC memreq %d success\n", state? "Enable":"Disable", crtc); */
 	return ATOM_SUCCESS ;
     }
 
@@ -157,7 +157,7 @@ atombios_blank_crtc(atomBiosHandlePtr at
     data.exec.pspace = &crtc_data;
 
     if (RHDAtomBiosFunc(atomBIOS->pScrn, atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("%s CRTC %d success\n", state? "Blank":"Unblank", crtc);
+/*	ErrorF("%s CRTC %d success\n", state? "Blank":"Unblank", crtc); */
 	return ATOM_SUCCESS ;
     }
 
@@ -231,7 +231,7 @@ atombios_set_crtc_timing(xf86CrtcPtr crt
     data.exec.pspace = &param;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Set CRTC Timing success\n");
+/*	ErrorF("Set CRTC Timing success\n"); */
 	return ATOM_SUCCESS ;
     }
 
@@ -282,7 +282,7 @@ atombios_set_crtc_dtd_timing(xf86CrtcPtr
     data.exec.pspace = &param;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Set DTD CRTC Timing success\n");
+/*	ErrorF("Set DTD CRTC Timing success\n"); */
 	return ATOM_SUCCESS ;
     }
 
@@ -336,7 +336,7 @@ atombios_pick_pll(xf86CrtcPtr crtc)
     } else
 	radeon_crtc->pll_id = radeon_crtc->crtc_id;
 
-    ErrorF("Picked PLL %d\n", radeon_crtc->pll_id);
+/*    ErrorF("Picked PLL %d\n", radeon_crtc->pll_id); */
 
     for (o = 0; o < xf86_config->num_output; o++) {
 	output = xf86_config->output[o];
@@ -449,11 +449,11 @@ static uint32_t atombios_adjust_pll(xf86
 		args.v1.ucTransmitterID = radeon_encoder->encoder_id;
 		args.v1.ucEncodeMode = atombios_get_encoder_mode(output);
 
-		ErrorF("before %d\n", args.v1.usPixelClock);
+/*		ErrorF("before %d\n", args.v1.usPixelClock); */
 		if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
 		    adjusted_clock = le16_to_cpu(args.v1.usPixelClock) * 10;
 		}
-		ErrorF("after %d\n", args.v1.usPixelClock);
+/*		ErrorF("after %d\n", args.v1.usPixelClock); */
 		break;
 	    case 3:
 		args.v3.sInput.usPixelClock = cpu_to_le16(adjusted_clock / 10);
@@ -467,7 +467,7 @@ static uint32_t atombios_adjust_pll(xf86
 		// if SS
 		//    args.v3.sInput.ucDispPllConfig |= DISPPLL_CONFIG_SS_ENABLE;
 
-		ErrorF("before %d 0x%x\n", args.v3.sInput.usPixelClock, args.v3.sInput.ucDispPllConfig);
+/*		ErrorF("before %d 0x%x\n", args.v3.sInput.usPixelClock, args.v3.sInput.ucDispPllConfig); */
 		if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
 		    adjusted_clock = args.v3.sOutput.ulDispPllFreq * 10;
 		    if (args.v3.sOutput.ucRefDiv) {
@@ -478,8 +478,8 @@ static uint32_t atombios_adjust_pll(xf86
 			pll_flags |= RADEON_PLL_USE_POST_DIV;
 			info->pll.post_div = args.v3.sOutput.ucPostDiv;
 		    }
-		    ErrorF("after %d %d %d\n", args.v3.sOutput.ulDispPllFreq,
-			   args.v3.sOutput.ucRefDiv, args.v3.sOutput.ucPostDiv);
+/*		    ErrorF("after %d %d %d\n", args.v3.sOutput.ulDispPllFreq,
+			   args.v3.sOutput.ucRefDiv, args.v3.sOutput.ucPostDiv); */
 		}
 		break;
 	    default:
@@ -568,7 +568,7 @@ atombios_crtc_set_dcpll(xf86CrtcPtr crtc
     data.exec.pspace = &args;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Set DCPLL success\n");
+/*	ErrorF("Set DCPLL success\n"); */
 	return;
     }
 
@@ -710,7 +710,7 @@ atombios_crtc_set_pll(xf86CrtcPtr crtc, 
     data.exec.pspace = &args;
 
     if (RHDAtomBiosFunc(info->atomBIOS->pScrn, info->atomBIOS, ATOMBIOS_EXEC, &data) == ATOM_SUCCESS) {
-	ErrorF("Set CRTC %d PLL success\n", radeon_crtc->crtc_id);
+/*	ErrorF("Set CRTC %d PLL success\n", radeon_crtc->crtc_id); */
 	return;
     }
 
@@ -991,8 +991,8 @@ atombios_crtc_mode_set(xf86CrtcPtr crtc,
 	tilingChanged = RADEONSetTiling(pScrn);
     }
 
-    ErrorF("Mode %dx%d - %d %d %d\n", adjusted_mode->CrtcHDisplay, adjusted_mode->CrtcVDisplay,
-	   adjusted_mode->CrtcHTotal, adjusted_mode->CrtcVTotal, adjusted_mode->Flags);
+/*    ErrorF("Mode %dx%d - %d %d %d\n", adjusted_mode->CrtcHDisplay, adjusted_mode->CrtcVDisplay,
+	   adjusted_mode->CrtcHTotal, adjusted_mode->CrtcVTotal, adjusted_mode->Flags); */
 
     RADEONInitMemMapRegisters(pScrn, info->ModeReg, info);
     RADEONRestoreMemMapRegisters(pScrn, info->ModeReg);
