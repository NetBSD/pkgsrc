$NetBSD: patch-js_src_util_NativeStack.cpp,v 1.6 2020/04/09 14:01:26 ryoon Exp $

Support SunOS.

--- js/src/util/NativeStack.cpp.orig	2020-04-03 19:34:51.000000000 +0000
+++ js/src/util/NativeStack.cpp
@@ -13,7 +13,7 @@
 #  if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #    include <pthread_np.h>
 #  endif
-#  if defined(SOLARIS) || defined(AIX)
+#  if defined(__sun) || defined(AIX)
 #    include <ucontext.h>
 #  endif
 #  if defined(ANDROID) && !defined(__aarch64__)
@@ -40,7 +40,7 @@ void* js::GetNativeStackBaseImpl() {
   return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 static_assert(JS_STACK_GROWTH_DIRECTION < 0);
 
@@ -128,6 +128,7 @@ void* js::GetNativeStackBaseImpl() {
 #    elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
   /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
   pthread_attr_get_np(thread, &sattr);
+#    elif defined(__sun)
 #    else
   /*
    * FIXME: this function is non-portable;
