$NetBSD: patch-src_corelib_thread_qmutex__p.h,v 1.1 2019/04/28 12:46:31 maya Exp $

Avoid using semaphores on netbsd. they're flimsy and sem_init fails
if you use too many semaphores.

--- src/corelib/thread/qmutex_p.h.orig	2019-04-09 09:51:26.000000000 +0000
+++ src/corelib/thread/qmutex_p.h
@@ -65,7 +65,7 @@
 #elif defined(Q_OS_LINUX) && !defined(QT_LINUXBASE)
 // use Linux mutexes everywhere except for LSB builds
 #  define QT_LINUX_FUTEX
-#elif defined(Q_OS_UNIX)
+#elif defined(Q_OS_UNIX) && !defined(__NetBSD__)
 # if _POSIX_VERSION-0 >= 200112L || _XOPEN_VERSION-0 >= 600
 #  include <semaphore.h>
 #  define QT_UNIX_SEMAPHORE
