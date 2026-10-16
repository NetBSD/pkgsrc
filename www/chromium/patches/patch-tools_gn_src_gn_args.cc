$NetBSD: patch-tools_gn_src_gn_args.cc,v 1.17 2026/10/16 15:31:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/src/gn/args.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ tools/gn/src/gn/args.cc
@@ -389,7 +389,7 @@ const char* Args::GetHostCpu() {
     return kX86;
   if (os_arch == "x86_64")
     return kX64;
-  if (os_arch == "aarch64" || os_arch == "arm64")
+  if (os_arch == "aarch64" || os_arch == "arm64" || os_arch == "evbarm")
     return kArm64;
   if (os_arch.substr(0, 3) == "arm")
     return kArm;
