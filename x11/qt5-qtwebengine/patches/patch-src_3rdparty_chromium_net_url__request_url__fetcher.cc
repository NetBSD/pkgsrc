$NetBSD: patch-src_3rdparty_chromium_net_url__request_url__fetcher.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/url_request/url_fetcher.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/url_request/url_fetcher.cc
@@ -21,7 +21,7 @@ void URLFetcher::SetIgnoreCertificateReq
   URLFetcherImpl::SetIgnoreCertificateRequests(ignored);
 }
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 // static
 std::unique_ptr<URLFetcher> URLFetcher::Create(
     const GURL& url,
