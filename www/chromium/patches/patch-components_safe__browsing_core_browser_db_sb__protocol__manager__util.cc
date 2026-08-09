$NetBSD: patch-components_safe__browsing_core_browser_db_sb__protocol__manager__util.cc,v 1.4 2026/08/09 06:31:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc
@@ -121,7 +121,7 @@ std::ostream& operator<<(std::ostream& o
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
