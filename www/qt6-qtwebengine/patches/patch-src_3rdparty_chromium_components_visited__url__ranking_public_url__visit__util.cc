$NetBSD: patch-src_3rdparty_chromium_components_visited__url__ranking_public_url__visit__util.cc,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/visited_url_ranking/public/url_visit_util.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/components/visited_url_ranking/public/url_visit_util.cc
@@ -66,7 +66,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
