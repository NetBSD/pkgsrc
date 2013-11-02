$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable.cc,v 1.3 2013/11/02 22:57:55 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc.orig	2013-10-25 22:27:35.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc
@@ -17,6 +17,8 @@
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <pthread.h>
 #include "webrtc/system_wrappers/source/condition_variable_posix.h"
+#else
+#include <stddef.h>  // for NULL
 #endif
 
 namespace webrtc {
