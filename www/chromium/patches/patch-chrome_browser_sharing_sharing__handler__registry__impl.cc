$NetBSD: patch-chrome_browser_sharing_sharing__handler__registry__impl.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sharing/sharing_handler_registry_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/sharing/sharing_handler_registry_impl.cc
@@ -22,7 +22,7 @@
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/sharing/shared_clipboard/remote_copy_message_handler.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) BUILDFLAG(IS_CHROMEOS)
@@ -74,7 +74,7 @@ SharingHandlerRegistryImpl::SharingHandl
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sharing_device_registration->IsRemoteCopySupported()) {
     AddSharingHandler(
         std::make_unique<RemoteCopyMessageHandler>(profile),
