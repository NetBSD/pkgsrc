$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2025-08-25 08:21:59.060354541 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -3765,7 +3765,7 @@ public:
 
         linuxPageFlush(current, end);
 #else
-#error "The cacheFlush support is missing on this platform."
+#warning "The cacheFlush support is missing on this platform."
 #endif
     }
 
