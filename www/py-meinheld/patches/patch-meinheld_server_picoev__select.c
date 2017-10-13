$NetBSD: patch-meinheld_server_picoev__select.c,v 1.1 2017/10/13 14:51:16 jperkin Exp $

Fix broken code.

--- meinheld/server/picoev_select.c.orig	2015-09-16 12:56:12.000000000 +0000
+++ meinheld/server/picoev_select.c
@@ -102,7 +102,7 @@ picoev_loop* picoev_create_loop(int max_
     return NULL;
   }
   
-  loop->loop.now = current_msec / 1000;
+  loop->now = current_msec / 1000;
   return loop;
 }
 
