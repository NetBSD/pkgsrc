$NetBSD: patch-build_config_linux_pkg-config.py,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/config/linux/pkg-config.py.orig	2026-01-07 00:50:30.000000000 +0000
+++ build/config/linux/pkg-config.py
@@ -108,7 +108,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd', 'netbsd'])):
     print("[[],[],[],[],[]]")
     return 0
 
