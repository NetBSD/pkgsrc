$NetBSD: patch-components_safe__browsing_core_browser_db_sb__protocol__manager__util.cc,v 1.5 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc
@@ -207,7 +207,7 @@ std::ostream& operator<<(std::ostream& o
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
