$NetBSD: patch-src_3rdparty_chromium_tools_licenses_licenses.py,v 1.1 2025/12/21 09:38:46 markd Exp $

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/tools/licenses/licenses.py.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/tools/licenses/licenses.py
@@ -816,6 +816,12 @@ def _GnBinary():
   exe = 'gn'
   if sys.platform.startswith('linux'):
     subdir = 'linux64'
+  elif sys.platform.startswith('freebsd'):
+    subdir = 'linux64'
+  elif sys.platform.startswith('netbsd'):
+    subdir = 'linux64'
+  elif sys.platform.startswith('openbsd'):
+    subdir = 'linux64'
   elif sys.platform == 'darwin':
     subdir = 'mac'
   elif sys.platform == 'win32':
