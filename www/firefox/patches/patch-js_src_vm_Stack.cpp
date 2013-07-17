$NetBSD: patch-js_src_vm_Stack.cpp,v 1.1 2013/07/17 11:00:13 jperkin Exp $

--- js/src/vm/Stack.cpp.orig	2013-05-11 19:19:36.000000000 +0000
+++ js/src/vm/Stack.cpp
@@ -814,7 +814,11 @@ StackSpace::sizeOf()
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
