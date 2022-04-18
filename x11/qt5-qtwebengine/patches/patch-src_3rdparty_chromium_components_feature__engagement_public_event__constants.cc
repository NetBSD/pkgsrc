$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_event__constants.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/event_constants.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/event_constants.cc
@@ -11,13 +11,13 @@ namespace feature_engagement {
 namespace events {
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 #endif  // defined(OS_WIN) || defined(OS_APPLE) ||
         // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kTabGroupCreated[] = "tab_group_created";
 
