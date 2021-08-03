$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__constants.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/content_constants.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_constants.h
@@ -65,7 +65,7 @@ CONTENT_EXPORT extern const int kDefault
 CONTENT_EXPORT extern const char kCorsExemptPurposeHeaderName[];
 CONTENT_EXPORT extern const char kCorsExemptRequestedWithHeaderName[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The OOM score adj constants
 // The highest and lowest assigned OOM score adjustment (oom_score_adj) for
 // renderers and extensions used by the OomPriority Manager.
