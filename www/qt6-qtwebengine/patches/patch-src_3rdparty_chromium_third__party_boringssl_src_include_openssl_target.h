$NetBSD: patch-src_3rdparty_chromium_third__party_boringssl_src_include_openssl_target.h,v 1.1 2026/03/29 16:57:04 tnn Exp $

Add NetBSD support.

--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/target.h.orig	2026-03-28 15:03:26.265395108 +0000
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/target.h
@@ -175,6 +175,10 @@
 #define OPENSSL_OPENBSD
 #endif
 
+#if defined(__NetBSD__)
+#define OPENSSL_NETBSD
+#endif
+
 // BoringSSL requires platform's locking APIs to make internal global state
 // thread-safe, including the PRNG. On some single-threaded embedded platforms,
 // locking APIs may not exist, so this dependency may be disabled with the
