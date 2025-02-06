$NetBSD: patch-third__party_perfetto_src_tracing_track.cc,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/tracing/track.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/src/tracing/track.cc
@@ -60,8 +60,9 @@ protos::gen::TrackDescriptor ProcessTrac
   auto desc = Track::Serialize();
   auto pd = desc.mutable_process();
   pd->set_pid(static_cast<int32_t>(pid));
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string cmdline;
   if (base::ReadFile("/proc/self/cmdline", &cmdline)) {
     // Since cmdline is a zero-terminated list of arguments, this ends up
@@ -155,7 +156,7 @@ namespace internal {
 namespace {
 
 uint64_t GetProcessStartTime() {
-#if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string stat;
   if (!base::ReadFile("/proc/self/stat", &stat))
     return 0u;
