$NetBSD: patch-src_3rdparty_chromium_weblayer_app_content__main__delegate__impl.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/weblayer/app/content_main_delegate_impl.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/weblayer/app/content_main_delegate_impl.cc
@@ -219,7 +219,7 @@ bool ContentMainDelegateImpl::ShouldCrea
 }
 
 void ContentMainDelegateImpl::PreSandboxStartup() {
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
