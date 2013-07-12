$NetBSD: patch-mozilla_js_src_ion_AsmJSSignalHandlers.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/ion/AsmJSSignalHandlers.cpp.orig	2013-06-20 04:35:07.000000000 +0000
+++ mozilla/js/src/ion/AsmJSSignalHandlers.cpp
@@ -271,7 +271,7 @@ LookupHeapAccess(const AsmJSModule &modu
 # if defined(JS_CPU_X64)
 #  if defined(__DragonFly__)
 #   include <machine/npx.h> // for union savefpu
-#  elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#  elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #   include <machine/fpu.h> // for struct savefpu/fxsave64
 #  endif
 # endif
