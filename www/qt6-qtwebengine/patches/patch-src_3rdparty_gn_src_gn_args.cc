$NetBSD: patch-src_3rdparty_gn_src_gn_args.cc,v 1.1 2026/03/29 16:57:04 tnn Exp $

- Handle NetBSD/evbarm correctly (from wip/gn-git)

--- src/3rdparty/gn/src/gn/args.cc.orig	2026-03-28 14:06:25.132164117 +0000
+++ src/3rdparty/gn/src/gn/args.cc
@@ -358,6 +358,10 @@ void Args::SetSystemVarsLocked(Scope* dest) const {
     arch = kX86;
   else if (os_arch == "x86_64")
     arch = kX64;
+  else if (os_arch == "evbarm" && sizeof(long) == 8)
+    arch = kArm64;
+  else if (os_arch == "evbarm" && sizeof(long) == 4)
+    arch = kArm;
   else if (os_arch == "aarch64" || os_arch == "arm64")
     arch = kArm64;
   else if (os_arch.substr(0, 3) == "arm")
