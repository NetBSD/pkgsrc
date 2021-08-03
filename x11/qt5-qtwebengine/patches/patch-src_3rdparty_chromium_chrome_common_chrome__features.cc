$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__features.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/chrome_features.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_features.cc
@@ -70,7 +70,7 @@ const base::Feature kAsyncDns {
 #endif
 };
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
