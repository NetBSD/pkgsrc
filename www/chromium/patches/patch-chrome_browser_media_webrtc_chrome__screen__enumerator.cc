$NetBSD: patch-chrome_browser_media_webrtc_chrome__screen__enumerator.cc,v 1.32 2026/11/08 15:38:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/chrome_screen_enumerator.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/media/webrtc/chrome_screen_enumerator.cc
@@ -21,7 +21,7 @@
 #if BUILDFLAG(IS_CHROMEOS)
 #include "ash/shell.h"
 #include "ui/aura/window.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/functional/callback.h"
 #include "content/public/browser/desktop_capture.h"
 #endif
@@ -32,7 +32,7 @@ base::LazyInstance<std::vector<raw_ptr<a
     DestructorAtExit root_windows_for_testing_ = LAZY_INSTANCE_INITIALIZER;
 }  // namespace
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace {
 base::LazyInstance<std::unique_ptr<webrtc::DesktopCapturer>>::DestructorAtExit
     g_desktop_capturer_for_testing = LAZY_INSTANCE_INITIALIZER;
@@ -80,7 +80,7 @@ blink::mojom::StreamDevicesSetPtr Enumer
   return stream_devices_set;
 }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 blink::mojom::StreamDevicesSetPtr EnumerateScreens(
     blink::mojom::MediaStreamType stream_type) {
   CHECK_CURRENTLY_ON(content::BrowserThread::UI, base::NotFatalUntil::M161);
@@ -133,7 +133,7 @@ void ChromeScreenEnumerator::SetRootWind
   root_windows_for_testing_.Get() = std::move(root_windows);
 }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeScreenEnumerator::SetDesktopCapturerForTesting(
     std::unique_ptr<webrtc::DesktopCapturer> capturer) {
   g_desktop_capturer_for_testing.Get() = std::move(capturer);
@@ -146,7 +146,7 @@ void ChromeScreenEnumerator::EnumerateSc
     ScreensCallback screens_callback) const {
   CHECK_CURRENTLY_ON(content::BrowserThread::IO, base::NotFatalUntil::M161);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   content::GetUIThreadTaskRunner({})->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(::EnumerateScreens, stream_type),
       base::BindOnce(
