$NetBSD: patch-src_radeon__video.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

--- src/radeon_video.c.orig	2012-06-25 08:32:43.000000000 +0000
+++ src/radeon_video.c
@@ -32,9 +32,11 @@
 
 #include "theatre_detect.h"
 #include "theatre_reg.h"
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 #include "fi1236.h"
 #include "msp3430.h"
 #include "tda9885.h"
+#endif
 
 #define OFF_DELAY       250  /* milliseconds */
 #define FREE_DELAY      15000
@@ -1743,8 +1745,10 @@ RADEONStopVideo(ScrnInfoPtr pScrn, point
         OUTREG(RADEON_CAP0_TRIG_CNTL, 0);
         RADEONResetVideo(pScrn);
         pPriv->video_stream_active = FALSE;
+#ifdef PKGSRC_LEGACY_XORG_SERVER
         if(pPriv->msp3430 != NULL) xf86_MSP3430SetVolume(pPriv->msp3430, MSP3430_FAST_MUTE);
 		if(pPriv->uda1380 != NULL) xf86_uda1380_mute(pPriv->uda1380, TRUE);
+#endif
         if(pPriv->i2c != NULL) RADEON_board_setmisc(pPriv);
      }
      RADEONFreeVideoMemory(pScrn, pPriv);
@@ -1913,11 +1917,13 @@ RADEONSetPortAttribute(ScrnInfoPtr  pScr
         pPriv->encoding = value;
         if(pPriv->video_stream_active)
         {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
            if(pPriv->theatre != NULL) RADEON_RT_SetEncoding(pScrn, pPriv);
            if(pPriv->msp3430 != NULL) RADEON_MSP_SetEncoding(pPriv);
            if(pPriv->tda9885 != NULL) RADEON_TDA9885_SetEncoding(pPriv);
 	   if(pPriv->fi1236 != NULL) RADEON_FI1236_SetEncoding(pPriv);
            if(pPriv->i2c != NULL) RADEON_board_setmisc(pPriv);
+#endif
         /* put more here to actually change it */
         }
    } 
@@ -1925,6 +1931,7 @@ RADEONSetPortAttribute(ScrnInfoPtr  pScr
    {
         pPriv->frequency = value;
         /* mute volume if it was not muted before */
+#ifdef PKGSRC_LEGACY_XORG_SERVER
         if((pPriv->msp3430!=NULL)&& !pPriv->mute)xf86_MSP3430SetVolume(pPriv->msp3430, MSP3430_FAST_MUTE);
 		if((pPriv->uda1380!=NULL)&& !pPriv->mute)xf86_uda1380_mute(pPriv->uda1380, TRUE);
         if(pPriv->fi1236 != NULL) xf86_TUNER_set_frequency(pPriv->fi1236, value);
@@ -1933,18 +1940,23 @@ RADEONSetPortAttribute(ScrnInfoPtr  pScr
                 xf86_InitMSP3430(pPriv->msp3430);
         if((pPriv->msp3430 != NULL)&& !pPriv->mute) xf86_MSP3430SetVolume(pPriv->msp3430, MSP3430_VOLUME(pPriv->volume));
 		if((pPriv->uda1380 != NULL)&& !pPriv->mute) xf86_uda1380_setvolume(pPriv->uda1380, pPriv->volume);
+#endif
    } 
    else if(attribute == xvMute) 
    {
         pPriv->mute = value;
+#ifdef PKGSRC_LEGACY_XORG_SERVER
         if(pPriv->msp3430 != NULL) xf86_MSP3430SetVolume(pPriv->msp3430, pPriv->mute ? MSP3430_FAST_MUTE : MSP3430_VOLUME(pPriv->volume));
         if(pPriv->i2c != NULL) RADEON_board_setmisc(pPriv);
 		if(pPriv->uda1380 != NULL) xf86_uda1380_mute(pPriv->uda1380, pPriv->mute);
+#endif
    } 
    else if(attribute == xvSAP) 
    {
         pPriv->sap_channel = value;
+#ifdef PKGSRC_LEGACY_XORG_SERVER
         if(pPriv->msp3430 != NULL) xf86_MSP3430SetSAP(pPriv->msp3430, pPriv->sap_channel?4:3);
+#endif
    } 
    else if(attribute == xvVolume) 
    {
@@ -1952,9 +1964,11 @@ RADEONSetPortAttribute(ScrnInfoPtr  pScr
         if(value>1000)value = 1000;
         pPriv->volume = value;  
         pPriv->mute = FALSE;
+#ifdef PKGSRC_LEGACY_XORG_SERVER
         if(pPriv->msp3430 != NULL) xf86_MSP3430SetVolume(pPriv->msp3430, MSP3430_VOLUME(value));
         if(pPriv->i2c != NULL) RADEON_board_setmisc(pPriv);
 		if(pPriv->uda1380 != NULL) xf86_uda1380_setvolume(pPriv->uda1380, value);
+#endif
    } 
    else if(attribute == xvOverlayDeinterlacingMethod) 
    {
@@ -1982,6 +1996,7 @@ RADEONSetPortAttribute(ScrnInfoPtr  pScr
 		pScrn->currentMode->Flags & V_INTERLACE ? " interlaced" : "" ,
 		pScrn->currentMode->Flags & V_DBLSCAN ? " doublescan" : ""
 		);
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 	if(pPriv->tda9885 != NULL){
 		xf86_tda9885_getstatus(pPriv->tda9885);
 		xf86_tda9885_dumpstatus(pPriv->tda9885);
@@ -1989,16 +2004,19 @@ RADEONSetPortAttribute(ScrnInfoPtr  pScr
 	if(pPriv->fi1236!=NULL){
 		xf86_fi1236_dump_status(pPriv->fi1236);
 		}
+#endif
    }
    else if(attribute == xvAdjustment) 
    {
   	pPriv->adjustment=value;
         xf86DrvMsg(pScrn->scrnIndex,X_ERROR,"Setting pPriv->adjustment to %u\n",
 		   (unsigned)pPriv->adjustment);
+#ifdef PKGSRC_LEGACY_XORG_SERVER
   	if(pPriv->tda9885!=0){
 		pPriv->tda9885->top_adjustment=value;
 		RADEON_TDA9885_SetEncoding(pPriv);
 		}
+#endif
    }
    else 
 	return BadMatch;
@@ -2090,12 +2108,14 @@ RADEONGetPortAttribute(ScrnInfoPtr  pScr
         *value = pPriv->frequency;
     else 
     if(attribute == xvTunerStatus) {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
         if(pPriv->fi1236==NULL){
                 *value=TUNER_OFF;
                 } else
                 {
                 *value = xf86_TUNER_get_afc_hint(pPriv->fi1236);
                 }
+#endif
        } 
     else if(attribute == xvMute)
         *value = pPriv->mute;
@@ -3676,9 +3696,11 @@ RADEONPutVideo(
       {
          RADEON_RT_SetEncoding(pScrn, pPriv); 
       }
+#ifdef PKGSRC_LEGACY_XORG_SERVER
       if(pPriv->msp3430 != NULL) RADEON_MSP_SetEncoding(pPriv);
       if(pPriv->tda9885 != NULL) RADEON_TDA9885_SetEncoding(pPriv);
       if(pPriv->fi1236 != NULL) RADEON_FI1236_SetEncoding(pPriv);
+#endif
       if(pPriv->i2c != NULL)RADEON_board_setmisc(pPriv);
    }
 
@@ -3756,6 +3778,7 @@ RADEONPutVideo(
 
 static void RADEON_board_setmisc(RADEONPortPrivPtr pPriv)
 {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
     /* Adjust PAL/SECAM constants for FI1216MF tuner */
     if((((pPriv->tuner_type & 0xf)==5) ||
         ((pPriv->tuner_type & 0xf)==11)||
@@ -3775,7 +3798,7 @@ static void RADEON_board_setmisc(RADEONP
            pPriv->fi1236->parm.band_high = 0x33;
         }
     }
-    
+#endif
 }
 
 static void RADEON_RT_SetEncoding(ScrnInfoPtr pScrn, RADEONPortPrivPtr pPriv)
@@ -3867,6 +3890,7 @@ xf86_RT_SetOutputVideoSize(pPriv->theatr
 
 static void RADEON_MSP_SetEncoding(RADEONPortPrivPtr pPriv)
 {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 xf86_MSP3430SetVolume(pPriv->msp3430, MSP3430_FAST_MUTE);
 switch(pPriv->encoding){
         case 1:
@@ -3922,10 +3946,12 @@ switch(pPriv->encoding){
         }
 xf86_InitMSP3430(pPriv->msp3430);
 xf86_MSP3430SetVolume(pPriv->msp3430, pPriv->mute ? MSP3430_FAST_MUTE : MSP3430_VOLUME(pPriv->volume));
+#endif
 }
 
 static void RADEON_TDA9885_SetEncoding(RADEONPortPrivPtr pPriv)
 {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 TDA9885Ptr t=pPriv->tda9885;
 
 switch(pPriv->encoding){
@@ -3962,10 +3988,12 @@ switch(pPriv->encoding){
 xf86_tda9885_setparameters(pPriv->tda9885); 
 xf86_tda9885_getstatus(pPriv->tda9885);
 xf86_tda9885_dumpstatus(pPriv->tda9885);
+#endif
 }
 
 static void RADEON_FI1236_SetEncoding(RADEONPortPrivPtr pPriv)
 {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 /* at the moment this only affect MT2032 */
 switch(pPriv->encoding){
                 /* PAL */
@@ -3994,5 +4022,6 @@ switch(pPriv->encoding){
         default:
                 return;
         }       
+#endif
 }
 
