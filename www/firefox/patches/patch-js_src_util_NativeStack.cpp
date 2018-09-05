$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.2 2018/09/05 15:29:58 ryoon Exp $

Support SunOS.

--- js/src/util/NativeStack.cpp.orig	2018-08-30 16:44:22.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -46,7 +46,7 @@ js::GetNativeStackBaseImpl()
     return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 JS_STATIC_ASSERT(JS_STACK_GROWTH_DIRECTION < 0);
 
@@ -134,6 +134,7 @@ js::GetNativeStackBaseImpl()
 #  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
+#  elif defined(__sun)
 #  else
     /*
      * FIXME: this function is non-portable;
