$NetBSD: patch-src_compat-api.h,v 1.1 2016/11/16 22:19:16 wiz Exp $

Adapt Block/WakeupHandler signature for ABI 23.

--- src/compat-api.h.orig	2016-09-16 09:01:22.000000000 +0000
+++ src/compat-api.h
@@ -73,8 +73,13 @@
 
 #define SCREEN_INIT_ARGS_DECL ScreenPtr pScreen, int argc, char **argv
 
+#if ABI_VIDEODRV_VERSION >= SET_ABI_VERSION(23, 0)
+#define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout
+#define BLOCKHANDLER_ARGS arg, pTimeout
+#else
 #define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout, pointer pReadmask
 #define BLOCKHANDLER_ARGS arg, pTimeout, pReadmask
+#endif
 
 #define CLOSE_SCREEN_ARGS_DECL ScreenPtr pScreen
 #define CLOSE_SCREEN_ARGS pScreen
