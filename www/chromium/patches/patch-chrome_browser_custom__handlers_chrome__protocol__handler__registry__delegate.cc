$NetBSD: patch-chrome_browser_custom__handlers_chrome__protocol__handler__registry__delegate.cc,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/custom_handlers/chrome_protocol_handler_registry_delegate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/custom_handlers/chrome_protocol_handler_registry_delegate.cc
@@ -68,7 +68,7 @@ void ChromeProtocolHandlerRegistryDelega
 // If true default protocol handlers will be removed if the OS level
 // registration for a protocol is no longer Chrome.
 bool ChromeProtocolHandlerRegistryDelegate::ShouldRemoveHandlersNotInOS() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // We don't do this on Linux as the OS registration there is not reliable,
   // and Chrome OS doesn't have any notion of OS registration.
   // TODO(benwells): When Linux support is more reliable remove this
