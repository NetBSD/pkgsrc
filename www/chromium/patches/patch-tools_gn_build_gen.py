$NetBSD: patch-tools_gn_build_gen.py,v 1.1 2025/02/06 09:58:29 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/build/gen.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ tools/gn/build/gen.py
@@ -94,6 +94,12 @@ class Platform(object):
   def is_solaris(self):
     return self._platform == 'solaris'
 
+  def is_openbsd(self):
+    return self._platform == 'openbsd'
+
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku', 'solaris', 'msys', 'netbsd', 'serenity']
 
@@ -304,7 +310,7 @@ def WriteGenericNinja(path, static_libra
       'linux': 'build_linux.ninja.template',
       'freebsd': 'build_linux.ninja.template',
       'aix': 'build_aix.ninja.template',
-      'openbsd': 'build_openbsd.ninja.template',
+      'openbsd': 'build_linux.ninja.template',
       'haiku': 'build_haiku.ninja.template',
       'solaris': 'build_linux.ninja.template',
       'netbsd': 'build_linux.ninja.template',
@@ -540,6 +546,9 @@ def WriteGNNinja(path, platform, host, o
     if platform.is_posix() and not platform.is_haiku():
       ldflags.append('-pthread')
 
+    if platform.is_openbsd():
+      libs.append('-lkvm')
+
     if platform.is_mingw() or platform.is_msys():
       cflags.extend(['-DUNICODE',
                      '-DNOMINMAX',
