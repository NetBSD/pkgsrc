$NetBSD: patch-chrome_browser_enterprise_chrome__browser__main__extra__parts__enterprise.cc,v 1.4 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.cc
@@ -7,7 +7,7 @@
 #include "components/enterprise/buildflags/buildflags.h"
 #include "content/public/browser/browser_thread.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
 #include "chrome/browser/enterprise/connectors/analysis/content_analysis_sdk_manager.h"  // nogncheck
 #include "chrome/browser/enterprise/connectors/connectors_service.h"  // nogncheck
@@ -53,7 +53,7 @@ ChromeBrowserMainExtraPartsEnterprise::C
 ChromeBrowserMainExtraPartsEnterprise::
     ~ChromeBrowserMainExtraPartsEnterprise() = default;
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
 void ChromeBrowserMainExtraPartsEnterprise::PostProfileInit(
     Profile* profile,
