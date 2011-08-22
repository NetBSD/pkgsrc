$NetBSD: patch-Xlib_rdb.py,v 1.1 2011/08/22 12:18:19 wiz Exp $

Python-3.1 compatibility.

--- Xlib/rdb.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/rdb.py
@@ -191,12 +191,13 @@ class ResourceDB:
 
         self.lock.release()
 
-    def __getitem__(self, (name, cls)):
+    def __getitem__(self, nc):
         """db[name, class]
 
         Return the value matching the resource identified by NAME and
         CLASS.  If no match is found, KeyError is raised.
         """
+        name, cls = nc
 
         # Split name and class into their parts
 
