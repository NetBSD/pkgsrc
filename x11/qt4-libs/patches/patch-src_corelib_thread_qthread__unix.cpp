$NetBSD: patch-src_corelib_thread_qthread__unix.cpp,v 1.3 2016/05/31 21:35:11 joerg Exp $

--- src/corelib/thread/qthread_unix.cpp.orig	2015-05-07 14:14:48.000000000 +0000
+++ src/corelib/thread/qthread_unix.cpp
@@ -120,6 +120,12 @@ enum { ThreadPriorityResetFlag = 0x80000
 #if defined(Q_CC_XLC) || defined (Q_CC_SUN)
 #define HAVE_TLS
 #endif
+#if defined(Q_OS_NETBSD)
+#include <machine/types.h>
+#if defined(__HAVE_TLS_VARIANT_I) || defined(__HAVE_TLS_VARIANT_II)
+#define HAVE_TLS
+#endif
+#endif
 
 #ifdef HAVE_TLS
 static __thread QThreadData *currentThreadData = 0;
@@ -167,20 +173,6 @@ static void create_current_thread_data_k
     pthread_key_create(&current_thread_data_key, destroy_current_thread_data);
 }
 
-static void destroy_current_thread_data_key()
-{
-    pthread_once(&current_thread_data_once, create_current_thread_data_key);
-    pthread_key_delete(current_thread_data_key);
-
-    // Reset current_thread_data_once in case we end up recreating
-    // the thread-data in the rare case of QObject construction
-    // after destroying the QThreadData.
-    pthread_once_t pthread_once_init = PTHREAD_ONCE_INIT;
-    current_thread_data_once = pthread_once_init;
-}
-Q_DESTRUCTOR_FUNCTION(destroy_current_thread_data_key)
-
-
 // Utility functions for getting, setting and clearing thread specific data.
 static QThreadData *get_thread_data()
 {
