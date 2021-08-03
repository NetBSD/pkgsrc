$NetBSD: patch-src_3rdparty_chromium_content_app_content__main__runner__impl.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/app/content_main_runner_impl.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/app/content_main_runner_impl.cc
@@ -112,7 +112,7 @@
 
 #endif  // OS_POSIX || OS_FUCHSIA
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/native_library.h"
 #include "base/rand_util.h"
 #include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
@@ -305,7 +305,7 @@ void InitializeZygoteSandboxForBrowserPr
 }
 #endif  // BUILDFLAG(USE_ZYGOTE_HANDLE)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PLUGINS)
 // Loads the (native) libraries but does not initialize them (i.e., does not
@@ -472,7 +472,7 @@ int RunZygote(ContentMainDelegate* deleg
   delegate->ZygoteStarting(&zygote_fork_delegates);
   media::InitializeMediaLibrary();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   PreSandboxInit();
 #endif
 
@@ -632,7 +632,7 @@ int ContentMainRunnerImpl::Initialize(co
                    base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
     g_fds->Set(service_manager::kCrashDumpSignal,
                service_manager::kCrashDumpSignal +
                    base::GlobalDescriptors::kBaseDescriptor);
