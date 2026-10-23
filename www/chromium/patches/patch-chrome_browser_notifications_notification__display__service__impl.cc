$NetBSD: patch-chrome_browser_notifications_notification__display__service__impl.cc,v 1.31 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -34,7 +34,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/sharing/sharing_notification_handler.h"
 #endif
 
@@ -67,7 +67,7 @@ NotificationDisplayServiceImpl* Notifica
 // static
 void NotificationDisplayServiceImpl::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAllowSystemNotifications, true);
 #endif
 }
@@ -83,7 +83,7 @@ NotificationDisplayServiceImpl::Notifica
                            std::make_unique<PersistentNotificationHandler>());
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_WIN)) &&                                                 \
+     BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) &&                                                 \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
     AddNotificationHandler(
         NotificationHandler::Type::TAILORED_SECURITY,
