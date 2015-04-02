$NetBSD: patch-src_radeon__video.h,v 1.1 2015/04/02 22:16:46 tnn Exp $

--- src/radeon_video.h.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_video.h
@@ -2,10 +2,12 @@
 #define __RADEON_VIDEO_H__
 
 #include "xf86i2c.h"
+#ifdef PKGSRC_LEGACY_XORG_SERVER
 #include "fi1236.h"
 #include "msp3430.h"
 #include "tda9885.h"
 #include "uda1380.h"
+#endif
 #include "i2c_def.h"
 
 #include "generic_bus.h"
@@ -44,11 +46,15 @@ typedef struct {
    uint32_t      i2c_status;
    uint32_t      i2c_cntl;
 
+#ifdef PKGSRC_LEGACY_XORG_SERVER
    FI1236Ptr     fi1236;
+#endif
    uint8_t       tuner_type;
+#ifdef PKGSRC_LEGACY_XORG_SERVER
    MSP3430Ptr    msp3430;
    TDA9885Ptr    tda9885;
    UDA1380Ptr    uda1380;
+#endif
 
    /* VIP bus and devices */
    GENERIC_BUS_Ptr  VIP;
