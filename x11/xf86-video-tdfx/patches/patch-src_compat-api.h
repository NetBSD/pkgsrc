$NetBSD: patch-src_compat-api.h,v 1.1 2016/11/16 21:51:13 wiz Exp $

commit b99390efcb55d7d4a68e8c595119c1af4426fc0b
Author: Adam Jackson <ajax@redhat.com>
Date:   Tue Jul 19 10:03:56 2016 -0400

    Adapt Block/WakeupHandler signature for ABI 23
    
    Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/compat-api.h.orig	2013-02-07 07:56:21.000000000 +0000
+++ src/compat-api.h
@@ -78,11 +78,19 @@
 
 #define SCREEN_INIT_ARGS_DECL ScreenPtr pScreen, int argc, char **argv
 
+#if ABI_VIDEODRV_VERSION >= SET_ABI_VERSION(23, 0)
+#define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout
+#define BLOCKHANDLER_ARGS arg, pTimeout
+
+#define WAKEUPHANDLER_ARGS_DECL ScreenPtr arg, unsigned long result
+#define WAKEUPHANDLER_ARGS arg, result
+#else
 #define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout, pointer pReadmask
 #define BLOCKHANDLER_ARGS arg, pTimeout, pReadmask
 
 #define WAKEUPHANDLER_ARGS_DECL ScreenPtr arg, unsigned long result, pointer read_mask
 #define WAKEUPHANDLER_ARGS arg, result, read_mask
+#endif
 
 #define CLOSE_SCREEN_ARGS_DECL ScreenPtr pScreen
 #define CLOSE_SCREEN_ARGS pScreen
