$NetBSD: patch-third__party_boringssl_src_include_openssl_target.h,v 1.4 2026/05/10 15:30:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/boringssl/src/include/openssl/target.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/boringssl/src/include/openssl/target.h
@@ -177,6 +177,10 @@
 #define OPENSSL_OPENBSD
 #endif
 
+#if defined(__NetBSD__)
+#define OPENSSL_NETBSD
+#endif
+
 // BoringSSL requires platform's locking APIs to make internal global state
 // thread-safe, including the PRNG. On some single-threaded embedded platforms,
 // locking APIs may not exist, so this dependency may be disabled with the
