$NetBSD: patch-chrome_browser_devtools_remote__debugging__server.cc,v 1.13 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/remote_debugging_server.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/devtools/remote_debugging_server.cc
@@ -49,7 +49,7 @@ namespace {
 
 bool g_tethering_enabled = false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool g_enable_default_user_data_dir_check_for_chromium_branding_for_testing =
     false;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -179,7 +179,7 @@ IsRemoteDebuggingAllowed(const std::opti
     return base::unexpected(
         RemoteDebuggingServer::NotStartedReason::kDisabledByPolicy);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   constexpr bool default_user_data_dir_check_enabled = true;
 #else
@@ -300,7 +300,7 @@ void RemoteDebuggingServer::EnableTether
   g_tethering_enabled = true;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void RemoteDebuggingServer::EnableDefaultUserDataDirCheckForTesting() {
   g_enable_default_user_data_dir_check_for_chromium_branding_for_testing = true;
