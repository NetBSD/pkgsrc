$NetBSD: patch-third__party_boringssl_src_include_openssl_target.h,v 1.1 2026/03/29 19:18:49 tnn Exp $

Add NetBSD support.

--- third_party/boringssl/src/include/openssl/target.h.orig	2026-03-28 17:21:56.979756510 +0000
+++ third_party/boringssl/src/include/openssl/target.h
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
