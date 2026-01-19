$NetBSD: patch-chrome_browser_ui_url__identity.cc,v 1.6 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/url_identity.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/url_identity.cc
@@ -17,7 +17,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -97,7 +97,7 @@ std::optional<webapps::AppId> GetIsolate
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 UrlIdentity CreateIsolatedWebAppIdentityFromUrl(Profile* profile,
                                                 const GURL& url,
                                                 const FormatOptions& options) {
@@ -155,7 +155,7 @@ UrlIdentity UrlIdentity::CreateFromUrl(P
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.SchemeIs(webapps::kIsolatedAppScheme)) {
     DCHECK(allowed_types.Has(Type::kIsolatedWebApp));
     return CreateIsolatedWebAppIdentityFromUrl(profile, url, options);
