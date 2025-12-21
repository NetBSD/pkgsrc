$NetBSD: patch-src_3rdparty_chromium_net_traffic__annotation_network__traffic__annotation.h,v 1.1 2025/12/21 09:38:35 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/traffic_annotation/network_traffic_annotation.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/net/traffic_annotation/network_traffic_annotation.h
@@ -378,7 +378,7 @@ struct MutablePartialNetworkTrafficAnnot
 }  // namespace net
 
 // Placeholder for unannotated usages.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 #define TRAFFIC_ANNOTATION_WITHOUT_PROTO(ANNOTATION_ID) \
   net::DefineNetworkTrafficAnnotation(ANNOTATION_ID, "No proto yet.")
 #endif
@@ -392,7 +392,7 @@ struct MutablePartialNetworkTrafficAnnot
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 
 #define NO_TRAFFIC_ANNOTATION_YET \
   net::DefineNetworkTrafficAnnotation("undefined", "Nothing here yet.")
