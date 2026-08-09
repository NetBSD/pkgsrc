$NetBSD: patch-chrome_browser_notifications_notification__platform__bridge__delegator.cc,v 1.24 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2026-08-05 20:17:42.000000000 +0000
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
