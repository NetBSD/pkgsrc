$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable.cc,v 1.2 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc.orig	2013-09-16 18:26:51.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc
@@ -16,6 +16,8 @@
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <pthread.h>
 #include "condition_variable_posix.h"
+#else
+#include <stddef.h>  // for NULL
 #endif
 
 namespace webrtc {
