$NetBSD: patch-src_3rdparty_chromium_net_url__request_url__request__context.cc,v 1.1 2025/12/21 09:38:35 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/url_request/url_request_context.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/net/url_request/url_request_context.cc
@@ -121,7 +121,7 @@ const HttpNetworkSessionContext* URLRequ
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
