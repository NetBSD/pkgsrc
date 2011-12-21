$NetBSD: patch-src_Resources.hh,v 1.1 2011/12/21 13:02:10 wiz Exp $

Avoid conflict with list<>.

--- src/Resources.hh.orig	2002-11-06 11:55:10.000000000 +0000
+++ src/Resources.hh
@@ -40,24 +40,24 @@ typedef struct _ButtonStyle ButtonStyle;
 
 #define IS_ENV_CHAR(ch) (isalnum(ch) || ch == '_')
 
-#define ACTLISTCLEAR(list) \
-    while (! list.empty()) { \
-        if (list.back()->exec) \
-            delete [] list.back()->exec; \
-        if (list.back()->param) \
-            delete [] list.back()->param; \
-        delete list.back(); \
-        list.pop_back(); \
+#define ACTLISTCLEAR(rlist) \
+    while (! rlist.empty()) { \
+        if (rlist.back()->exec) \
+            delete [] rlist.back()->exec; \
+        if (rlist.back()->param) \
+            delete [] rlist.back()->param; \
+        delete rlist.back(); \
+        rlist.pop_back(); \
     }
 
-#define ACTLISTPTRCLEAR(list) \
-    while (! list->empty()) { \
-        if (list->back()->exec) \
-            delete [] list->back()->exec; \
-        if (list->back()->param) \
-            delete [] list->back()->param; \
-        delete list->back(); \
-        list->pop_back(); \
+#define ACTLISTPTRCLEAR(rlist) \
+    while (! rlist->empty()) { \
+        if (rlist->back()->exec) \
+            delete [] rlist->back()->exec; \
+        if (rlist->back()->param) \
+            delete [] rlist->back()->param; \
+        delete rlist->back(); \
+        rlist->pop_back(); \
     }
 
 
@@ -193,13 +193,13 @@ public:
         delete name;
         delete cl;
         delete title;
-        ACTLISTCLEAR(list);
+        ACTLISTCLEAR(rlist);
     }
     
     Regex *name;
     Regex *cl;
     Regex *title;
-    list<WaAction *> list;
+    list<WaAction *> rlist;
 };
 
 class StrComp {
