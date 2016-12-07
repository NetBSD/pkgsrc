$NetBSD: patch-src_sna_sna.h,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/sna/sna.h.orig	2014-12-20 13:29:05.000000000 +0000
+++ src/sna/sna.h
@@ -364,8 +364,10 @@ struct sna {
 	EntityInfoPtr pEnt;
 	const struct intel_device_info *info;
 
+#if !HAVE_NOTIFY_FD
 	ScreenBlockHandlerProcPtr BlockHandler;
 	ScreenWakeupHandlerProcPtr WakeupHandler;
+#endif
 	CloseScreenProcPtr CloseScreen;
 
 	PicturePtr clear;
