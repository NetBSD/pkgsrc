$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable.cc,v 1.3 2013/11/04 06:01:46 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc.orig	2013-10-29 01:21:06.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc
@@ -17,6 +17,8 @@
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <pthread.h>
 #include "webrtc/system_wrappers/source/condition_variable_posix.h"
+#else
+#include <stddef.h>  // for NULL
 #endif
 
 namespace webrtc {
