$NetBSD: patch-Source_WebCore_platform_graphics_gbm_MemoryMappedGPUBuffer.cpp,v 1.2 2026/09/22 12:27:03 wiz Exp $

--- Source/WebCore/platform/graphics/gbm/MemoryMappedGPUBuffer.cpp.orig	2026-09-11 05:39:27.267262200 +0000
+++ Source/WebCore/platform/graphics/gbm/MemoryMappedGPUBuffer.cpp
@@ -36,7 +36,9 @@
 #include "VivanteSuperTiledTextureInlines.h"
 #include <epoxy/egl.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/dma-buf.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <unistd.h>
@@ -508,6 +510,7 @@ bool MemoryMappedGPUBuffer::performDMABufSyncSystemCal
 
 bool MemoryMappedGPUBuffer::performDMABufSyncSystemCall(OptionSet<DMABufSyncFlag> flags)
 {
+#ifdef __linux__
     constexpr unsigned maxRetries = 10;
 
     struct dma_buf_sync sync;
@@ -537,6 +540,9 @@ bool MemoryMappedGPUBuffer::performDMABufSyncSystemCal
     }
 
     return true;
+#else
+    return false;
+#endif
 }
 
 } // namespace WebCore
