$NetBSD: patch-src_3rdparty_chromium_chrome_browser_devtools_devtools__eye__dropper.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/browser/devtools/devtools_eye_dropper.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/devtools/devtools_eye_dropper.cc
@@ -163,7 +163,7 @@ void DevToolsEyeDropper::UpdateCursor() 
 // magnified projection only with centered hotspot.
 // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
