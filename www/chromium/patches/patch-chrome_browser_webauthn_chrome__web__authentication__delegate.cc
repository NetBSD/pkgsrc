$NetBSD: patch-chrome_browser_webauthn_chrome__web__authentication__delegate.cc,v 1.1 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/chrome_web_authentication_delegate.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/webauthn/chrome_web_authentication_delegate.cc
@@ -70,7 +70,7 @@
 #include "url/url_constants.h"
 #include "url/url_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_service.h"
 #endif
 
@@ -413,7 +413,7 @@ content::WebAuthenticationRequestProxy*
 ChromeWebAuthenticationDelegate::MaybeGetRequestProxy(
     content::BrowserContext* browser_context,
     const url::Origin& caller_origin) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The webAuthenticationProxy extension API is supported on Win/Mac/Linux.
   auto* service = extensions::WebAuthenticationProxyService::GetIfProxyAttached(
       Profile::FromBrowserContext(browser_context));
