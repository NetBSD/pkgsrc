$NetBSD: patch-src_3rdparty_chromium_net_url__request_url__request__context.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/url_request/url_request_context.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/net/url_request/url_request_context.cc
@@ -128,7 +128,7 @@ const HttpNetworkSessionContext* URLRequ
   return &network_session->context();
 }
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
