$NetBSD: patch-pyphen.py,v 1.1 2015/07/13 16:13:55 kleink Exp $

Adjust dictionaries path to allow multiple Python version installs.

--- pyphen.py.orig	2013-12-27 17:53:36.000000000 +0100
+++ pyphen.py	2015-07-13 17:48:37.000000000 +0200
@@ -53,10 +53,10 @@
 else:
     dictionaries_roots = (os.path.join(
         pkg_resources.resource_filename('pyphen', ''),
-        'share', 'pyphen', 'dictionaries'),)
+        'share', 'pyphen%s' % sys.version[0:3], 'dictionaries'),)
 finally:
     dictionaries_roots += (
-        os.path.join(sys.prefix, 'share', 'pyphen', 'dictionaries'),
+        os.path.join(sys.prefix, 'share', 'pyphen%s' % sys.version[0:3], 'dictionaries'),
         os.path.join(os.path.dirname(__file__), 'dictionaries'))
 
 
