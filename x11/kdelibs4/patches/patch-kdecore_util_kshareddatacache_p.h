$NetBSD: patch-kdecore_util_kshareddatacache_p.h,v 1.1 2012/03/19 11:28:49 markd Exp $

--- kdecore/util/kshareddatacache_p.h.orig	2011-04-01 13:56:18.000000000 +0000
+++ kdecore/util/kshareddatacache_p.h
@@ -311,7 +311,9 @@ static SharedLockId findBestSharedLock()
         sem_t tempSemaphore;
         QSharedPointer<KSDCLock> tempLock(0);
         if (timeoutsSupported) {
+#ifdef KSDC_TIMEOUTS_SUPPORTED
             tempLock = QSharedPointer<KSDCLock>(new semaphoreTimedLock(tempSemaphore));
+#endif
         }
         else {
             tempLock = QSharedPointer<KSDCLock>(new semaphoreLock(tempSemaphore));
