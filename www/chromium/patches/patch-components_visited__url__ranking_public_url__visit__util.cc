$NetBSD: patch-components_visited__url__ranking_public_url__visit__util.cc,v 1.2 2025/05/16 16:08:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/visited_url_ranking/public/url_visit_util.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/visited_url_ranking/public/url_visit_util.cc
@@ -67,7 +67,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
