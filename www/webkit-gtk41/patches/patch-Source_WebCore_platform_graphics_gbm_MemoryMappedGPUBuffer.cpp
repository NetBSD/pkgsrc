$NetBSD: patch-Source_WebCore_platform_graphics_gbm_MemoryMappedGPUBuffer.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/WebCore/platform/graphics/gbm/MemoryMappedGPUBuffer.cpp.orig	2026-03-08 22:16:59.683749700 +0000
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
 #include <wtf/SafeStrerror.h>
@@ -406,6 +408,7 @@ bool MemoryMappedGPUBuffer::performDMABufSyncSystemCal
 
 bool MemoryMappedGPUBuffer::performDMABufSyncSystemCall(OptionSet<DMABufSyncFlag> flags)
 {
+#ifdef __linux__
     constexpr unsigned maxRetries = 10;
 
     struct dma_buf_sync sync;
@@ -435,6 +438,9 @@ bool MemoryMappedGPUBuffer::performDMABufSyncSystemCal
     }
 
     return true;
+#else
+    return false;
+#endif
 }
 
 } // namespace WebCore
