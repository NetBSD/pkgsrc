$NetBSD: patch-components_visited__url__ranking_public_url__visit__util.cc,v 1.30 2026/10/16 15:30:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/visited_url_ranking/public/url_visit_util.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/visited_url_ranking/public/url_visit_util.cc
@@ -68,7 +68,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
