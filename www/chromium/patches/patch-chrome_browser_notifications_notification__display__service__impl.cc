$NetBSD: patch-chrome_browser_notifications_notification__display__service__impl.cc,v 1.17 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -31,7 +31,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/sharing/sharing_notification_handler.h"
 #endif
@@ -64,7 +64,7 @@ NotificationDisplayServiceImpl* Notifica
 // static
 void NotificationDisplayServiceImpl::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAllowSystemNotifications, true);
 #endif
 }
@@ -80,7 +80,7 @@ NotificationDisplayServiceImpl::Notifica
                            std::make_unique<PersistentNotificationHandler>());
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     AddNotificationHandler(
         NotificationHandler::Type::SEND_TAB_TO_SELF,
         std::make_unique<send_tab_to_self::DesktopNotificationHandler>(
@@ -88,7 +88,7 @@ NotificationDisplayServiceImpl::Notifica
 #endif
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_WIN)) &&                                                 \
+     BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) &&                            \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
     AddNotificationHandler(
         NotificationHandler::Type::TAILORED_SECURITY,
