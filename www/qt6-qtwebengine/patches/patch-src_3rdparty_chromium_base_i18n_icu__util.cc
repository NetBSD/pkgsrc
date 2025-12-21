$NetBSD: patch-src_3rdparty_chromium_base_i18n_icu__util.cc,v 1.1 2025/12/21 09:38:13 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/i18n/icu_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/i18n/icu_util.cc
@@ -52,7 +52,7 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
@@ -328,7 +328,7 @@ void InitializeIcuTimeZone() {
       FuchsiaIntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#elif BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
