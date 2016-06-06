$NetBSD: patch-src_setting.c,v 1.2 2016/06/06 13:35:35 youri Exp $

Fix glib function, patch accepted upstream.

--- src/setting.c.orig	2014-10-21 15:29:18.000000000 +0000
+++ src/setting.c
@@ -162,7 +162,7 @@ void save_setting()
 /* Deep copy settings. */
 Setting * copy_setting(Setting * setting)
 {
-    g_return_if_fail (setting != NULL);
+    g_return_val_if_fail (setting != NULL, NULL);
 
     /* Allocate structure. */
     Setting * new_setting = g_slice_new0(Setting);
