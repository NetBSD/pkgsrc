$NetBSD: patch-src_3rdparty_chromium_base_i18n_icu__util.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/i18n/icu_util.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/i18n/icu_util.cc
@@ -49,7 +49,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !BUILDFLAG(IS_CHROMECAST))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMECAST))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
 
@@ -345,7 +345,7 @@ void InitializeIcuTimeZone() {
       fuchsia::IntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !BUILDFLAG(IS_CHROMECAST)
+#elif (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
