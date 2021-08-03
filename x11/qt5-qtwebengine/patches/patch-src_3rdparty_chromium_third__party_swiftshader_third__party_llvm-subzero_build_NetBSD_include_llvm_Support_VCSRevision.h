$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_third__party_llvm-subzero_build_NetBSD_include_llvm_Support_VCSRevision.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/Support/VCSRevision.h.orig	2020-07-23 08:46:21.668378518 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/Support/VCSRevision.h
@@ -0,0 +1 @@
+#undef LLVM_REVISION
