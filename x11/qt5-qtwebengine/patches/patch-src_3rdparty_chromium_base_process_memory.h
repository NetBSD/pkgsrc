$NetBSD: patch-src_3rdparty_chromium_base_process_memory.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/memory.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/memory.h
@@ -25,7 +25,7 @@ BASE_EXPORT void EnableTerminationOnOutO
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
 BASE_EXPORT extern size_t g_oom_size;
 
 // The maximum allowed value for the OOM score.
