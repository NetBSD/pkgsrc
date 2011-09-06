$NetBSD: patch-Xlib_rdb.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

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
 
