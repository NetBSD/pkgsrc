$NetBSD: patch-toolkit_crashreporter_google-breakpad_src_third_party_curl_curlbuild.h,v 1.1 2017/09/12 07:39:08 martin Exp $

See https://bugzilla.mozilla.org/show_bug.cgi?id=1399027
Allow non-whitelisted 64bit platforms to build.

--- toolkit/crashreporter/google-breakpad/src/third_party/curl/curlbuild.h.orig	2017-06-15 22:52:33.000000000 +0200
+++ toolkit/crashreporter/google-breakpad/src/third_party/curl/curlbuild.h	2017-09-12 09:11:23.076831216 +0200
@@ -155,7 +155,8 @@
 
 /* The size of `long', as computed by sizeof. */
 #if defined(_M_X64) || (defined(__x86_64__) && !defined(__ILP32__)) ||      \
-    defined(__aarch64__) || (defined(__mips__) && _MIPS_SIM == _ABI64)
+    defined(__aarch64__) || (defined(__mips__) && _MIPS_SIM == _ABI64) ||   \
+    defined(__LP64__)
 #define CURL_SIZEOF_LONG 8
 #else
 #define CURL_SIZEOF_LONG 4
