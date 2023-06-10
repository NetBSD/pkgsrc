$NetBSD: patch-src_3rdparty_gn_tools_gn_args.cc,v 1.3 2023/06/10 18:23:07 adam Exp $

--- src/3rdparty/gn/tools/gn/args.cc.orig	2022-04-06 13:32:17.000000000 +0000
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
