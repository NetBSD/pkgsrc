$NetBSD: patch-test_xtest.c,v 1.1 2019/02/28 12:32:39 tnn Exp $

xtest.c:64:23: error: suggest braces around initialization of subobject

--- test/xtest.c.orig	2019-02-26 19:28:50.000000000 +0000
+++ test/xtest.c
@@ -61,7 +61,7 @@ xtest_init_devices(void)
 {
     ScreenRec screen = {0};
     ClientRec server_client = {0};
-    WindowRec root = {0};
+    WindowRec root = {{0}};
     WindowOptRec optional = {0};
 
     /* random stuff that needs initialization */
