$NetBSD: patch-chrome_browser_feedback_show__feedback__page.h,v 1.1 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/feedback/show_feedback_page.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/feedback/show_feedback_page.h
@@ -17,7 +17,7 @@ class Profile;
 
 namespace chrome {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // These values are persisted to logs. Entries should not be renumbered and
 // numeric values should never be reused.
 //
