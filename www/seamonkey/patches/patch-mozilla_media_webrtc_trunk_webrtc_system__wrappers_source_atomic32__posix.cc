$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_atomic32__posix.cc,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/atomic32_posix.cc.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/atomic32_posix.cc
@@ -12,7 +12,6 @@
 
 #include <assert.h>
 #include <inttypes.h>
-#include <malloc.h>
 
 #include "common_types.h"
 
