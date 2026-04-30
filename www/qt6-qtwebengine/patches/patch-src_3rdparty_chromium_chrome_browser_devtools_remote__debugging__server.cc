$NetBSD: patch-src_3rdparty_chromium_chrome_browser_devtools_remote__debugging__server.cc,v 1.1 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/devtools/remote_debugging_server.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/devtools/remote_debugging_server.cc
@@ -42,7 +42,7 @@ namespace {
 
 bool g_tethering_enabled = false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool g_enable_default_user_data_dir_check_for_chromium_branding_for_testing =
     false;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -114,7 +114,7 @@ IsRemoteDebuggingAllowed(const std::opti
     return base::unexpected(
         RemoteDebuggingServer::NotStartedReason::kDisabledByPolicy);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   constexpr bool default_user_data_dir_check_enabled = true;
 #else
@@ -140,7 +140,7 @@ void RemoteDebuggingServer::EnableTether
   g_tethering_enabled = true;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void RemoteDebuggingServer::EnableDefaultUserDataDirCheckForTesting() {
   g_enable_default_user_data_dir_check_for_chromium_branding_for_testing = true;
