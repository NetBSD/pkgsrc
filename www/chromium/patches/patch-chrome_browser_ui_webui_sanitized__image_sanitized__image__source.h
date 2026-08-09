$NetBSD: patch-chrome_browser_ui_webui_sanitized__image_sanitized__image__source.h,v 1.6 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/sanitized_image/sanitized_image_source.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/webui/sanitized_image/sanitized_image_source.h
@@ -124,7 +124,7 @@ class SanitizedImageSource : public cont
     ~RequestAttributes();
 
     GURL image_url = GURL();
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool static_encode = true;
 #else
     bool static_encode = false;
