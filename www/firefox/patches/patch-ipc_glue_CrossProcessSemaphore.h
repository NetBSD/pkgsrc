$NetBSD: patch-ipc_glue_CrossProcessSemaphore.h,v 1.3 2020/05/03 18:45:30 maya Exp $

--- ipc/glue/CrossProcessSemaphore.h.orig	2018-10-18 20:06:06.000000000 +0000
+++ ipc/glue/CrossProcessSemaphore.h
@@ -18,6 +18,10 @@
 #  include "mozilla/Atomics.h"
 #endif
 
+#ifdef __NetBSD__ // For version check only.
+#include <sys/param.h>
+#endif
+
 namespace IPC {
 template <typename T>
 struct ParamTraits;
@@ -105,7 +109,13 @@ class CrossProcessSemaphore {
   HANDLE mSemaphore;
 #elif !defined(OS_MACOSX)
   RefPtr<mozilla::ipc::SharedMemoryBasic> mSharedBuffer;
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000000)
+  pthread_mutex_t* mMutex;
+  pthread_cond_t* mNotZero;
+  uint32_t* mValue;
+#else
   sem_t* mSemaphore;
+#endif
   mozilla::Atomic<int32_t>* mRefCount;
 #endif
 };
