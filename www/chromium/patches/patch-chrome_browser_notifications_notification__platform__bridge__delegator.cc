$NetBSD: patch-chrome_browser_notifications_notification__platform__bridge__delegator.cc,v 1.8 2025/10/16 19:43:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -55,7 +55,7 @@ bool SystemNotificationsEnabled(Profile*
 #elif BUILDFLAG(IS_WIN)
   return NotificationPlatformBridgeWin::SystemNotificationEnabled();
 #else
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
