$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.3 2018/09/25 12:55:53 jperkin Exp $

Support SunOS.

--- js/src/util/NativeStack.cpp.orig	2018-08-30 16:44:22.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -13,7 +13,7 @@
 # if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #  include <pthread_np.h>
 # endif
-# if defined(SOLARIS) || defined(AIX)
+# if defined(__sun) || defined(AIX)
 #  include <ucontext.h>
 # endif
 # if defined(ANDROID) && !defined(__aarch64__)
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
