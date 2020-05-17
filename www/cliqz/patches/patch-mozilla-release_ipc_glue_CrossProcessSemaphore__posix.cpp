$NetBSD: patch-mozilla-release_ipc_glue_CrossProcessSemaphore__posix.cpp,v 1.2 2020/05/17 10:10:19 fox Exp $

Taken from www/firefox.

--- mozilla-release/ipc/glue/CrossProcessSemaphore_posix.cpp.orig	2019-01-18 00:20:30.000000000 +0000
+++ mozilla-release/ipc/glue/CrossProcessSemaphore_posix.cpp
@@ -9,6 +9,12 @@
 #include "nsDebug.h"
 #include "nsISupportsImpl.h"
 #include <errno.h>
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <iostream>
+#include <unistd.h>
+#include <limits>
+#endif
 
 static const uint64_t kNsPerMs = 1000000;
 static const uint64_t kNsPerSec = 1000000000;
@@ -16,7 +22,13 @@ static const uint64_t kNsPerSec = 100000
 namespace {
 
 struct SemaphoreData {
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  pthread_mutex_t mMutex;
+  pthread_cond_t mNotZero;
+  uint32_t mValue;
+#else
   sem_t mSemaphore;
+#endif
   mozilla::Atomic<int32_t> mRefCount;
   uint32_t mInitialValue;
 };
@@ -43,13 +55,27 @@ CrossProcessSemaphore* CrossProcessSemap
     return nullptr;
   }
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  data->mValue = aInitialValue;
+  if (pthread_mutex_init(&data->mMutex, NULL) ||
+      pthread_cond_init(&data->mNotZero, NULL) ) {
+    return nullptr;
+  }
+#else
   if (sem_init(&data->mSemaphore, 1, aInitialValue)) {
     return nullptr;
   }
+#endif
 
   CrossProcessSemaphore* sem = new CrossProcessSemaphore;
   sem->mSharedBuffer = sharedBuffer;
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  sem->mMutex = &data->mMutex;
+  sem->mNotZero = &data->mNotZero;
+  sem->mValue = &data->mValue;
+#else
   sem->mSemaphore = &data->mSemaphore;
+#endif
   sem->mRefCount = &data->mRefCount;
   *sem->mRefCount = 1;
 
@@ -85,23 +111,44 @@ CrossProcessSemaphore* CrossProcessSemap
 
   int32_t oldCount = data->mRefCount++;
   if (oldCount == 0) {
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+    if (pthread_mutex_init(&data->mMutex, NULL) ||
+        pthread_cond_init(&data->mNotZero, NULL) ) {
+      data->mRefCount--;
+      return nullptr;
+    }
+#else
     // The other side has already let go of their CrossProcessSemaphore, so now
     // mSemaphore is garbage. We need to re-initialize it.
     if (sem_init(&data->mSemaphore, 1, data->mInitialValue)) {
       data->mRefCount--;
       return nullptr;
     }
+#endif
   }
 
   CrossProcessSemaphore* sem = new CrossProcessSemaphore;
   sem->mSharedBuffer = sharedBuffer;
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  sem->mMutex = &data->mMutex;
+  sem->mNotZero = &data->mNotZero;
+  sem->mValue = &data->mValue;
+#else
   sem->mSemaphore = &data->mSemaphore;
+#endif
   sem->mRefCount = &data->mRefCount;
   return sem;
 }
 
 CrossProcessSemaphore::CrossProcessSemaphore()
-    : mSemaphore(nullptr), mRefCount(nullptr) {
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  : mMutex (nullptr)
+  , mNotZero (nullptr)
+  , mValue (nullptr)
+#else
+    : mSemaphore(nullptr)
+#endif
+    , mRefCount(nullptr) {
   MOZ_COUNT_CTOR(CrossProcessSemaphore);
 }
 
@@ -110,16 +157,57 @@ CrossProcessSemaphore::~CrossProcessSema
 
   if (oldCount == 0) {
     // Nothing can be done if the destroy fails so ignore return code.
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+    (void)pthread_cond_destroy(mNotZero);
+    (void)pthread_mutex_destroy(mMutex);
+#else
     Unused << sem_destroy(mSemaphore);
+#endif
   }
 
   MOZ_COUNT_DTOR(CrossProcessSemaphore);
 }
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+static struct timespec
+makeAbsTime(const Maybe<TimeDuration>& aWaitTime) {
+  struct timespec ts;
+  if (aWaitTime.isSome()) {
+    clock_gettime(CLOCK_REALTIME, &ts);
+    ts.tv_nsec += (kNsPerMs * aWaitTime->ToMilliseconds());
+    ts.tv_sec += ts.tv_nsec / kNsPerSec;
+    ts.tv_nsec %= kNsPerSec;
+  }
+  else {
+    ts.tv_sec = std::numeric_limits<time_t>::max();
+    ts.tv_nsec = 0;
+  }
+  return ts;
+}
+#endif
+
 bool CrossProcessSemaphore::Wait(const Maybe<TimeDuration>& aWaitTime) {
   MOZ_ASSERT(*mRefCount > 0,
              "Attempting to wait on a semaphore with zero ref count");
   int ret;
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  struct timespec ts = makeAbsTime(aWaitTime);
+
+  ret = pthread_mutex_lock(mMutex);
+
+  if (ret == 0) {
+    while (ret == 0 && mValue == 0) {
+      ret = pthread_cond_timedwait(mNotZero, mMutex, &ts);
+      while (ret == -1 && errno == EINTR) {
+        ret = pthread_cond_timedwait(mNotZero, mMutex, &ts);
+      }
+    }
+    if (ret == 0) {
+      --(*mValue);
+    }
+    pthread_mutex_unlock(mMutex);
+  }
+#else
   if (aWaitTime.isSome()) {
     struct timespec ts;
     if (clock_gettime(CLOCK_REALTIME, &ts) == -1) {
@@ -136,13 +224,24 @@ bool CrossProcessSemaphore::Wait(const M
     while ((ret = sem_wait(mSemaphore)) == -1 && errno == EINTR) {
     }
   }
+#endif
   return ret == 0;
 }
 
 void CrossProcessSemaphore::Signal() {
   MOZ_ASSERT(*mRefCount > 0,
              "Attempting to signal a semaphore with zero ref count");
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 900000001)
+  int ret;
+  ret = pthread_mutex_lock(mMutex);
+  if (ret == 0) {
+    ++(*mValue);
+    pthread_cond_signal(mNotZero);
+    pthread_mutex_unlock(mMutex);
+  }
+#else
   sem_post(mSemaphore);
+#endif
 }
 
 CrossProcessSemaphoreHandle CrossProcessSemaphore::ShareToProcess(
