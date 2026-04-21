$NetBSD: patch-chrome_browser_ui_url__identity.cc,v 1.10 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/url_identity.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/url_identity.cc
@@ -17,7 +17,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -90,7 +90,7 @@ UrlIdentity CreateChromeExtensionIdentit
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 UrlIdentity CreateIsolatedWebAppIdentityFromUrl(Profile* profile,
                                                 const GURL& url,
                                                 const FormatOptions& options) {
@@ -151,7 +151,7 @@ UrlIdentity UrlIdentity::CreateFromUrl(P
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.SchemeIs(webapps::kIsolatedAppScheme)) {
     DCHECK(allowed_types.Has(Type::kIsolatedWebApp));
     return CreateIsolatedWebAppIdentityFromUrl(profile, url, options);
