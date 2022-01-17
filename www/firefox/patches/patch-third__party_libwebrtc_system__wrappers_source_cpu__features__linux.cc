$NetBSD: patch-third__party_libwebrtc_system__wrappers_source_cpu__features__linux.cc,v 1.2 2022/01/17 10:22:54 tnn Exp $

* Fix build under NetBSD at least.

--- third_party/libwebrtc/system_wrappers/source/cpu_features_linux.cc.orig	2022-01-13 19:26:15.000000000 +0000
+++ third_party/libwebrtc/system_wrappers/source/cpu_features_linux.cc
@@ -8,7 +8,9 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
+#if !defined(__NetBSD__)
 #include <features.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 
@@ -30,7 +32,7 @@
 #include "rtc_base/system/arch.h"
 #include "system_wrappers/include/cpu_features_wrapper.h"
 
-#if defined(WEBRTC_ARCH_ARM_FAMILY)
+#if defined(WEBRTC_ARCH_ARM_FAMILY) && defined(__linux__)
 #include <asm/hwcap.h>
 
 namespace webrtc {
