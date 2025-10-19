$NetBSD: patch-third__party_libwebrtc_rtc__base_memory__usage.cc,v 1.1 2025/10/19 11:56:57 leot Exp $

--- third_party/libwebrtc/rtc_base/memory_usage.cc.orig	2025-05-21 12:27:20.023110519 +0000
+++ third_party/libwebrtc/rtc_base/memory_usage.cc
@@ -10,7 +10,7 @@
 
 #include "rtc_base/memory_usage.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include <unistd.h>
 
 #include <cstdio>
@@ -32,7 +32,7 @@
 namespace rtc {
 
 int64_t GetProcessResidentSizeBytes() {
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   FILE* file = fopen("/proc/self/statm", "r");
   if (file == nullptr) {
     RTC_LOG(LS_ERROR) << "Failed to open /proc/self/statm";
