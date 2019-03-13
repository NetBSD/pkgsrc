$NetBSD: patch-Source_JavaScriptCore_jit_ExecutableAllocator.cpp,v 1.3 2019/03/13 20:49:40 leot Exp $

Avoid to (pre)allocate 1GB of memory on OpenBSD:

 <https://bugs.webkit.org/show_bug.cgi?id=61137>

From OpenBSD ports.

--- Source/JavaScriptCore/jit/ExecutableAllocator.cpp.orig	2019-02-12 11:21:03.000000000 +0000
+++ Source/JavaScriptCore/jit/ExecutableAllocator.cpp
@@ -92,7 +92,7 @@ static const size_t fixedExecutableMemor
 static const size_t fixedExecutableMemoryPoolSize = 16 * 1024 * 1024;
 #elif CPU(ARM64)
 static const size_t fixedExecutableMemoryPoolSize = 128 * 1024 * 1024;
-#elif CPU(X86_64)
+#elif CPU(X86_64) && !OS(OPENBSD)
 static const size_t fixedExecutableMemoryPoolSize = 1024 * 1024 * 1024;
 #else
 static const size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;
