$NetBSD: patch-project.py,v 1.2 2025/07/22 04:55:48 adam Exp $

Accept license for pkgsrc.

--- project.py.orig	2025-06-03 15:55:52.456821200 +0000
+++ project.py
@@ -164,11 +164,8 @@ del find_qt
                     "Qt v6 is required, not v{0}".format(
                             self.builder.qt_version_str))
 
-        # Automatically confirm the license if there might not be a command
-        # line option to do so.
-        if tool == 'pep517':
-            self.confirm_license = True
-
+	# Accept license automatically (handled by pkgsrc license framework)
+        self.confirm_license = True
         self._check_license()
 
         # Handle the platform tag.
