$NetBSD: patch-src_3rdparty_chromium_third__party_protobuf_src_google_protobuf_stubs_platform__macros.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2020-07-15 18:56:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/stubs/platform_macros.h
@@ -118,7 +118,7 @@ GOOGLE_PROTOBUF_PLATFORM_ERROR
 
 #undef GOOGLE_PROTOBUF_PLATFORM_ERROR
 
-#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__OpenBSD__)
+#if defined(GOOGLE_PROTOBUF_OS_ANDROID) || defined(GOOGLE_PROTOBUF_OS_IPHONE) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 // Android ndk does not support the __thread keyword very well yet. Here
 // we use pthread_key_create()/pthread_getspecific()/... methods for
 // TLS support on android.
