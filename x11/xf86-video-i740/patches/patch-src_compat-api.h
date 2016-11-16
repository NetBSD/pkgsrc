$NetBSD: patch-src_compat-api.h,v 1.1 2016/11/16 22:05:14 wiz Exp $

Adapt Block/WakeupHandler signature for ABI 23.

--- src/compat-api.h.orig	2013-02-07 07:55:46.000000000 +0000
+++ src/compat-api.h
@@ -75,8 +75,13 @@
 
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
