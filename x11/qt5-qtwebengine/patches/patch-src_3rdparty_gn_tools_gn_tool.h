$NetBSD: patch-src_3rdparty_gn_tools_gn_tool.h,v 1.1 2021/08/03 21:04:36 markd Exp $

add support for -Wl,-R

--- src/3rdparty/gn/tools/gn/tool.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/gn/tools/gn/tool.h
@@ -149,6 +149,12 @@ class Tool {
     lib_dir_switch_ = std::move(s);
   }
 
+  const std::string& lib_dir_Rswitch() const { return lib_dir_Rswitch_; }
+  void set_lib_dir_Rswitch(std::string s) {
+    DCHECK(!complete_);
+    lib_dir_Rswitch_ = std::move(s);
+  }
+
   const std::string& linker_arg() const { return linker_arg_; }
   void set_linker_arg(std::string s) {
     DCHECK(!complete_);
@@ -262,6 +268,7 @@ class Tool {
   std::string framework_dir_switch_;
   std::string lib_switch_;
   std::string lib_dir_switch_;
+  std::string lib_dir_Rswitch_;
   std::string linker_arg_;
   SubstitutionList outputs_;
   SubstitutionList runtime_outputs_;
