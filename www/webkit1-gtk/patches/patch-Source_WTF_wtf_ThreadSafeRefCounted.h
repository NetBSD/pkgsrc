$NetBSD: patch-Source_WTF_wtf_ThreadSafeRefCounted.h,v 1.1 2014/08/03 22:07:39 wiz Exp $

--- Source/WTF/wtf/ThreadSafeRefCounted.h.orig	2013-05-08 07:46:55.000000000 +0000
+++ Source/WTF/wtf/ThreadSafeRefCounted.h
@@ -96,7 +96,7 @@ public:
 #if !USE(LOCKFREE_THREADSAFEREFCOUNTED)
         MutexLocker locker(m_mutex);
 #endif
-        return static_cast<int const volatile &>(m_refCount);
+        return m_refCount;
     }
 
 protected:
@@ -123,7 +123,7 @@ protected:
     }
 
 private:
-    int m_refCount;
+    atomic_int m_refCount;
 #if !USE(LOCKFREE_THREADSAFEREFCOUNTED)
     mutable Mutex m_mutex;
 #endif
