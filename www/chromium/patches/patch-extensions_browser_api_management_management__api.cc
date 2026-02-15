$NetBSD: patch-extensions_browser_api_management_management__api.cc,v 1.15 2026/02/15 09:04:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/management/management_api.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ extensions/browser/api/management/management_api.cc
@@ -296,7 +296,7 @@ void AddExtensionInfo(const Extension* s
 
 bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
