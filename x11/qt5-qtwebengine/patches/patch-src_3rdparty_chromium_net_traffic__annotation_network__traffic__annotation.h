$NetBSD: patch-src_3rdparty_chromium_net_traffic__annotation_network__traffic__annotation.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/traffic_annotation/network_traffic_annotation.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/traffic_annotation/network_traffic_annotation.h
@@ -359,7 +359,7 @@ struct MutablePartialNetworkTrafficAnnot
 }  // namespace net
 
 // Placeholder for unannotated usages.
-#if !defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 #define TRAFFIC_ANNOTATION_WITHOUT_PROTO(ANNOTATION_ID) \
   net::DefineNetworkTrafficAnnotation(ANNOTATION_ID, "No proto yet.")
 #endif
@@ -370,7 +370,7 @@ struct MutablePartialNetworkTrafficAnnot
 //
 // On Linux and Windows, use MISSING_TRAFFIC_ANNOTATION or
 // TRAFFIC_ANNOTATION_FOR_TESTS.
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 #define NO_TRAFFIC_ANNOTATION_YET \
   net::DefineNetworkTrafficAnnotation("undefined", "Nothing here yet.")
 
