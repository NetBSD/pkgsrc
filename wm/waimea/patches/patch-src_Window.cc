$NetBSD: patch-src_Window.cc,v 1.1 2011/12/21 13:02:10 wiz Exp $

Avoid conflict with list<>.

--- src/Window.cc.orig	2002-11-06 11:55:10.000000000 +0000
+++ src/Window.cc
@@ -280,13 +280,13 @@ list <WaAction *> *WaWindow::GetActionLi
         if (classhint) {
             if (classhint->res_name &&
                 (*it)->name->Match(classhint->res_name))
-                return &((*it)->list);
+                return &((*it)->rlist);
             else if (classhint->res_class &&
                      (*it)->cl->Match(classhint->res_class))
-                return &((*it)->list);
+                return &((*it)->rlist);
         }
         if ((*it)->title->Match(name))
-            return &((*it)->list);
+            return &((*it)->rlist);
     }
     return NULL;
 }
