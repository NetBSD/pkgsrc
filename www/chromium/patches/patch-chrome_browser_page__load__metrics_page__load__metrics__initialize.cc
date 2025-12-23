$NetBSD: patch-chrome_browser_page__load__metrics_page__load__metrics__initialize.cc,v 1.5 2025/12/23 13:22:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/page_load_metrics/page_load_metrics_initialize.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/page_load_metrics/page_load_metrics_initialize.cc
@@ -70,7 +70,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -351,7 +351,7 @@ bool PageLoadMetricsEmbedder::IsInternal
 
 bool PageLoadMetricsEmbedder::ShouldObserveScheme(std::string_view scheme) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return scheme == webapps::kIsolatedAppScheme;
 #else   // !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS))
