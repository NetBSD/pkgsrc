$NetBSD: patch-third__party_webrtc_rtc__base_ip__address.cc,v 1.1 2025/02/06 09:58:29 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/ip_address.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/webrtc/rtc_base/ip_address.cc
@@ -14,7 +14,8 @@
 #include <cstring>
 #include <string>
 #if defined(WEBRTC_POSIX)
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #ifndef __native_client__
