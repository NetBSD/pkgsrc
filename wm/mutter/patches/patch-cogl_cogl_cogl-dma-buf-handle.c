$NetBSD: patch-cogl_cogl_cogl-dma-buf-handle.c,v 1.1 2020/11/10 01:56:20 nia Exp $

Disable Linux-only functions

--- cogl/cogl/cogl-dma-buf-handle.c.orig	2020-10-05 18:05:31.474278000 +0000
+++ cogl/cogl/cogl-dma-buf-handle.c
@@ -36,8 +36,10 @@
 
 #include <errno.h>
 #include <gio/gio.h>
+#ifdef __linux__
 #include <linux/dma-buf.h>
 #include <sys/ioctl.h>
+#endif
 #include <sys/mman.h>
 #include <unistd.h>
 
@@ -101,6 +103,8 @@ cogl_dma_buf_handle_free (CoglDmaBufHand
   g_free (dmabuf_handle);
 }
 
+
+#ifdef __linux__
 static gboolean
 sync_read (CoglDmaBufHandle  *dmabuf_handle,
            uint64_t           start_or_end,
@@ -147,6 +151,7 @@ cogl_dma_buf_handle_sync_read_end (CoglD
 {
   return sync_read (dmabuf_handle, DMA_BUF_SYNC_END, error);
 }
+#endif
 
 gpointer
 cogl_dma_buf_handle_mmap (CoglDmaBufHandle  *dmabuf_handle,
