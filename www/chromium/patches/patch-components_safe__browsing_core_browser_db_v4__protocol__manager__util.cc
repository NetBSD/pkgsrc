$NetBSD: patch-components_safe__browsing_core_browser_db_v4__protocol__manager__util.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc
@@ -112,7 +112,7 @@ std::ostream& operator<<(std::ostream& o
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
