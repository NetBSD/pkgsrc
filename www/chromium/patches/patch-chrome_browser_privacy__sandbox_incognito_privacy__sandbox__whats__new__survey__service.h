$NetBSD: patch-chrome_browser_privacy__sandbox_incognito_privacy__sandbox__whats__new__survey__service.h,v 1.2 2025/11/20 08:36:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/privacy_sandbox/incognito/privacy_sandbox_whats_new_survey_service.h.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/privacy_sandbox/incognito/privacy_sandbox_whats_new_survey_service.h
@@ -16,7 +16,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "content/public/browser/web_contents.h"
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 #error This file should only be included on Win, Mac or Linux
 #endif
 
