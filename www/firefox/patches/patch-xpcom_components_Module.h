$NetBSD: patch-xpcom_components_Module.h,v 1.3 2016/08/16 09:34:12 tnn Exp $

Can't do relocation against extern protected symbol (pkg/50767)
usr/bin/ld: ../../xpcom/components/nsComponentManager.o: relocation R_X86_64_PC32 against protected symbol `start_kPStaticModules_NSModule' can not be used when making a shared object

--- xpcom/components/Module.h.orig	2016-06-01 04:11:44.000000000 +0000
+++ xpcom/components/Module.h
@@ -125,7 +125,7 @@ struct Module
 #    define NSMODULE_SECTION __declspec(allocate(".kPStaticModules$M"), dllexport)
 #  elif defined(__GNUC__)
 #    if defined(__ELF__)
-#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("protected")))
+#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("hidden")))
 #    elif defined(__MACH__)
 #      define NSMODULE_SECTION __attribute__((section("__DATA, .kPStaticModules"), visibility("default")))
 #    elif defined (_WIN32)
