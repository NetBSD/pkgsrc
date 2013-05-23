$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable__posix.cc,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable_posix.cc.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable_posix.cc
@@ -79,7 +79,7 @@ bool ConditionVariablePosix::SleepCS(Cri
                                      unsigned long max_time_inMS) {
   const unsigned long INFINITE =  0xFFFFFFFF;
   const int MILLISECONDS_PER_SECOND = 1000;
-#ifndef WEBRTC_LINUX
+#if !defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
   const int MICROSECONDS_PER_MILLISECOND = 1000;
 #endif
   const int NANOSECONDS_PER_SECOND = 1000000000;
