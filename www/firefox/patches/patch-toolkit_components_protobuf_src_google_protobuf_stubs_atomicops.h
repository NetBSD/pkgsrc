$NetBSD: patch-toolkit_components_protobuf_src_google_protobuf_stubs_atomicops.h,v 1.4 2018/01/24 16:52:08 ryoon Exp $

--- toolkit/components/protobuf/src/google/protobuf/stubs/atomicops.h.orig	2018-01-11 20:17:03.000000000 +0000
+++ toolkit/components/protobuf/src/google/protobuf/stubs/atomicops.h
@@ -87,6 +87,11 @@ typedef intptr_t Atomic64;
 #endif
 #endif
 
+#if defined(__NetBSD__) && defined(__arm__)
+// NetBSD/arm uses long for intptr_t, which fails -fpermissive checks. So
+// explicitly use int32 here instead.
+typedef int32 AtomicWord;
+#else
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
 #if defined(__OpenBSD__) && !defined(GOOGLE_PROTOBUF_ARCH_64_BIT) /* See Bug 1192556 */
@@ -94,6 +99,7 @@ typedef Atomic32 AtomicWord;
 #else
 typedef intptr_t AtomicWord;
 #endif
+#endif
 
 // Atomically execute:
 //      result = *ptr;
