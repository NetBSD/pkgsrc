$NetBSD: patch-third__party_dawn_src_dawn_platform_WorkerThread.cpp,v 1.1 2026/11/19 19:46:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/platform/WorkerThread.cpp.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/dawn/src/dawn/platform/WorkerThread.cpp
@@ -34,7 +34,7 @@
 #include "src/utils/assert.h"
 #include "src/utils/platform.h"
 
-#if DAWN_PLATFORM_IS(LINUX)
+#if DAWN_PLATFORM_IS(LINUX) && !DAWN_PLATFORM_IS(BSD)
 #include <pthread.h>
 #endif
 
@@ -108,7 +108,7 @@ void AsyncJobHandleImpl::Join() {
 }
 
 void AsyncJobHandleImpl::JobThreadLoop(PostWorkerJobCallback cb, void* userdata) {
-#if DAWN_PLATFORM_IS(LINUX)
+#if DAWN_PLATFORM_IS(LINUX) && !DAWN_PLATFORM_IS(BSD)
     // Give the worker thread a dedicated name instead of inheriting the spawning thread's name.
     // Linux and Android only: the pthread_setname_np() signature differs on other POSIX platforms.
     pthread_setname_np(pthread_self(), "DawnWorker");
