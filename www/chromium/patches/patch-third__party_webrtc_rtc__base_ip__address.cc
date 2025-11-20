$NetBSD: patch-third__party_webrtc_rtc__base_ip__address.cc,v 1.10 2025/11/20 08:36:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/ip_address.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ third_party/webrtc/rtc_base/ip_address.cc
@@ -22,7 +22,8 @@
 #include "rtc_base/string_utils.h"
 
 #if defined(WEBRTC_POSIX)
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #include <netdb.h>
