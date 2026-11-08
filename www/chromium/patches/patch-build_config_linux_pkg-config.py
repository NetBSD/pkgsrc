$NetBSD: patch-build_config_linux_pkg-config.py,v 1.32 2026/11/08 15:38:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/config/linux/pkg-config.py.orig	2026-11-02 23:22:33.000000000 +0000
+++ build/config/linux/pkg-config.py
@@ -143,7 +143,7 @@ def main():
     )
     (options, args) = parser.parse_args()
 
-    if "linux" not in sys.platform:
+    if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd', 'netbsd'])):
         if (
             sys.platform == 'darwin'
             and options.sysroot
