$NetBSD: patch-chrome_browser_media_webrtc_desktop__media__picker__controller.cc,v 1.30 2026/10/16 15:30:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -112,7 +112,7 @@ bool DesktopMediaPickerController::IsSys
   } else {
     return media::IsMacCatapSystemLoopbackCaptureSupported();
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
