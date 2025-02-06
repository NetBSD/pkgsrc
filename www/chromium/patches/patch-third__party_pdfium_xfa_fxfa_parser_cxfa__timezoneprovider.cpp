$NetBSD: patch-third__party_pdfium_xfa_fxfa_parser_cxfa__timezoneprovider.cpp,v 1.1 2025/02/06 09:58:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp
@@ -6,12 +6,16 @@
 
 #include "xfa/fxfa/parser/cxfa_timezoneprovider.h"
 
+#include <stdint.h>
 #include <stdlib.h>
 #include <time.h>
 
 #include "build/build_config.h"
 
 static bool g_bProviderTimeZoneSet = false;
+#if defined(OS_FREEBSD)
+static long g_lTimeZoneOffset = 0;
+#endif
 
 #if BUILDFLAG(IS_WIN)
 #define TIMEZONE _timezone
@@ -24,9 +28,21 @@ static bool g_bProviderTimeZoneSet = fal
 CXFA_TimeZoneProvider::CXFA_TimeZoneProvider() {
   if (!g_bProviderTimeZoneSet) {
     g_bProviderTimeZoneSet = true;
+#if defined(OS_FREEBSD)
+    time_t now = time(nullptr);
+    struct tm tm = {};
+
+    localtime_r(&now, &tm);
+    g_lTimeZoneOffset = tm.tm_gmtoff;
+#else
     TZSET();
+#endif
   }
+#if defined(OS_FREEBSD)
+  tz_minutes_ = static_cast<int8_t>((abs(g_lTimeZoneOffset) % 3600) / 60);
+#else
   tz_minutes_ = TIMEZONE / -60;
+#endif
 }
 
 CXFA_TimeZoneProvider::~CXFA_TimeZoneProvider() = default;
