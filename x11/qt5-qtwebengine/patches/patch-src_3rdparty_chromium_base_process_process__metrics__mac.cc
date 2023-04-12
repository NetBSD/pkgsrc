$NetBSD: patch-src_3rdparty_chromium_base_process_process__metrics__mac.cc,v 1.1 2023/04/12 19:24:06 adam Exp $

--- src/3rdparty/chromium/base/process/process_metrics_mac.cc.orig	2023-04-11 09:33:46.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_metrics_mac.cc
@@ -296,7 +296,7 @@ bool GetSystemMemoryInfo(SystemMemoryInf
   }
   DCHECK_EQ(HOST_VM_INFO64_COUNT, count);
 
-#if defined(ARCH_CPU_ARM64)
+#if defined(ARCH_CPU_ARM64) || defined(OS_APPLE)
   // PAGE_SIZE is vm_page_size on arm, which isn't constexpr.
   DCHECK_EQ(PAGE_SIZE % 1024, 0u) << "Invalid page size";
 #else
