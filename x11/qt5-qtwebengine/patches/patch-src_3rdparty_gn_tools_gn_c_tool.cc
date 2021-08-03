$NetBSD: patch-src_3rdparty_gn_tools_gn_c_tool.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

Add support of -Wl,-R

--- src/3rdparty/gn/tools/gn/c_tool.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/gn/tools/gn/c_tool.cc
@@ -23,6 +23,7 @@ CTool::CTool(const char* n)
   set_framework_switch("-framework ");
   set_framework_dir_switch("-F");
   set_lib_dir_switch("-L");
+  set_lib_dir_Rswitch("-Wl,-R");
   set_lib_switch("-l");
   set_linker_arg("");
 }
