$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__constants.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/common/content_constants.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_constants.cc
@@ -56,7 +56,7 @@ std::string GetCorsExemptRequestedWithHe
   return base::JoinString(pieces, "-");
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 
