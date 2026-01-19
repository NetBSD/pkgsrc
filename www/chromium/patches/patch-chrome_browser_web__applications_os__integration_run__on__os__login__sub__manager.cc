$NetBSD: patch-chrome_browser_web__applications_os__integration_run__on__os__login__sub__manager.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/run_on_os_login_sub_manager.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/web_applications/os_integration/run_on_os_login_sub_manager.cc
@@ -55,7 +55,7 @@ proto::os_state::RunOnOsLogin::Mode Conv
 // different from other platforms, see web_app_run_on_os_login_manager.h for
 // more info.
 bool DoesRunOnOsLoginRequireExecution() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kDesktopPWAsRunOnOsLogin);
 #else
   return false;
