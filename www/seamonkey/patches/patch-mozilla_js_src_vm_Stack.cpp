$NetBSD: patch-mozilla_js_src_vm_Stack.cpp,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/js/src/vm/Stack.cpp.orig	2013-08-04 03:05:34.000000000 +0000
+++ mozilla/js/src/vm/Stack.cpp
@@ -803,7 +803,11 @@ StackSpace::sizeOf()
 #endif
 
     MincoreArgType *vec = (MincoreArgType *) js_malloc(numPages);
+#ifdef __sun
+    int result = mincore((caddr_t)base_, numBytes, vec);
+#else
     int result = mincore(base_, numBytes, vec);
+#endif
     if (result) {
         js_free(vec);
         /*
