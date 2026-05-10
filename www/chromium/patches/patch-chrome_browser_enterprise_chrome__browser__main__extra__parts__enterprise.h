$NetBSD: patch-chrome_browser_enterprise_chrome__browser__main__extra__parts__enterprise.h,v 1.9 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h
@@ -25,7 +25,7 @@ class ChromeBrowserMainExtraPartsEnterpr
   ~ChromeBrowserMainExtraPartsEnterprise() override;
 
   // ChromeBrowserMainExtraParts:
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
   void PostProfileInit(Profile* profile, bool is_initial_profile) override;
 #endif
