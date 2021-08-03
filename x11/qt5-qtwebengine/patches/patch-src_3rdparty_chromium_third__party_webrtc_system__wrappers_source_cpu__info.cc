$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_system__wrappers_source_cpu__info.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/webrtc/system_wrappers/source/cpu_info.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/system_wrappers/source/cpu_info.cc
@@ -16,6 +16,8 @@
 #include <unistd.h>
 #elif defined(WEBRTC_MAC)
 #include <sys/sysctl.h>
+#elif defined(WEBRTC_BSD)
+#include <sys/sysctl.h>
 #elif defined(WEBRTC_FUCHSIA)
 #include <zircon/syscalls.h>
 #endif
@@ -36,7 +38,10 @@ static int DetectNumberOfCores() {
     RTC_LOG(LS_ERROR) << "Failed to get number of cores";
     number_of_cores = 1;
   }
-#elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS) || defined(WEBRTC_BSD)
+#if !defined(HW_AVAILCPU) && defined(HW_NCPUONLINE)
+#define HW_AVAILCPU HW_NCPUONLINE
+#endif
   int name[] = {CTL_HW, HW_AVAILCPU};
   size_t size = sizeof(number_of_cores);
   if (0 != sysctl(name, 2, &number_of_cores, &size, NULL, 0)) {
