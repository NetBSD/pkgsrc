$NetBSD: patch-third__party_libwebrtc_rtc__base_memory__usage.cc,v 1.4 2025/09/26 23:15:49 ryoon Exp $

--- third_party/libwebrtc/rtc_base/memory_usage.cc.orig	2025-09-10 12:13:46.353394466 +0000
+++ third_party/libwebrtc/rtc_base/memory_usage.cc
@@ -12,7 +12,7 @@
 
 #include <cstdint>
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include <unistd.h>
 
 #include <cstdio>
@@ -34,7 +34,8 @@
 namespace webrtc {
 
 int64_t GetProcessResidentSizeBytes() {
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
+ #include <unistd.h>
   FILE* file = fopen("/proc/self/statm", "r");
   if (file == nullptr) {
     RTC_LOG(LS_ERROR) << "Failed to open /proc/self/statm";
