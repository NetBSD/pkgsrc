$NetBSD: patch-chrome_browser_devtools_remote__debugging__server.cc,v 1.2 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/remote_debugging_server.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/devtools/remote_debugging_server.cc
@@ -109,7 +109,7 @@ IsRemoteDebuggingAllowed(const std::opti
         RemoteDebuggingServer::NotStartedReason::kDisabledByPolicy);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kDevToolsDebuggingRestrictions) &&
       is_default_user_data_dir.value_or(true)) {
     return base::unexpected(
