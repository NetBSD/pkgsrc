$NetBSD: patch-src_3rdparty_chromium_base_cpu.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/cpu.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/cpu.cc
@@ -31,7 +31,7 @@
 #endif
 
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "base/files/file_util.h"
 #endif
 
@@ -153,7 +153,7 @@ uint64_t xgetbv(uint32_t xcr) {
 #endif  // ARCH_CPU_X86_FAMILY
 
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 std::string* CpuInfoBrand() {
   static std::string* brand = []() {
     // This function finds the value from /proc/cpuinfo under the key "model
@@ -305,7 +305,7 @@ void CPU::Initialize() {
     }
   }
 #elif defined(ARCH_CPU_ARM_FAMILY)
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   cpu_brand_ = *CpuInfoBrand();
 #elif defined(OS_WIN)
   // Windows makes high-resolution thread timing information available in
