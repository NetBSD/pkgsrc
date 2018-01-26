$NetBSD: patch-siputils.py,v 1.3 2018/01/26 15:47:18 jperkin Exp $

Fix build on Darwin with pkgsrc python.
Fix SunOS/clang.

--- siputils.py.orig	2015-03-25 11:00:24.000000000 +0000
+++ siputils.py
@@ -258,6 +258,9 @@ class Makefile:
         self._installs = installs
         self._infix = ""
 
+        if sys.platform == "darwin":
+            self.config.qt_framework = 0
+
         # Make sure the destination directory is an absolute path.
         if dir:
             self.dir = os.path.abspath(dir)
@@ -1596,10 +1599,10 @@ class ModuleMakefile(Makefile):
                     if sys.platform[:5] == 'linux':
                         self.LFLAGS.extend(['-Wl,--version-script=%s.exp' % self._target])
                     elif sys.platform[:5] == 'sunos':
-                        if self.required_string('LINK') == 'g++':
-                            self.LFLAGS.extend(['-Wl,-z,noversion', '-Wl,-M,%s.exp' % self._target])
-                        else:
+                        if self.required_string('LINK') == 'CC':
                             self.LFLAGS.extend(['-z' 'noversion', '-M', '%s.exp' % self._target])
+                        else:
+                            self.LFLAGS.extend(['-Wl,-z,noversion', '-Wl,-M,%s.exp' % self._target])
                     elif sys.platform[:5] == 'hp-ux':
                         self.LFLAGS.extend(['-Wl,+e,%s' % self._entry_point])
                     elif sys.platform[:5] == 'irix' and self.required_string('LINK') != 'g++':
