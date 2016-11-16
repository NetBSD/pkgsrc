$NetBSD: patch-src_compat-api.h,v 1.1 2016/11/16 21:43:58 wiz Exp $

commit 78d1138dd6e214a200ca66fa9e439ee3c9270ec8
Author: Adam Jackson <ajax@redhat.com>
Date:   Tue Jul 19 10:03:56 2016 -0400

    Adapt Block/WakeupHandler signature for ABI 23

    Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/compat-api.h.orig	2015-08-17 22:53:52.000000000 +0000
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
