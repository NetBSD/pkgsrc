$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_html_canvas_canvas__async__blob__creator.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -44,7 +44,7 @@ constexpr base::TimeDelta kEncodeRowSlac
 
 /* The value is based on user statistics on Nov 2017. */
 #if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-     defined(OS_WIN))
+     defined(OS_WIN)) || defined(OS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
