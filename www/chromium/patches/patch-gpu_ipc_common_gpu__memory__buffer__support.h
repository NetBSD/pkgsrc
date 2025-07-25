$NetBSD: patch-gpu_ipc_common_gpu__memory__buffer__support.h,v 1.4 2025/07/25 16:17:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ gpu/ipc/common/gpu_memory_buffer_support.h
@@ -21,7 +21,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 namespace gfx {
 class ClientNativePixmapFactory;
 }  // namespace gfx
