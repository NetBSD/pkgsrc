$NetBSD: patch-xpcom_components_nsComponentManager.cpp,v 1.1 2018/11/12 12:50:52 jperkin Exp $

Ensure symbols aren't pruned from being unused.

--- xpcom/components/nsComponentManager.cpp.orig	2018-10-31 00:08:15.000000000 +0000
+++ xpcom/components/nsComponentManager.cpp
@@ -298,8 +298,8 @@ extern mozilla::Module const* const __st
 
 #  if defined(__ELF__) || (defined(_WIN32) && defined(__GNUC__))
 
-extern "C" mozilla::Module const* const __start_kPStaticModules;
-extern "C" mozilla::Module const* const __stop_kPStaticModules;
+extern "C" mozilla::Module const* const __start_kPStaticModules = nullptr;
+extern "C" mozilla::Module const* const __stop_kPStaticModules = nullptr;
 
 #  elif defined(__MACH__)
 
