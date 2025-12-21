$NetBSD: patch-src_3rdparty_chromium_components_safe__browsing_core_browser_db_v4__protocol__manager__util.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc
@@ -119,7 +119,7 @@ std::ostream& operator<<(std::ostream& o
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
