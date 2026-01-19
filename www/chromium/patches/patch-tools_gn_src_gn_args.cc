$NetBSD: patch-tools_gn_src_gn_args.cc,v 1.1 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/src/gn/args.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ tools/gn/src/gn/args.cc
@@ -386,7 +386,7 @@ void Args::SetSystemVarsLocked(Scope* de
     arch = kX86;
   else if (os_arch == "x86_64")
     arch = kX64;
-  else if (os_arch == "aarch64" || os_arch == "arm64")
+  else if (os_arch == "aarch64" || os_arch == "arm64" || os_arch == "evbarm")
     arch = kArm64;
   else if (os_arch.substr(0, 3) == "arm")
     arch = kArm;
