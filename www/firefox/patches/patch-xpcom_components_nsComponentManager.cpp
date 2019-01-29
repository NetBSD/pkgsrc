$NetBSD: patch-xpcom_components_nsComponentManager.cpp,v 1.3 2019/01/29 16:28:22 ryoon Exp $

Ensure symbols aren't pruned from being unused.

--- xpcom/components/nsComponentManager.cpp.orig	2019-01-18 00:21:31.000000000 +0000
+++ xpcom/components/nsComponentManager.cpp
@@ -267,8 +267,13 @@ NSMODULE_ASAN_BLACKLIST __declspec(alloc
 
 #if defined(__ELF__) || (defined(_WIN32) && defined(__GNUC__))
 
+#ifdef __sun
+extern "C" mozilla::Module const* const __start_kPStaticModules = nullptr;
+extern "C" mozilla::Module const* const __stop_kPStaticModules = nullptr;
+#else
 extern "C" mozilla::Module const* const __start_kPStaticModules;
 extern "C" mozilla::Module const* const __stop_kPStaticModules;
+#endif
 
 #elif defined(__MACH__)
 
