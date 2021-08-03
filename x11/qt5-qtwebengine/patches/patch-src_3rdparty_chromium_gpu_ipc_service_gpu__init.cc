$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_service_gpu__init.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/ipc/service/gpu_init.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_init.cc
@@ -92,7 +92,7 @@ void InitializePlatformOverlaySettings(G
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -161,7 +161,7 @@ bool GpuInit::InitializeAndStartSandbox(
   gpu_info_.subpixel_font_rendering = true;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.gpu.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -213,7 +213,7 @@ bool GpuInit::InitializeAndStartSandbox(
   delayed_watchdog_enable = true;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // PreSandbox is mainly for resource handling and not related to the GPU
   // driver, it doesn't need the GPU watchdog. The loadLibrary may take long
   // time that killing and restarting the GPU process will not help.
@@ -258,7 +258,7 @@ bool GpuInit::InitializeAndStartSandbox(
   }
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -291,7 +291,7 @@ bool GpuInit::InitializeAndStartSandbox(
   }
   if (gl_initialized && use_swiftshader &&
       gl::GetGLImplementation() != gl::kGLImplementationSwiftShaderGL) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
             << "on Linux";
     return false;
@@ -324,7 +324,7 @@ bool GpuInit::InitializeAndStartSandbox(
     }
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // gpu::GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -375,7 +375,7 @@ bool GpuInit::InitializeAndStartSandbox(
           command_line, gpu_feature_info_,
           gpu_preferences_.disable_software_rasterizer, false);
       if (use_swiftshader) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
                 << "on Linux";
         return false;
@@ -445,7 +445,7 @@ bool GpuInit::InitializeAndStartSandbox(
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -631,7 +631,7 @@ void GpuInit::InitializeInProcess(base::
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
