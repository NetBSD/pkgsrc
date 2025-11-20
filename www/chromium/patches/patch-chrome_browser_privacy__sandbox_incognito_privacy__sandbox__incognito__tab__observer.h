$NetBSD: patch-chrome_browser_privacy__sandbox_incognito_privacy__sandbox__incognito__tab__observer.h,v 1.2 2025/11/20 08:36:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/privacy_sandbox/incognito/privacy_sandbox_incognito_tab_observer.h.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/privacy_sandbox/incognito/privacy_sandbox_incognito_tab_observer.h
@@ -23,7 +23,7 @@ class PrivacySandboxIncognitoTabObserver
 
  private:
   bool IsNewTabPage(const GURL& url);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsWhatsNewPage(const GURL& url);
 #endif
 };
