$NetBSD: patch-remoting_host_base_desktop__environment__options.cc,v 1.17 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/base/desktop_environment_options.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ remoting/host/base/desktop_environment_options.cc
@@ -109,7 +109,7 @@ bool DesktopEnvironmentOptions::capture_
   // TODO(joedow): Determine whether we can migrate additional platforms to
   // using the DesktopCaptureWrapper instead of the DesktopCaptureProxy. Then
   // clean up DesktopCapturerProxy::Core::CreateCapturer().
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return capture_video_on_dedicated_thread_;
 #else
   return false;
