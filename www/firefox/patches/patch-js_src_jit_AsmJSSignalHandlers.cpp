$NetBSD: patch-js_src_jit_AsmJSSignalHandlers.cpp,v 1.1 2013/09/19 12:37:50 ryoon Exp $

--- js/src/jit/AsmJSSignalHandlers.cpp.orig	2013-09-10 03:43:36.000000000 +0000
+++ js/src/jit/AsmJSSignalHandlers.cpp
@@ -269,7 +269,7 @@ LookupHeapAccess(const AsmJSModule &modu
 # if defined(JS_CPU_X64)
 #  if defined(__DragonFly__)
 #   include <machine/npx.h> // for union savefpu
-#  elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__)
+#  elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #   include <machine/fpu.h> // for struct savefpu/fxsave64
 #  endif
 # endif
