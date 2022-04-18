$NetBSD: patch-src_3rdparty_gn_tools_gn_args.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/gn/tools/gn/args.cc.orig
+++ src/3rdparty/gn/tools/gn/args.cc
@@ -314,6 +314,8 @@ void Args::SetSystemVarsLocked(Scope* de
   os = "aix";
 #elif defined(OS_OPENBSD)
   os = "openbsd";
+#elif defined(OS_NETBSD)
+  os = "netbsd";
 #else
 #error Unknown OS type.
 #endif
@@ -338,6 +340,8 @@ void Args::SetSystemVarsLocked(Scope* de
     arch = kX86;
   else if (os_arch == "x86_64")
     arch = kX64;
+  else if (os_arch == "arm64")
+    arch = kArm64;
   else if (os_arch.substr(0, 3) == "arm")
     arch = kArm;
   else if (os_arch == "aarch64")
