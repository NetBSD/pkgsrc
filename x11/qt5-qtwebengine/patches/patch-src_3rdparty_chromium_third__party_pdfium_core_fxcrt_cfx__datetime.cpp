$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxcrt_cfx__datetime.cpp,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -10,7 +10,7 @@
 #include "core/fxcrt/fx_system.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_APPLE) || defined(OS_ASMJS)
+    defined(OS_APPLE) || defined(OS_ASMJS) || defined(OS_BSD)
 #include <sys/time.h>
 #include <time.h>
 #endif
