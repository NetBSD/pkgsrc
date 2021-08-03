$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxcrt_cfx__datetime.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2020-07-15 19:01:38.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -10,7 +10,7 @@
 #include "core/fxcrt/fx_system.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_ASMJS) || defined(__wasm__)
+    defined(OS_ASMJS) || defined(__wasm__) || defined(OS_BSD)
 #include <sys/time.h>
 #include <time.h>
 #endif
