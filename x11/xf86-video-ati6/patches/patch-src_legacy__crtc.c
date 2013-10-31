$NetBSD: patch-src_legacy__crtc.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/legacy_crtc.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/legacy_crtc.c
@@ -305,7 +305,8 @@ RADEONRestorePLLRegisters(ScrnInfoPtr pS
 
 #if defined(__powerpc__)
     /* apparently restoring the pll causes a hang??? */
-    if (info->MacModel == RADEON_MAC_IBOOK)
+    if ((info->MacModel == RADEON_MAC_IBOOK) ||
+        (info->MacModel == RADEON_MAC_MINI_INTERNAL))
 	return;
 #endif
 
@@ -1260,7 +1261,8 @@ RADEONInitPLLRegisters(xf86CrtcPtr crtc,
 
 #if defined(__powerpc__)
     /* apparently programming this otherwise causes a hang??? */
-    if (info->MacModel == RADEON_MAC_IBOOK)
+    if ((info->MacModel == RADEON_MAC_IBOOK) ||
+        (info->MacModel == RADEON_MAC_MINI_INTERNAL))
 	save->ppll_div_3 = 0x000600ad;
     else
 #endif
