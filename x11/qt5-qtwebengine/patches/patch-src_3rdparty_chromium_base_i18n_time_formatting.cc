$NetBSD: patch-src_3rdparty_chromium_base_i18n_time_formatting.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

icu >= 68

--- src/3rdparty/chromium/base/i18n/time_formatting.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/base/i18n/time_formatting.cc
@@ -236,7 +236,7 @@ bool TimeDurationFormatWithSeconds(const
   icu::FieldPosition ignore(icu::FieldPosition::DONT_CARE);
   measure_format.formatMeasures(measures, 3, formatted, ignore, status);
   *out = i18n::UnicodeStringToString16(formatted);
-  return U_SUCCESS(status) == TRUE;
+  return U_SUCCESS(status) == true;
 }
 
 string16 DateIntervalFormat(const Time& begin_time,
