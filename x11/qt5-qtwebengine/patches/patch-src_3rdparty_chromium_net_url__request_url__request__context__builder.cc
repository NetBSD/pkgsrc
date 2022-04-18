$NetBSD: patch-src_3rdparty_chromium_net_url__request_url__request__context__builder.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/url_request/url_request_context_builder.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/url_request/url_request_context_builder.cc
@@ -497,7 +497,7 @@ std::unique_ptr<URLRequestContext> URLRe
   }
 
   if (!proxy_resolution_service_) {
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID) && !defined(OS_BSD)
     // TODO(willchan): Switch to using this code when
     // ConfiguredProxyResolutionService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.
