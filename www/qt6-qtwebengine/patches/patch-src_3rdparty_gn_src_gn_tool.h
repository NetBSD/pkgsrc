$NetBSD: patch-src_3rdparty_gn_src_gn_tool.h,v 1.1 2025/12/21 09:38:51 markd Exp $

add support for -Wl,-R

--- src/3rdparty/gn/src/gn/tool.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/gn/src/gn/tool.h
@@ -157,6 +157,12 @@ class Tool {
     lib_dir_switch_ = std::move(s);
   }
 
+  const std::string& lib_dir_Rswitch() const { return lib_dir_Rswitch_; }
+  void set_lib_dir_Rswitch(std::string s) {
+    DCHECK(!complete_);
+    lib_dir_Rswitch_ = std::move(s);
+  }
+
   const std::string& swiftmodule_switch() const { return swiftmodule_switch_; }
   void set_swiftmodule_switch(std::string s) {
     DCHECK(!complete_);
@@ -284,6 +290,7 @@ class Tool {
   std::string framework_dir_switch_;
   std::string lib_switch_;
   std::string lib_dir_switch_;
+  std::string lib_dir_Rswitch_;
   std::string swiftmodule_switch_;
   std::string linker_arg_;
   SubstitutionList outputs_;
