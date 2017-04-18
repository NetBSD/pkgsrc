$NetBSD: patch-src_easy.c,v 1.1 2017/04/18 15:06:22 jperkin Exp $

Avoid "sun" definition.

--- src/easy.c.orig	2016-02-04 04:09:31.000000000 +0000
+++ src/easy.c
@@ -653,12 +653,12 @@ convert_protocol_address(struct sockaddr
 #if !defined(WIN32)
     case AF_UNIX:
         {
-            struct sockaddr_un* sun = (struct sockaddr_un*)saddr;
+            struct sockaddr_un* sockun = (struct sockaddr_un*)saddr;
 
 #if PY_MAJOR_VERSION >= 3
-            res_obj = Py_BuildValue("y", sun->sun_path);
+            res_obj = Py_BuildValue("y", sockun->sun_path);
 #else
-            res_obj = Py_BuildValue("s", sun->sun_path);
+            res_obj = Py_BuildValue("s", sockun->sun_path);
 #endif
         }
         break;
