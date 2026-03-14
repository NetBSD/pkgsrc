$NetBSD: patch-components_visited__url__ranking_public_url__visit__util.cc,v 1.16 2026/03/14 12:40:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/visited_url_ranking/public/url_visit_util.cc.orig	2026-03-11 22:12:25.000000000 +0000
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
