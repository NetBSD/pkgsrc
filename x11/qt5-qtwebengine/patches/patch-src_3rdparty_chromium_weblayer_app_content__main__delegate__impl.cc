$NetBSD: patch-src_3rdparty_chromium_weblayer_app_content__main__delegate__impl.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/weblayer/app/content_main_delegate_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/weblayer/app/content_main_delegate_impl.cc
@@ -225,7 +225,7 @@ bool ContentMainDelegateImpl::ShouldCrea
 
 void ContentMainDelegateImpl::PreSandboxStartup() {
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
