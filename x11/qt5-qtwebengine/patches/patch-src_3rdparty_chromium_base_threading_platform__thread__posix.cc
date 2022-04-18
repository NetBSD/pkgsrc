$NetBSD: patch-src_3rdparty_chromium_base_threading_platform__thread__posix.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/threading/platform_thread_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/threading/platform_thread_posix.cc
@@ -66,7 +66,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::ThreadRestrictions::SetSingletonAllowed(false);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 
 #if defined(OS_APPLE)
     PlatformThread::SetCurrentThreadRealtimePeriodValue(
