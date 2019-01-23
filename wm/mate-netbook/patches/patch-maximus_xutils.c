$NetBSD: patch-maximus_xutils.c,v 1.1 2019/01/23 15:00:15 youri Exp $

Fix segfault.

--- maximus/xutils.c.orig	2018-06-15 10:51:07.000000000 +0000
+++ maximus/xutils.c
@@ -86,9 +86,6 @@ _wnck_get_wmclass (Window xwindow,
   
   retval = NULL;
 
-  if (res_class)
-    *res_class = NULL;
-
   if (res_name)
     *res_name = NULL;
   
