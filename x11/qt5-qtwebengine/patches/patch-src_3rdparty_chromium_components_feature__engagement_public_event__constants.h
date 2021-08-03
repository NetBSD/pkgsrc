$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_event__constants.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/event_constants.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/event_constants.h
@@ -14,7 +14,7 @@ namespace events {
 
 // Desktop and IOS.
 #if defined(OS_IOS) || defined(OS_WIN) || defined(OS_MACOSX) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
@@ -23,7 +23,7 @@ extern const char kNewTabOpened[];
 
 // Desktop
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // All conditions for reopen closed tab IPH were met. Since this IPH needs to
 // track user events (opening/closing tabs, focusing the omnibox, etc) on the
 // second level, it must be done manually.
