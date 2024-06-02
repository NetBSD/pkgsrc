$NetBSD: patch-src_3rdparty_chromium_third__party_abseil-cpp_absl_base_options.h,v 1.1 2024/06/02 11:34:20 markd Exp $

ICU75 fix - from ArchLinux

--- src/3rdparty/chromium/third_party/abseil-cpp/absl/base/options.h.orig	2023-05-05 08:39:51.000000000 +0000
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/base/options.h
@@ -180,7 +180,7 @@
 // absl::variant is a typedef of std::variant, use the feature macro
 // ABSL_USES_STD_VARIANT.
 
-#define ABSL_OPTION_USE_STD_VARIANT 2
+#define ABSL_OPTION_USE_STD_VARIANT 0
 
 
 // ABSL_OPTION_USE_INLINE_NAMESPACE
