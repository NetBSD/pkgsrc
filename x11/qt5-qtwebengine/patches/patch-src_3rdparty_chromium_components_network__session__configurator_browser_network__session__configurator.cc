$NetBSD: patch-src_3rdparty_chromium_components_network__session__configurator_browser_network__session__configurator.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/network_session_configurator/browser/network_session_configurator.cc
@@ -717,7 +717,7 @@ net::URLRequestContextBuilder::HttpCache
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
