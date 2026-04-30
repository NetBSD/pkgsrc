$NetBSD: patch-src_3rdparty_chromium_services_tracing_public_cpp_perfetto_track__name__recorder.cc,v 1.1 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/tracing/public/cpp/perfetto/track_name_recorder.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/services/tracing/public/cpp/perfetto/track_name_recorder.cc
@@ -51,7 +51,7 @@ void FillThreadTrack(const perfetto::Thr
   if (thread_type != ChromeThreadDescriptor::THREAD_UNSPECIFIED) {
     desc.mutable_chrome_thread()->set_thread_type(thread_type);
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   if (base::GetCurrentProcId() !=
       base::trace_event::TraceLog::GetInstance()->process_id()) {
     desc.mutable_chrome_thread()->set_is_sandboxed_tid(true);
