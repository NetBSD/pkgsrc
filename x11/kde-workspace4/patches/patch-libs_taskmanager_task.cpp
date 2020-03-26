$NetBSD: patch-libs_taskmanager_task.cpp,v 1.1 2020/03/26 21:48:12 joerg Exp $

--- libs/taskmanager/task.cpp.orig	2020-03-26 12:01:17.299732149 +0000
+++ libs/taskmanager/task.cpp
@@ -478,10 +478,10 @@ bool Task::idMatch(const QString& id1, c
     if (id1.isEmpty() || id2.isEmpty())
         return false;
 
-    if (id1.contains(id2) > 0)
+    if (id1.contains(id2))
         return true;
 
-    if (id2.contains(id1) > 0)
+    if (id2.contains(id1))
         return true;
 
     return false;
