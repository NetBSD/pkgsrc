$NetBSD: patch-net_url__request_url__request__context.h,v 1.7 2025/09/12 16:02:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/url_request/url_request_context.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ net/url_request/url_request_context.h
@@ -86,7 +86,7 @@ class NET_EXPORT URLRequestContext final
   // session.
   const HttpNetworkSessionContext* GetNetworkSessionContext() const;
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
