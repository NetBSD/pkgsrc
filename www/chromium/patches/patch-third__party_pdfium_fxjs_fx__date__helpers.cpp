$NetBSD: patch-third__party_pdfium_fxjs_fx__date__helpers.cpp,v 1.1 2025/02/06 09:58:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/pdfium/fxjs/fx_date_helpers.cpp
@@ -39,6 +39,11 @@ double GetLocalTZA() {
     return 0;
   time_t t = 0;
   FXSYS_time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   FXSYS_localtime(&t);
 #if BUILDFLAG(IS_WIN)
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -47,6 +52,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
