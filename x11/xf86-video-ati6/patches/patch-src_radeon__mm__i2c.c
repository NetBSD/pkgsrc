$NetBSD: patch-src_radeon__mm__i2c.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

--- src/radeon_mm_i2c.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_mm_i2c.c
@@ -16,10 +16,21 @@
 
 /* i2c stuff */
 #include "xf86i2c.h"
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 #include "fi1236.h"
 #include "msp3430.h"
 #include "tda9885.h"
 #include "uda1380.h"
+#else
+#define TUNER_TYPE_FI1216 -1
+#define TUNER_TYPE_FI1236 -1
+#define TUNER_TYPE_FI1236W -1
+#define TUNER_TYPE_FI1246 -1
+#define TUNER_TYPE_FI1256 -1
+#define TUNER_TYPE_MT2032 -1
+#define TUNER_TYPE_FM1216ME -1
+#define TUNER_TYPE_TEMIC_FN5AL -1
+#endif
 #include "i2c_def.h"
 
 
@@ -367,10 +378,12 @@ void RADEONInitI2C(ScrnInfoPtr pScrn, RA
     RADEONPLLPtr  pll = &(info->pll);
 
     pPriv->i2c = NULL;
+#ifdef PKGSRC_LEGACY_XORG_SERVER
     pPriv->fi1236 = NULL;
     pPriv->msp3430 = NULL;
     pPriv->tda9885 = NULL;
 	 pPriv->uda1380 = NULL;
+#endif
     #if 0 /* put back on when saa7114 support is present */
     pPriv->saa7114 = NULL;
     #endif
@@ -469,6 +482,7 @@ void RADEONInitI2C(ScrnInfoPtr pScrn, RA
     if(!info->MM_TABLE_valid)RADEON_read_eeprom(pPriv);
 #endif    
     
+#ifdef PKGSRC_LEGACY_XORG_SERVER
     if(!xf86LoadSubModule(pScrn,"fi1236"))
     {
        xf86DrvMsg(pScrn->scrnIndex, X_ERROR, "Unable to initialize fi1236 driver\n");
@@ -595,6 +609,7 @@ void RADEONInitI2C(ScrnInfoPtr pScrn, RA
        xf86_InitMSP3430(pPriv->msp3430);
        xf86_MSP3430SetVolume(pPriv->msp3430, pPriv->mute ? MSP3430_FAST_MUTE : MSP3430_VOLUME(pPriv->volume));
     }
+#endif
     
 #if 0 /* put this back when saa7114 driver is ready */
     if(!xf86LoadSubModule(pScrn,"saa7114"))
@@ -624,6 +639,7 @@ void RADEONInitI2C(ScrnInfoPtr pScrn, RA
 
 static void RADEON_TDA9885_Init(RADEONPortPrivPtr pPriv)
 {
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 TDA9885Ptr t=pPriv->tda9885;
 t->sound_trap=0;
 t->auto_mute_fm=1; /* ? */
@@ -639,4 +655,5 @@ t->minimum_gain=0;
 t->gating=0; 
 t->vif_agc=1; /* set to 1 ? - depends on design */
 t->gating=0; 
+#endif
 }
