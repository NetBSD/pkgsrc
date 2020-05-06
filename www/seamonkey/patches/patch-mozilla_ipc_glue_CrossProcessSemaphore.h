$NetBSD: patch-mozilla_ipc_glue_CrossProcessSemaphore.h,v 1.1 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/ipc/glue/CrossProcessSemaphore.h.orig	2020-02-17 23:37:52.000000000 +0000
+++ mozilla/ipc/glue/CrossProcessSemaphore.h
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
