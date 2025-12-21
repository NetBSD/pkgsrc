$NetBSD: patch-src_3rdparty_chromium_build_config_linux_pkg-config.py,v 1.1 2025/12/21 09:38:17 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/build/config/linux/pkg-config.py.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/build/config/linux/pkg-config.py
@@ -113,7 +113,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if 'linux' not in sys.platform and 'darwin' not in sys.platform:
+  if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd', 'netbsd', 'darwin'])):
     print("[[],[],[],[],[]]")
     return 0
 
