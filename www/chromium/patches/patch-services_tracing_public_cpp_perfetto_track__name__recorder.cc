$NetBSD: patch-services_tracing_public_cpp_perfetto_track__name__recorder.cc,v 1.10 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/tracing/public/cpp/perfetto/track_name_recorder.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/tracing/public/cpp/perfetto/track_name_recorder.cc
@@ -53,7 +53,7 @@ void FillThreadTrack(const perfetto::Thr
     desc.mutable_chrome_thread()->set_thread_type(
         static_cast<int32_t>(thread_type));
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   if (base::GetCurrentProcId() !=
       base::trace_event::TraceLog::GetInstance()->process_id()) {
     desc.mutable_chrome_thread()->set_is_sandboxed_tid(true);
