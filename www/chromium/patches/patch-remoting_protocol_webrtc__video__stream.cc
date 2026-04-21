$NetBSD: patch-remoting_protocol_webrtc__video__stream.cc,v 1.18 2026/04/21 15:21:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/protocol/webrtc_video_stream.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ remoting/protocol/webrtc_video_stream.cc
@@ -248,7 +248,7 @@ WebrtcVideoStream::WebrtcVideoStream(con
     : session_options_(session_options) {
 // TODO: yuweih - Check if the other platforms can also be updated to run on a
 // dedicated thread.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   core_task_runner_ = base::ThreadPool::CreateSingleThreadTaskRunner(
       {base::TaskPriority::HIGHEST},
       base::SingleThreadTaskRunnerThreadMode::DEDICATED);
