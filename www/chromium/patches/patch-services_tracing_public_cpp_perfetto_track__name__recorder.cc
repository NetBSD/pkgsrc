$NetBSD: patch-services_tracing_public_cpp_perfetto_track__name__recorder.cc,v 1.2 2025/09/08 13:24:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/tracing/public/cpp/perfetto/track_name_recorder.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ services/tracing/public/cpp/perfetto/track_name_recorder.cc
@@ -51,7 +51,7 @@ void FillThreadTrack(const perfetto::Thr
   if (thread_type != ChromeThreadDescriptor::THREAD_UNSPECIFIED) {
     desc.mutable_chrome_thread()->set_thread_type(thread_type);
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   if (base::GetCurrentProcId() !=
       base::trace_event::TraceLog::GetInstance()->process_id()) {
     desc.mutable_chrome_thread()->set_is_sandboxed_tid(true);
