$NetBSD: patch-remoting_protocol_webrtc__video__stream.cc,v 1.24 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/protocol/webrtc_video_stream.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/protocol/webrtc_video_stream.cc
@@ -255,7 +255,7 @@ WebrtcVideoStream::WebrtcVideoStream(con
     : session_options_(session_options) {
 // TODO: yuweih - Check if the other platforms can also be updated to run on a
 // dedicated thread.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   core_task_runner_ = base::ThreadPool::CreateSingleThreadTaskRunner(
       {base::TaskPriority::HIGHEST},
       base::SingleThreadTaskRunnerThreadMode::DEDICATED);
