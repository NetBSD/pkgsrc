$NetBSD: patch-xmltooling_util_Threads.h,v 1.1 2013/09/17 21:16:16 joerg Exp $

--- xmltooling/util/Threads.h.orig	2013-09-17 20:39:26.000000000 +0000
+++ xmltooling/util/Threads.h
@@ -30,7 +30,6 @@
 #include <xmltooling/exceptions.h>
 
 #include <memory>
-#include <boost/scoped_ptr.hpp>
 #include <signal.h>
 
 namespace xmltooling
@@ -317,16 +316,6 @@ namespace xmltooling
         }
 
         /**
-         * Locks and wraps the designated mutex.
-         *
-         * @param mtx mutex to lock
-         */
-        Lock(const boost::scoped_ptr<Mutex>& mtx) : mutex(mtx.get()) {
-            if (mutex)
-                mutex->lock();
-        }
-
-        /**
          * Unlocks the wrapped mutex, if any.
          */
         ~Lock() {
@@ -378,17 +367,6 @@ namespace xmltooling
         }
 
         /**
-         * Locks and wraps the designated shared lock.
-         *
-         * @param lock      lock to acquire
-         * @param lockit    true if the lock should be acquired here, false if already acquired
-         */
-        SharedLock(const boost::scoped_ptr<RWLock>& lock, bool lockit=true) : rwlock(lock.get()) {
-            if (rwlock && lockit)
-                rwlock->rdlock();
-        }
-
-        /**
          * Unlocks the wrapped shared lock, if any.
          */
         ~SharedLock() {
