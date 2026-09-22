$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.2 2026/09/22 12:27:02 wiz Exp $

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2026-07-24 08:02:50.530577200 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -4044,7 +4044,7 @@ class ARM64Assembler { (public)
 #elif OS(WINDOWS)
         FlushInstructionCache(GetCurrentProcess(), code, size);
 #else
-#error "The cacheFlush support is missing on this platform."
+#warning "The cacheFlush support is missing on this platform."
 #endif
     }
 
