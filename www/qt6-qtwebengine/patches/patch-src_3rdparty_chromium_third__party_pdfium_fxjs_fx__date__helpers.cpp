$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_fxjs_fx__date__helpers.cpp,v 1.1 2025/12/21 09:38:43 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/fx_date_helpers.cpp
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
@@ -264,7 +270,7 @@ double FX_MakeTime(int nHour, int nMin, 
 }
 
 double FX_MakeDate(double day, double time) {
-  if (!isfinite(day) || !isfinite(time))
+  if (!std::isfinite(day) || !std::isfinite(time))
     return nan("");
 
   return day * 86400000 + time;
@@ -543,7 +549,7 @@ ConversionStatus FX_ParseDateUsingFormat
 
   dt = FX_MakeDate(FX_MakeDay(nYear, nMonth - 1, nDay),
                    FX_MakeTime(nHour, nMin, nSec, 0));
-  if (isnan(dt))
+  if (std::isnan(dt))
     return ConversionStatus::kBadDate;
 
   *result = dt;
