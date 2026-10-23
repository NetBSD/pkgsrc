$NetBSD: patch-chrome_browser_sessions_session__service.cc,v 1.3 2026/10/23 15:05:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sessions/session_service.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/sessions/session_service.cc
@@ -120,7 +120,7 @@ class InstanceTracker : public base::Sup
 };
 
 bool ShouldTriggerSessionRestoreForBrowser(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kRespectShouldTriggerSessionRestoreOnDesktop) &&
       browser) {
