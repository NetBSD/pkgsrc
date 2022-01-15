$NetBSD: patch-third__party_libwebrtc_system__wrappers_source_cpu__features__linux.cc,v 1.1 2022/01/15 15:57:38 ryoon Exp $

* Fix build under NetBSD at least.

--- third_party/libwebrtc/system_wrappers/source/cpu_features_linux.cc.orig	2021-12-28 21:40:10.000000000 +0000
+++ third_party/libwebrtc/system_wrappers/source/cpu_features_linux.cc
@@ -8,7 +8,9 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
+#if !defined(__NetBSD__)
 #include <features.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 
