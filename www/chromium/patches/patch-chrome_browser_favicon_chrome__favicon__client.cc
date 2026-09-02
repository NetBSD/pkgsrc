$NetBSD: patch-chrome_browser_favicon_chrome__favicon__client.cc,v 1.17 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/favicon/chrome_favicon_client.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/favicon/chrome_favicon_client.cc
@@ -15,7 +15,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -48,7 +48,7 @@ bool ChromeFaviconClient::IsNativeApplic
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.SchemeIs(webapps::kIsolatedAppScheme)) {
     return true;
   }
