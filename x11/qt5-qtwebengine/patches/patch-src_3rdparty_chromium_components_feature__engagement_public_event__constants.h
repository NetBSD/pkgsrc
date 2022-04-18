$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_event__constants.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/event_constants.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/event_constants.h
@@ -13,7 +13,7 @@ namespace events {
 
 // Desktop and IOS.
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
@@ -22,7 +22,7 @@ extern const char kNewTabOpened[];
 
 // Desktop
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // A new tab was opened when 5 (or more) tabs were already open.
 extern const char kSixthTabOpened[];
 // The user made a new tab group.
