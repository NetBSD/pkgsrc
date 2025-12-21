$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_html_canvas_canvas__async__blob__creator.cc,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -55,7 +55,7 @@ constexpr base::TimeDelta kEncodeRowSlac
 
 /* The value is based on user statistics on Nov 2017. */
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_WIN))
+     BUILDFLAG(IS_WIN)) || BUILDFLAG(IS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
