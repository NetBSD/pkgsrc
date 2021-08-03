$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__constants.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/content_constants.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_constants.cc
@@ -46,7 +46,7 @@ const int kDefaultDetachableCancelDelayM
 const char kCorsExemptPurposeHeaderName[] = "Purpose";
 const char kCorsExemptRequestedWithHeaderName[] = "X-Requested-With";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 
