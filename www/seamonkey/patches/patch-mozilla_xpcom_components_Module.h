$NetBSD: patch-mozilla_xpcom_components_Module.h,v 1.1 2016/03/01 20:05:13 joerg Exp $

--- mozilla/xpcom/components/Module.h.orig	2016-02-29 19:46:51.779120265 +0000
+++ mozilla/xpcom/components/Module.h
@@ -125,7 +125,7 @@ struct Module
 #    define NSMODULE_SECTION __declspec(allocate(".kPStaticModules$M"), dllexport)
 #  elif defined(__GNUC__)
 #    if defined(__ELF__)
-#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("protected")))
+#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("hidden")))
 #    elif defined(__MACH__)
 #      define NSMODULE_SECTION __attribute__((section("__DATA, .kPStaticModules"), visibility("default")))
 #    elif defined (_WIN32)
