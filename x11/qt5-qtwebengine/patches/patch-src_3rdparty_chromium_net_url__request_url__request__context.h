$NetBSD: patch-src_3rdparty_chromium_net_url__request_url__request__context.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/url_request/url_request_context.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/url_request/url_request_context.h
@@ -82,7 +82,7 @@ class NET_EXPORT URLRequestContext
   // session.
   const HttpNetworkSession::Context* GetNetworkSessionContext() const;
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
