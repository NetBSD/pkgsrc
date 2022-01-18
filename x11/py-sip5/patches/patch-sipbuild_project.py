$NetBSD: patch-sipbuild_project.py,v 1.1 2022/01/18 19:07:45 rhialto Exp $

Backport Project.get_platform_tag from sip6, because it is used
by py-qtbuilder.

--- sipbuild/project.py.orig	2020-11-23 13:21:33.000000000 +0000
+++ sipbuild/project.py
@@ -28,6 +28,7 @@ import packaging
 import shutil
 import subprocess
 import sys
+import sysconfig
 import tempfile
 import warnings
 
@@ -306,6 +307,47 @@ class Project(AbstractProject, Configura
 
         return ''
 
+    def get_platform_tag(self):
+        """ Return the platform tag to use in a wheel name.  This default
+        implementation uses the platform name and applies PEP defined
+        conventions depending on OS version and GLIBC version as appropriate.
+        """
+
+        platform_tag = sysconfig.get_platform()
+
+        if self.py_platform == 'darwin' and self.minimum_macos_version:
+            # We expect a three part tag so leave anything else unchanged.
+            parts = platform_tag.split('-')
+            if len(parts) == 3:
+                parts[1] = '{}.{}'.format(self.minimum_macos_version[0],
+                        self.minimum_macos_version[1])
+
+                platform_tag = '-'.join(parts)
+
+        elif self.py_platform == 'linux' and self.manylinux:
+            # We expect a two part tag so leave anything else unchanged.
+            parts = platform_tag.split('-')
+            if len(parts) == 2:
+                if self.minimum_glibc_version > (2, 17):
+                    # PEP 600.
+                    parts[0] = 'manylinux'
+                    parts.insert(1,
+                            '{}.{}'.format(self.minimum_glibc_version[0],
+                                    self.minimum_glibc_version[1]))
+                elif self.minimum_glibc_version > (2, 12):
+                    # PEP 599.
+                    parts[0] = 'manylinux2014'
+                elif self.minimum_glibc_version > (2, 5):
+                    # PEP 571.
+                    parts[0] = 'manylinux2010'
+                else:
+                    # PEP 513.
+                    parts[0] = 'manylinux1'
+
+                platform_tag = '-'.join(parts)
+
+        return platform_tag.replace('.', '_').replace('-', '_')
+
     def get_requires_dists(self):
         """ Return any 'Requires-Dist' to add to the project's meta-data. """
 
