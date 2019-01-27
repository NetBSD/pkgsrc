$NetBSD: patch-src_compat-api.h,v 1.1 2019/01/27 11:54:57 tnn Exp $

Adapt to current server API

--- src/compat-api.h.orig	2012-06-15 13:26:20.000000000 +0000
+++ src/compat-api.h
@@ -73,8 +73,8 @@
 
 #define SCREEN_INIT_ARGS_DECL ScreenPtr pScreen, int argc, char **argv
 
-#define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout, pointer pReadmask
-#define BLOCKHANDLER_ARGS arg, pTimeout, pReadmask
+#define BLOCKHANDLER_ARGS_DECL ScreenPtr arg, pointer pTimeout
+#define BLOCKHANDLER_ARGS arg, pTimeout
 
 #define CLOSE_SCREEN_ARGS_DECL ScreenPtr pScreen
 #define CLOSE_SCREEN_ARGS pScreen
