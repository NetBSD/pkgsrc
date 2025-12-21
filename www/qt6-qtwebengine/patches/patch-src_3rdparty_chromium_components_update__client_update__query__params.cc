$NetBSD: patch-src_3rdparty_chromium_components_update__client_update__query__params.cc,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -40,6 +40,10 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
+#elif defined(OS_NETBSD)
+    "netbsd";
 #else
 #error "unknown os"
 #endif
