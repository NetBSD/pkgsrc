$NetBSD: patch-v8_src_snapshot_embedded_platform-embedded-file-writer-generic.cc,v 1.11 2025/12/11 09:13:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc
@@ -9,6 +9,10 @@
 
 #include "src/objects/instruction-stream.h"
 
+#if V8_OS_OPENBSD
+#include <sys/param.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
@@ -35,6 +39,10 @@ const char* DirectiveAsString(DataDirect
 void PlatformEmbeddedFileWriterGeneric::SectionText() {
   if (target_os_ == EmbeddedTargetOs::kChromeOS) {
     fprintf(fp_, ".section .text.hot.embedded\n");
+#if !defined(V8_TARGET_ARCH_IA32)
+  } else if (target_os_ == EmbeddedTargetOs::kOpenBSD) {
+    fprintf(fp_, ".section .openbsd.mutable,\"a\"\n");
+#endif
   } else {
     fprintf(fp_, ".section .text\n");
   }
@@ -75,6 +83,8 @@ void PlatformEmbeddedFileWriterGeneric::
 #else
   fprintf(fp_, ".balign 4096\n");
 #endif
+#elif defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  fprintf(fp_, ".balign %d\n", PAGE_SIZE);
 #elif V8_TARGET_ARCH_X64
   // On x64 use 64-bytes code alignment to allow 64-bytes loop header alignment.
   static_assert(64 >= kCodeAlignment);
@@ -102,6 +112,8 @@ void PlatformEmbeddedFileWriterGeneric::
 #else
   fprintf(fp_, ".balign 4096\n");
 #endif
+#elif defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  fprintf(fp_, ".balign %d\n", PAGE_SIZE);
 #endif
 }
 
