$NetBSD: patch-src_3rdparty_chromium_base_i18n_icu__util.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/i18n/icu_util.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/i18n/icu_util.cc
@@ -49,7 +49,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
 
@@ -341,7 +341,7 @@ void InitializeIcuTimeZone() {
       fuchsia::IntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
