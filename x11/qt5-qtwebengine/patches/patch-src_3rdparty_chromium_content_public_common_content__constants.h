$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__constants.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/common/content_constants.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_constants.h
@@ -70,7 +70,7 @@ CONTENT_EXPORT extern const char kCorsEx
 // it at run time.
 CONTENT_EXPORT std::string GetCorsExemptRequestedWithHeaderName();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The OOM score adj constants
 // The highest and lowest assigned OOM score adjustment (oom_score_adj) for
 // renderers and extensions used by the OomPriority Manager.
