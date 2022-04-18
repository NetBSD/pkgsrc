$NetBSD: patch-src_3rdparty_chromium_components_security__interstitials_content_utils.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/security_interstitials/content/utils.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/security_interstitials/content/utils.cc
@@ -31,7 +31,7 @@ void LaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
