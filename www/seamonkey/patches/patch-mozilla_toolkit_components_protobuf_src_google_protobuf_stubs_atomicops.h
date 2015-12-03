$NetBSD: patch-mozilla_toolkit_components_protobuf_src_google_protobuf_stubs_atomicops.h,v 1.1 2015/12/03 12:22:27 ryoon Exp $

--- mozilla/toolkit/components/protobuf/src/google/protobuf/stubs/atomicops.h.orig	2015-11-04 01:55:45.000000000 +0000
+++ mozilla/toolkit/components/protobuf/src/google/protobuf/stubs/atomicops.h
@@ -76,9 +76,15 @@ typedef intptr_t Atomic64;
 #endif
 #endif
 
+#if defined(__NetBSD__) && defined(__arm__)
+// NetBSD/arm uses long for intptr_t, which fails -fpermissive checks. So
+// explicitly use int32 here instead.
+typedef int32 AtomicWord;
+#else
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
