$NetBSD: patch-toolkit_components_protobuf_src_google_protobuf_stubs_platform__macros.h,v 1.2 2016/06/16 12:08:21 ryoon Exp $

* Support Solaris

--- toolkit/components/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2015-09-11 00:23:02.000000000 +0000
+++ toolkit/components/protobuf/src/google/protobuf/stubs/platform_macros.h
@@ -67,7 +67,7 @@
 #define GOOGLE_PROTOBUF_ARCH_32_BIT 1
 #elif defined(sparc)
 #define GOOGLE_PROTOBUF_ARCH_SPARC 1
-#ifdef SOLARIS_64BIT_ENABLED
+#if (defined(sun) && defined(SOLARIS_64BIT_ENABLED)) || __LP64__
 #define GOOGLE_PROTOBUF_ARCH_64_BIT 1
 #else
 #define GOOGLE_PROTOBUF_ARCH_32_BIT 1
