$NetBSD: patch-chrome_browser_ui_webui_user__education__internals_user__education__internals__page__handler__impl.cc,v 1.13 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/user_education_internals/user_education_internals_page_handler_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/webui/user_education_internals/user_education_internals_page_handler_impl.cc
@@ -49,7 +49,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/resource_path.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_navigator_params.h"
 #include "net/base/url_util.h"
@@ -89,7 +89,7 @@ user_education::NewBadgeRegistry* GetNew
 }
 
 whats_new::WhatsNewRegistry* GetWhatsNewRegistry() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process->GetFeatures()->whats_new_registry();
 #else
   return nullptr;
@@ -913,7 +913,7 @@ void UserEducationInternalsPageHandlerIm
 }
 
 void UserEducationInternalsPageHandlerImpl::LaunchWhatsNewStaging() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GURL url = net::AppendQueryParameter(GURL(chrome::kChromeUIWhatsNewURL),
                                        "staging", "true");
   NavigateParams params(profile_, url, ui::PAGE_TRANSITION_TYPED);
