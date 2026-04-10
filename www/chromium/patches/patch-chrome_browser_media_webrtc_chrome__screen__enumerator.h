$NetBSD: patch-chrome_browser_media_webrtc_chrome__screen__enumerator.h,v 1.17 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/chrome_screen_enumerator.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/media/webrtc/chrome_screen_enumerator.h
@@ -18,7 +18,7 @@
 namespace aura {
 class Window;
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace webrtc {
 class DesktopCapturer;
 }
@@ -39,7 +39,7 @@ class ChromeScreenEnumerator : public me
 #if BUILDFLAG(IS_CHROMEOS)
   static void SetRootWindowsForTesting(
       std::vector<raw_ptr<aura::Window, VectorExperimental>> root_windows);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static void SetDesktopCapturerForTesting(
       std::unique_ptr<webrtc::DesktopCapturer> capturer);
 #endif
