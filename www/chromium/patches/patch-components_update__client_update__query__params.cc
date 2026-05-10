$NetBSD: patch-components_update__client_update__query__params.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/update_client/update_query_params.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/update_client/update_query_params.cc
@@ -39,6 +39,10 @@ constexpr std::string_view kOs =
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
