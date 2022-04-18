$NetBSD: patch-src_3rdparty_chromium_chrome_browser_custom__handlers_protocol__handler__registry.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/browser/custom_handlers/protocol_handler_registry.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/custom_handlers/protocol_handler_registry.cc
@@ -45,7 +45,7 @@ const ProtocolHandler& LookupHandler(
 // If true default protocol handlers will be removed if the OS level
 // registration for a protocol is no longer Chrome.
 bool ShouldRemoveHandlersNotInOS() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // We don't do this on Linux as the OS registration there is not reliable,
   // and Chrome OS doesn't have any notion of OS registration.
   // TODO(benwells): When Linux support is more reliable remove this
