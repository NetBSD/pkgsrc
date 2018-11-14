$NetBSD: patch-xpcom_components_nsComponentManager.cpp,v 1.2 2018/11/14 18:51:40 wiz Exp $

Ensure symbols aren't pruned from being unused.

--- xpcom/components/nsComponentManager.cpp.orig	2018-10-31 00:08:15.000000000 +0000
+++ xpcom/components/nsComponentManager.cpp
@@ -298,8 +298,13 @@ extern mozilla::Module const* const __st
 
 #  if defined(__ELF__) || (defined(_WIN32) && defined(__GNUC__))
 
+#ifdef __sun
+extern "C" mozilla::Module const* const __start_kPStaticModules = nullptr;
+extern "C" mozilla::Module const* const __stop_kPStaticModules = nullptr;
+#else
 extern "C" mozilla::Module const* const __start_kPStaticModules;
 extern "C" mozilla::Module const* const __stop_kPStaticModules;
+#endif
 
 #  elif defined(__MACH__)
 
