$NetBSD: patch-mozilla_xpcom_components_Module.h,v 1.4 2017/01/01 16:14:08 ryoon Exp $

* Workaround for binutils/GNU ld 2.26 from NetBSD/amd64 7.99.26

--- mozilla/xpcom/components/Module.h.orig	2016-12-14 02:10:01.000000000 +0000
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
