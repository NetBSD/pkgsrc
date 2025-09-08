$NetBSD: patch-third__party_blink_renderer_core_html_canvas_canvas__async__blob__creator.cc,v 1.6 2025/09/08 13:24:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -52,7 +52,7 @@ constexpr base::TimeDelta kEncodeRowSlac
 
 /* The value is based on user statistics on Nov 2017. */
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_WIN))
+     BUILDFLAG(IS_WIN)) || BUILDFLAG(IS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
