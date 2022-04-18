$NetBSD: patch-src_3rdparty_chromium_third__party_abseil-cpp_absl_time_internal_cctz_src_time__zone__format.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	2022-03-12 18:05:39.192228709 +0000
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc
@@ -18,12 +18,6 @@
 #endif
 #endif
 
-#if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE)
-#define _XOPEN_SOURCE  // Definedness suffices for strptime.
-#endif
-#endif
-
 #include "absl/base/config.h"
 #include "absl/time/internal/cctz/include/cctz/time_zone.h"
 
