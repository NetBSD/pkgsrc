$NetBSD: patch-components_security__interstitials_content_utils.cc,v 1.26 2026/09/22 13:41:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/security_interstitials/content/utils.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/security_interstitials/content/utils.cc
@@ -37,7 +37,7 @@ void LaunchDateAndTimeSettings() {
 #if BUILDFLAG(IS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
