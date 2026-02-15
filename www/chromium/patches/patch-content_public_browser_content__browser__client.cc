$NetBSD: patch-content_public_browser_content__browser__client.cc,v 1.15 2026/02/15 09:04:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/browser/content_browser_client.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ content/public/browser/content_browser_client.cc
@@ -1423,7 +1423,7 @@ bool ContentBrowserClient::ShouldRunOutO
 // that can be adequately sandboxed.
 // Currently Android's network service will not run out of process or sandboxed,
 // so OutOfProcessSystemDnsResolution is not currently enabled on Android.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
