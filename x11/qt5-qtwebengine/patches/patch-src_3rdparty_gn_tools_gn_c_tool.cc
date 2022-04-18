$NetBSD: patch-src_3rdparty_gn_tools_gn_c_tool.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/gn/tools/gn/c_tool.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/gn/tools/gn/c_tool.cc
@@ -24,6 +24,7 @@ CTool::CTool(const char* n)
   set_weak_framework_switch("-weak_framework ");
   set_framework_dir_switch("-F");
   set_lib_dir_switch("-L");
+  set_lib_dir_Rswitch("-Wl,-R");
   set_lib_switch("-l");
   set_linker_arg("");
 }
