$NetBSD: patch-net_http_http__auth__gssapi__posix.cc,v 1.33 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_auth_gssapi_posix.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ net/http/http_auth_gssapi_posix.cc
@@ -383,7 +383,9 @@ base::NativeLibrary GSSAPISharedLibrary:
   } else {
 #if BUILDFLAG(IS_APPLE)
     library_names.emplace_back("/System/Library/Frameworks/GSS.framework/GSS");
-#elif BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_BSD)
+    // MIT Kerberos - FreeBSD
+    library_names.emplace_back("libgssapi_krb5.so.2");
     // Heimdal - OpenBSD
     library_names.emplace_back("libgssapi.so");
 #else
