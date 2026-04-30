$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_management_management__api.cc,v 1.2 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/browser/api/management/management_api.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/management/management_api.cc
@@ -284,7 +284,7 @@ void AddExtensionInfo(const Extension* s
 
 bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
