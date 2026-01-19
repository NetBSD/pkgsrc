$NetBSD: patch-v8_src_execution_isolate.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/execution/isolate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ v8/src/execution/isolate.cc
@@ -175,6 +175,10 @@
 #include "src/execution/simulator-base.h"
 #endif
 
+#if defined(V8_OS_OPENBSD)
+#include <sys/mman.h>
+#endif
+
 extern "C" const uint8_t v8_Default_embedded_blob_code_[];
 extern "C" uint32_t v8_Default_embedded_blob_code_size_;
 extern "C" const uint8_t v8_Default_embedded_blob_data_[];
@@ -5234,6 +5238,13 @@ void Isolate::InitializeDefaultEmbeddedB
   const uint8_t* data = DefaultEmbeddedBlobData();
   uint32_t data_size = DefaultEmbeddedBlobDataSize();
 
+#if defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  if (code_size > 0) {
+    mprotect(reinterpret_cast<void *>(const_cast<uint8_t *>(code)),
+            code_size, PROT_READ | PROT_EXEC);
+  }
+#endif
+
   if (StickyEmbeddedBlobCode() != nullptr) {
     base::MutexGuard guard(current_embedded_blob_refcount_mutex_.Pointer());
     // Check again now that we hold the lock.
