$NetBSD: patch-src_3rdparty_chromium_content_public_browser_content__browser__client.cc,v 1.1 2025/12/21 09:38:28 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/public/browser/content_browser_client.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/public/browser/content_browser_client.cc
@@ -1343,7 +1343,7 @@ bool ContentBrowserClient::ShouldRunOutO
 // that can be adequately sandboxed.
 // Currently Android's network service will not run out of process or sandboxed,
 // so OutOfProcessSystemDnsResolution is not currently enabled on Android.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
