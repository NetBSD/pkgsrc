$NetBSD: patch-third__party_boringssl_src_include_openssl_target.h,v 1.16 2026/10/23 15:05:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/boringssl/src/include/openssl/target.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/boringssl/src/include/openssl/target.h
@@ -187,6 +187,10 @@
 #define OPENSSL_OPENBSD
 #endif
 
+#if defined(__NetBSD__)
+#define OPENSSL_NETBSD
+#endif
+
 // BoringSSL requires platform's locking APIs to make internal global state
 // thread-safe, including the PRNG. On some single-threaded embedded platforms,
 // locking APIs may not exist, so this dependency may be disabled with the
