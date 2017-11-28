$NetBSD: patch-meinheld_server_picoev__select.c,v 1.2 2017/11/28 12:47:28 wiz Exp $

Fix broken code.
https://github.com/mopemope/meinheld/pull/89

--- meinheld/server/picoev_select.c.orig	2015-09-16 12:56:12.000000000 +0000
+++ meinheld/server/picoev_select.c
@@ -102,7 +102,7 @@ picoev_loop* picoev_create_loop(int max_
     return NULL;
   }
   
-  loop->loop.now = current_msec / 1000;
+  loop->now = current_msec / 1000;
   return loop;
 }
 
