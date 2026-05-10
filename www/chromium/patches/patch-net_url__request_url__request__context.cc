$NetBSD: patch-net_url__request_url__request__context.cc,v 1.19 2026/05/10 15:30:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/url_request/url_request_context.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ net/url_request/url_request_context.cc
@@ -129,7 +129,7 @@ const HttpNetworkSessionContext* URLRequ
   return &network_session->context();
 }
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
