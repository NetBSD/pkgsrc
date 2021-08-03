$NetBSD: patch-src_3rdparty_chromium_net_url__request_url__fetcher.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/url_request/url_fetcher.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/net/url_request/url_fetcher.cc
@@ -11,7 +11,7 @@ namespace net {
 
 URLFetcher::~URLFetcher() = default;
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 // static
 std::unique_ptr<URLFetcher> URLFetcher::Create(
     const GURL& url,
