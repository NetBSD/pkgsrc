$NetBSD: patch-src_3rdparty_chromium_base_memory_discardable__memory__internal.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/memory/discardable_memory_internal.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/memory/discardable_memory_internal.h
@@ -10,7 +10,7 @@
 #include "base/metrics/field_trial_params.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace base {
 
