$NetBSD: patch-chrome_browser_media_webrtc_desktop__media__picker__controller.cc,v 1.26 2026/09/22 13:41:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-09-14 22:17:16.000000000 +0000
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
