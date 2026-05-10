$NetBSD: patch-chrome_browser_feedback_show__feedback__page.cc,v 1.1 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/feedback/show_feedback_page.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/feedback/show_feedback_page.cc
@@ -256,7 +256,7 @@ bool CanShowFeedback(const Profile* prof
     return false;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(switches::kDisableU18FeedbackDesktop)) {
     return true;
   }
