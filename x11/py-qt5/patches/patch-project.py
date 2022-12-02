$NetBSD: patch-project.py,v 1.1 2022/12/02 15:31:38 wiz Exp $

Accept license for pkgsrc.

--- project.py.orig	2022-06-18 17:04:05.430114300 +0000
+++ project.py
@@ -172,6 +172,8 @@ del find_qt
         if tool == 'pep517':
             self.confirm_license = True
 
+	# accept license automatically (handled by pkgsrc license framework)
+        self.confirm_license = True
         self._check_license()
 
         # Handle the platform tag (allowing for win32-g++).
