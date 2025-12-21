$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_event__constants.cc,v 1.1 2025/12/21 09:38:22 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/feature_engagement/public/event_constants.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/event_constants.cc
@@ -11,7 +11,7 @@ namespace feature_engagement {
 namespace events {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kReadingListItemAdded[] = "reading_list_item_added";
