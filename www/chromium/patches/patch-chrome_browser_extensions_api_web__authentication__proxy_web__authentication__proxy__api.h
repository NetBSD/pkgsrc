$NetBSD: patch-chrome_browser_extensions_api_web__authentication__proxy_web__authentication__proxy__api.h,v 1.7 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_api.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_api.h
@@ -15,7 +15,7 @@
 #include "extensions/browser/extension_function_histogram_value.h"
 
 // This API is limited to Win/Mac/Linux.
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 namespace extensions {
 
