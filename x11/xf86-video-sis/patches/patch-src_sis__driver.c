$NetBSD: patch-src_sis__driver.c,v 1.3 2018/05/20 06:33:40 wiz Exp $

commit 4b1356a2b7fd06e9a05d134caa4033681c939737
Author: Adam Jackson <ajax@redhat.com>
Date:   Thu Feb 16 11:21:27 2017 -0500

    Remove reference to ->virtualFrom

    The core will print this information as well anyway.

    Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/sis_driver.c.orig	2017-01-17 22:45:12.000000000 +0000
+++ src/sis_driver.c
@@ -2738,7 +2738,7 @@ SiSPrintModes(ScrnInfoPtr pScrn)
     float hsync, refresh = 0.0;
     char *desc, *desc2, *prefix, *uprefix, *output;
 
-    xf86DrvMsg(pScrn->scrnIndex, pScrn->virtualFrom, "Virtual size is %dx%d "
+    xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Virtual size is %dx%d "
 	       "(pitch %d)\n", pScrn->virtualX, pScrn->virtualY,
 	       pScrn->displayWidth);
 
