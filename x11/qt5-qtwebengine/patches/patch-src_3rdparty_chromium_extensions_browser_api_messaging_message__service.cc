$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_messaging_message__service.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/extensions/browser/api/messaging/message_service.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/messaging/message_service.cc
@@ -62,7 +62,7 @@ namespace {
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -397,7 +397,7 @@ void MessageService::OpenChannelToNative
     return;
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   bool has_permission = extension->permissions_data()->HasAPIPermission(
       APIPermission::kNativeMessaging);
   if (!has_permission) {
