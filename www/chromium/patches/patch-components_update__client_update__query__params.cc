$NetBSD: patch-components_update__client_update__query__params.cc,v 1.5 2025/08/13 07:44:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/update_client/update_query_params.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/update_client/update_query_params.cc
@@ -39,6 +39,10 @@ const char kOs[] =
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
