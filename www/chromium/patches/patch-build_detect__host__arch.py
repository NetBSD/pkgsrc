$NetBSD: patch-build_detect__host__arch.py,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/detect_host_arch.py.orig	2026-09-14 22:17:16.000000000 +0000
+++ build/detect_host_arch.py
@@ -23,6 +23,8 @@ def HostArch():
         host_arch = 'arm'
     elif host_arch.startswith('aarch64'):
         host_arch = 'arm64'
+    elif host_arch.startswith('arm64'):
+        host_arch = 'arm64'
     elif host_arch.startswith('mips64'):
         host_arch = 'mips64'
     elif host_arch.startswith('mips'):
