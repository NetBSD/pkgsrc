$NetBSD: patch-Source_JavaScriptCore_jit_ExecutableAllocator.cpp,v 1.4 2020/03/10 18:14:04 leot Exp $

Avoid to (pre)allocate 1GB of memory on OpenBSD:

 <https://bugs.webkit.org/show_bug.cgi?id=61137>

From OpenBSD ports.

--- Source/JavaScriptCore/jit/ExecutableAllocator.cpp.orig	2020-02-04 10:23:59.000000000 +0000
+++ Source/JavaScriptCore/jit/ExecutableAllocator.cpp
@@ -97,7 +97,7 @@ static constexpr size_t fixedExecutableM
 static constexpr size_t fixedExecutableMemoryPoolSize = 16 * 1024 * 1024;
 #elif CPU(ARM64)
 static constexpr size_t fixedExecutableMemoryPoolSize = 128 * 1024 * 1024;
-#elif CPU(X86_64)
+#elif CPU(X86_64) && !OS(OPENBSD)
 static constexpr size_t fixedExecutableMemoryPoolSize = 1024 * 1024 * 1024;
 #else
 static constexpr size_t fixedExecutableMemoryPoolSize = 32 * 1024 * 1024;
