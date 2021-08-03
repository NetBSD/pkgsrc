$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_third__party_llvm-subzero_build_NetBSD_include_llvm_Support_CMakeFiles_llvm__vcsrevision__h.dir_cmake__clean.cmake,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/Support/CMakeFiles/llvm_vcsrevision_h.dir/cmake_clean.cmake.orig	2020-07-23 08:46:21.644309495 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/Support/CMakeFiles/llvm_vcsrevision_h.dir/cmake_clean.cmake
@@ -0,0 +1,8 @@
+file(REMOVE_RECURSE
+  "CMakeFiles/llvm_vcsrevision_h"
+)
+
+# Per-language clean rules from dependency scanning.
+foreach(lang )
+  include(CMakeFiles/llvm_vcsrevision_h.dir/cmake_clean_${lang}.cmake OPTIONAL)
+endforeach()
