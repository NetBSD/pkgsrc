$NetBSD: patch-src_3rdparty_chromium_ui_gfx_linux_client__native__pixmap__dmabuf.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/linux/client_native_pixmap_dmabuf.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/linux/client_native_pixmap_dmabuf.cc
@@ -4,8 +4,12 @@
 
 #include "ui/gfx/linux/client_native_pixmap_dmabuf.h"
 
+#include "build/build_config.h"
+
 #include <fcntl.h>
+#if defined(OS_LINUX)
 #include <linux/version.h>
+#endif
 #include <stddef.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
@@ -27,6 +31,8 @@
 #include "ui/gfx/buffer_format_util.h"
 #include "ui/gfx/switches.h"
 
+#if defined(OS_LINUX)
+#if defined(OS_LINUX)
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
 #include <linux/dma-buf.h>
 #else
@@ -45,6 +51,21 @@ struct dma_buf_sync {
 #define DMA_BUF_BASE 'b'
 #define DMA_BUF_IOCTL_SYNC _IOW(DMA_BUF_BASE, 0, struct dma_buf_sync)
 #endif
+#endif
+#elif (OS_BSD)
+struct dma_buf_sync {
+  __u64 flags;
+};
+
+#define DMA_BUF_SYNC_READ (1 << 0)
+#define DMA_BUF_SYNC_WRITE (2 << 0)
+#define DMA_BUF_SYNC_RW (DMA_BUF_SYNC_READ | DMA_BUF_SYNC_WRITE)
+#define DMA_BUF_SYNC_START (0 << 2)
+#define DMA_BUF_SYNC_END (1 << 2)
+
+#define DMA_BUF_BASE 'b'
+#define DMA_BUF_IOCTL_SYNC _IOW(DMA_BUF_BASE, 0, struct dma_buf_sync)
+#endif
 
 namespace gfx {
 
