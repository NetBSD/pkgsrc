$NetBSD: patch-project.py,v 1.1 2023/08/05 07:23:35 adam Exp $

Accept license for pkgsrc.

--- project.py.orig	2023-07-22 15:08:24.000000000 +0000
+++ project.py
@@ -169,6 +169,8 @@ del find_qt
         if tool == 'pep517':
             self.confirm_license = True
 
+	# accept license automatically (handled by pkgsrc license framework)
+        self.confirm_license = True
         self._check_license()
 
         # Handle the platform tag.
