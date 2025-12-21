$NetBSD: patch-src_3rdparty_gn_src_gn_c__tool.cc,v 1.1 2025/12/21 09:38:51 markd Exp $

support writing out -L/foo -Wl,-R/foo

--- src/3rdparty/gn/src/gn/c_tool.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/gn/src/gn/c_tool.cc
@@ -28,6 +28,7 @@ CTool::CTool(const char* n)
   set_weak_framework_switch("-weak_framework ");
   set_framework_dir_switch("-F");
   set_lib_dir_switch("-L");
+  set_lib_dir_Rswitch("-Wl,-R");
   set_lib_switch("-l");
   set_linker_arg("");
 }
