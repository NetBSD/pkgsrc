$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.1 2018/06/28 14:04:10 ryoon Exp $

Support SunOS.

--- js/src/util/NativeStack.cpp.orig	2018-06-05 19:47:32.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -32,7 +32,7 @@ js::GetNativeStackBaseImpl()
     return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 #include <ucontext.h>
 
@@ -78,6 +78,7 @@ js::GetNativeStackBaseImpl()
 #  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
+#  elif defined(__sun)
 #  else
     /*
      * FIXME: this function is non-portable;
