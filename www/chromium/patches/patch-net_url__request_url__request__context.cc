$NetBSD: patch-net_url__request_url__request__context.cc,v 1.31 2026/10/23 15:05:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/url_request/url_request_context.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ net/url_request/url_request_context.cc
@@ -130,7 +130,7 @@ const HttpNetworkSessionContext* URLRequ
   return &network_session->context();
 }
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
