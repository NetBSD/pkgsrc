$NetBSD: patch-ipc_glue_CrossProcessSemaphore.h,v 1.1 2017/06/29 08:07:59 martin Exp $

- avoid use of sem_t on NetBSD
  http://mail-index.netbsd.org/pkgsrc-bugs/2017/06/23/msg062225.html

--- ipc/glue/CrossProcessSemaphore.h.orig	2017-06-05 20:45:20.000000000 +0000
+++ ipc/glue/CrossProcessSemaphore.h
@@ -91,7 +91,13 @@ private:
   HANDLE mSemaphore;
 #elif !defined(OS_MACOSX)
   RefPtr<mozilla::ipc::SharedMemoryBasic> mSharedBuffer;
+#if defined(__NetBSD__)
+  pthread_mutex_t* mMutex;
+  pthread_cond_t* mNotZero;
+  uint32_t* mValue;
+#else
   sem_t* mSemaphore;
+#endif
   mozilla::Atomic<int32_t>* mRefCount;
 #endif
 };
