$NetBSD: patch-Xlib_protocol_rq.py,v 1.1 2011/08/22 12:18:19 wiz Exp $

Python-3.1 compatibility.

--- Xlib/protocol/rq.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/protocol/rq.py
@@ -1090,7 +1090,7 @@ class Struct:
         # memory leak isn't that serious.  Besides, Python 2.0 has
         # real garbage collect.
 
-        exec code
+        exec(code)
         self.to_binary = new.instancemethod(to_binary, self, self.__class__)
 
         # Finally call it manually
@@ -1175,7 +1175,7 @@ class Struct:
 
         # Finally, compile function as for to_binary.
 
-        exec code
+        exec(code)
         self.parse_value = new.instancemethod(parse_value, self, self.__class__)
 
         # Call it manually
@@ -1275,7 +1275,7 @@ class Struct:
 
         # Finally, compile function as for to_binary.
 
-        exec code
+        exec(code)
         self.parse_binary = new.instancemethod(parse_binary, self, self.__class__)
 
         # Call it manually
