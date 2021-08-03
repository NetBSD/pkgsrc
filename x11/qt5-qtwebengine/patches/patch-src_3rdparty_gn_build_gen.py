$NetBSD: patch-src_3rdparty_gn_build_gen.py,v 1.1 2021/08/03 21:04:36 markd Exp $

teach about netbsd

--- src/3rdparty/gn/build/gen.py.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/gn/build/gen.py
@@ -43,10 +43,12 @@ class Platform(object):
       self._platform = 'freebsd'
     elif self._platform.startswith('openbsd'):
       self._platform = 'openbsd'
+    elif self._platform.startswith('netbsd'):
+      self._platform = 'netbsd'
 
   @staticmethod
   def known_platforms():
-    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia', 'freebsd', 'openbsd']
+    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia', 'freebsd', 'openbsd', 'netbsd']
 
   def platform(self):
     return self._platform
@@ -70,7 +72,7 @@ class Platform(object):
     return self._platform == 'aix'
 
   def is_posix(self):
-    return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd']
+    return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'netbsd']
 
 
 def main(argv):
@@ -189,6 +191,7 @@ def WriteGenericNinja(path, static_libra
       'freebsd': 'build_linux.ninja.template',
       'aix': 'build_aix.ninja.template',
       'openbsd': 'build_openbsd.ninja.template',
+      'netbsd': 'build_netbsd.ninja.template',
   }[platform.platform()])
 
   with open(template_filename) as f:
