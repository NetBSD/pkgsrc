$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_event__constants.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/event_constants.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/event_constants.cc
@@ -12,13 +12,13 @@ namespace feature_engagement {
 namespace events {
 
 #if defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 #endif  // defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) ||
         // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kReopenTabConditionsMet[] = "reopen_tab_conditions_met";
 const char kTabReopened[] = "tab_reopened";
 
