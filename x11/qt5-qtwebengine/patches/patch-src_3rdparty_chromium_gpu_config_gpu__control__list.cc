$NetBSD: patch-src_3rdparty_chromium_gpu_config_gpu__control__list.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/config/gpu_control_list.cc.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/gpu/config/gpu_control_list.cc
@@ -17,7 +17,7 @@
 #include "base/values.h"
 #include "build/build_config.h"
 #include "gpu/config/gpu_util.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace gpu {
 namespace {
@@ -248,7 +248,7 @@ bool GpuControlList::More::GLVersionInfo
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if defined(OS_CHROMEOS)
   return kGLTypeGL;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kGLTypeGL;
 #elif defined(OS_MACOSX)
   return kGLTypeGL;
@@ -754,7 +754,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsAndroid;
 #elif defined(OS_FUCHSIA)
   return kOsFuchsia;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
