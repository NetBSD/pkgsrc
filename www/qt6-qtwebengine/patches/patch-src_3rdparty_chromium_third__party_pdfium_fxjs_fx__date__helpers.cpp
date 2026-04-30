$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_fx__date__helpers.cpp,v 1.2 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/fx_date_helpers.cpp
@@ -41,6 +41,11 @@ double GetLocalTZA() {
   }
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
@@ -49,6 +54,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
@@ -278,7 +284,7 @@ double FX_MakeTime(int nHour, int nMin, 
 }
 
 double FX_MakeDate(double day, double time) {
-  if (!isfinite(day) || !isfinite(time)) {
+  if (!std::isfinite(day) || !std::isfinite(time)) {
     return nan("");
   }
 
@@ -565,7 +571,7 @@ ConversionStatus FX_ParseDateUsingFormat
 
   dt = FX_MakeDate(FX_MakeDay(nYear, nMonth - 1, nDay),
                    FX_MakeTime(nHour, nMin, nSec, 0));
-  if (isnan(dt)) {
+  if (std::isnan(dt)) {
     return ConversionStatus::kBadDate;
   }
 
