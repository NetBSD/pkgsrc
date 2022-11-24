$NetBSD: patch-src_corelib_thread_qmutex__p.h,v 1.1 2022/11/24 11:11:38 nros Exp $

Avoid using semaphores on netbsd. they're flimsy and sem_init fails
if you use too many semaphores.

--- src/corelib/thread/qmutex_p.h.orig	2021-09-23 07:42:06.000000000 +0000
+++ src/corelib/thread/qmutex_p.h
@@ -62,7 +62,7 @@
 
 #if defined(Q_OS_MAC)
 # include <mach/semaphore.h>
-#elif defined(Q_OS_UNIX)
+#elif defined(Q_OS_UNIX) && !defined(__NetBSD__)
 # if _POSIX_VERSION-0 >= 200112L || _XOPEN_VERSION-0 >= 600
 #  include <semaphore.h>
 #  define QT_UNIX_SEMAPHORE
