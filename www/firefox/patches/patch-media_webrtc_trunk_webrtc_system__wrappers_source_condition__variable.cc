$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable.cc,v 1.2 2013/09/19 12:37:50 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc.orig	2013-09-10 03:43:47.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc
@@ -16,6 +16,8 @@
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <pthread.h>
 #include "condition_variable_posix.h"
+#else
+#include <stddef.h>  // for NULL
 #endif
 
 namespace webrtc {
