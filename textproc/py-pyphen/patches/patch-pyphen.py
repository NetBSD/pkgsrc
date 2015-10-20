$NetBSD: patch-pyphen.py,v 1.2 2015/10/20 17:18:57 kleink Exp $

Adjust dictionaries path to allow multiple Python version installs.

--- pyphen.py.orig	2015-09-28 11:41:52.000000000 +0200
+++ pyphen.py	2015-10-20 18:26:32.000000000 +0200
@@ -50,13 +50,13 @@ try:
     import pkg_resources
     dictionaries_roots = (os.path.join(
         pkg_resources.resource_filename('pyphen', ''),
-        'share', 'pyphen', 'dictionaries'),)
+        'share', 'pyphen%s' % sys.version[0:3], 'dictionaries'),)
 except ImportError:
     dictionaries_roots = ()

 finally:
     dictionaries_roots += (
-        os.path.join(sys.prefix, 'share', 'pyphen', 'dictionaries'),
+        os.path.join(sys.prefix, 'share', 'pyphen%s' % sys.version[0:3], 'dictionaries'),
         os.path.join(os.path.dirname(__file__), 'dictionaries'))
 
 
