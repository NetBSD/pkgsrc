$NetBSD: patch-third__party_webrtc_rtc__base_cpu__info.cc,v 1.1 2025/08/13 07:44:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/cpu_info.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ third_party/webrtc/rtc_base/cpu_info.cc
@@ -22,7 +22,9 @@
 #elif defined(WEBRTC_FUCHSIA)
 #include <zircon/syscalls.h>
 #elif defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <features.h>
+#endif
 #include <stdlib.h>
 #include <string.h>  // IWYU pragma: keep
 #include <unistd.h>
