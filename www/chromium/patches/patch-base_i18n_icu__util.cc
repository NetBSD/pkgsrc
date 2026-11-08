$NetBSD: patch-base_i18n_icu__util.cc,v 1.32 2026/11/08 15:38:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/i18n/icu_util.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ base/i18n/icu_util.cc
@@ -63,7 +63,7 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
@@ -337,7 +337,7 @@ void InitializeIcuTimeZone() {
       FuchsiaIntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif BUILDFLAG(IS_CHROMEOS) || \
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_ANDROID)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
