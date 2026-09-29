$NetBSD: patch-chrome_browser_media_webrtc_desktop__media__picker__controller.cc,v 1.27 2026/09/29 07:42:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -101,7 +101,7 @@ bool DesktopMediaPickerController::IsSys
             base::FeatureList::IsEnabled(
                 media::kMacCatapLoopbackAudioForScreenShare));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
