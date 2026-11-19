$NetBSD: patch-remoting_host_base_desktop__environment__options.cc,v 1.33 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/base/desktop_environment_options.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/base/desktop_environment_options.cc
@@ -117,7 +117,7 @@ bool DesktopEnvironmentOptions::capture_
   // TODO(joedow): Determine whether we can migrate additional platforms to
   // using the DesktopCaptureWrapper instead of the DesktopCaptureProxy. Then
   // clean up DesktopCapturerProxy::Core::CreateCapturer().
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return capture_video_on_dedicated_thread_;
 #else
   return false;
