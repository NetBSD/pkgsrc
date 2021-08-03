$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_third__party_llvm-subzero_build_NetBSD_include_llvm_IR_CMakeFiles_intrinsics__gen.dir_cmake__clean.cmake,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/IR/CMakeFiles/intrinsics_gen.dir/cmake_clean.cmake.orig	2020-07-23 08:46:21.593341283 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/IR/CMakeFiles/intrinsics_gen.dir/cmake_clean.cmake
@@ -0,0 +1,14 @@
+file(REMOVE_RECURSE
+  "Attributes.inc"
+  "Attributes.inc.tmp"
+  "CMakeFiles/intrinsics_gen"
+  "IntrinsicEnums.inc"
+  "IntrinsicEnums.inc.tmp"
+  "IntrinsicImpl.inc"
+  "IntrinsicImpl.inc.tmp"
+)
+
+# Per-language clean rules from dependency scanning.
+foreach(lang )
+  include(CMakeFiles/intrinsics_gen.dir/cmake_clean_${lang}.cmake OPTIONAL)
+endforeach()
