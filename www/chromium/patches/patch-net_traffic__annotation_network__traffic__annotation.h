$NetBSD: patch-net_traffic__annotation_network__traffic__annotation.h,v 1.25 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/traffic_annotation/network_traffic_annotation.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ net/traffic_annotation/network_traffic_annotation.h
@@ -370,7 +370,7 @@ struct MutablePartialNetworkTrafficAnnot
 }  // namespace net
 
 // Placeholder for unannotated usages.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 #define TRAFFIC_ANNOTATION_WITHOUT_PROTO(ANNOTATION_ID) \
   net::DefineNetworkTrafficAnnotation(ANNOTATION_ID, "No proto yet.")
 #endif
@@ -381,7 +381,7 @@ struct MutablePartialNetworkTrafficAnnot
 //
 // On Linux and Windows, use MISSING_TRAFFIC_ANNOTATION or
 // TRAFFIC_ANNOTATION_FOR_TESTS.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 #define NO_TRAFFIC_ANNOTATION_YET \
   net::DefineNetworkTrafficAnnotation("undefined", "Nothing here yet.")
