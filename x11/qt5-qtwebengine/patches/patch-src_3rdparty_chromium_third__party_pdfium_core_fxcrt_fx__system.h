$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_core_fxcrt_fx__system.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_system.h.orig	2020-07-15 19:01:38.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_system.h
@@ -26,7 +26,7 @@
 #define _FX_PLATFORM_ _FX_PLATFORM_WINDOWS_
 #elif defined(_WIN64)
 #define _FX_PLATFORM_ _FX_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
 #define _FX_PLATFORM_ _FX_PLATFORM_LINUX_
 #elif defined(__APPLE__)
 #define _FX_PLATFORM_ _FX_PLATFORM_APPLE_
