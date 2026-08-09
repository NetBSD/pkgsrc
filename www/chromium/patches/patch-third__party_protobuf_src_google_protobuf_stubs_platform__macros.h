$NetBSD: patch-third__party_protobuf_src_google_protobuf_stubs_platform__macros.h,v 1.24 2026/08/09 06:31:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/protobuf/src/google/protobuf/stubs/platform_macros.h
@@ -99,7 +99,7 @@ GOOGLE_PROTOBUF_PLATFORM_ERROR
 
 #undef GOOGLE_PROTOBUF_PLATFORM_ERROR
 
-#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE)
+#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__OpenBSD__)
 // Android ndk does not support the __thread keyword very well yet. Here
 // we use pthread_key_create()/pthread_getspecific()/... methods for
 // TLS support on android.
