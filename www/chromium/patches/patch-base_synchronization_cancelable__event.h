$NetBSD: patch-base_synchronization_cancelable__event.h,v 1.18 2026/05/10 15:29:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/synchronization/cancelable_event.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ base/synchronization/cancelable_event.h
@@ -11,7 +11,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include <windows.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <semaphore.h>
 #else
 #include "base/synchronization/waitable_event.h"
@@ -49,7 +49,7 @@ class BASE_EXPORT CancelableEvent {
 
 #if BUILDFLAG(IS_WIN)
   using NativeHandle = HANDLE;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   using NativeHandle = sem_t;
 #else
   using NativeHandle = WaitableEvent;
