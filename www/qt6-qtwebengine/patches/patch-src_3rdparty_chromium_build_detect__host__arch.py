$NetBSD: patch-src_3rdparty_chromium_build_detect__host__arch.py,v 1.1 2025/12/21 09:38:17 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/build/detect_host_arch.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/build/detect_host_arch.py
@@ -20,6 +20,8 @@ def HostArch():
     host_arch = 'ia32'
   elif host_arch in ['x86_64', 'amd64']:
     host_arch = 'x64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('arm'):
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
