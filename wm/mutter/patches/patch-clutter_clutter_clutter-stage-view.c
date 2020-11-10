$NetBSD: patch-clutter_clutter_clutter-stage-view.c,v 1.1 2020/11/10 01:56:20 nia Exp $

Disable Linux-only functions

--- clutter/clutter/clutter-stage-view.c.orig	2020-10-05 18:05:31.453278500 +0000
+++ clutter/clutter/clutter-stage-view.c
@@ -529,13 +529,13 @@ find_damaged_tiles (ClutterStageView    
   bpp = cogl_dma_buf_handle_get_bpp (current_dma_buf_handle);
 
   cogl_framebuffer_finish (COGL_FRAMEBUFFER (priv->shadow.framebuffer));
-
+#ifdef __linux__
   if (!cogl_dma_buf_handle_sync_read_start (prev_dma_buf_handle, error))
     return NULL;
 
   if (!cogl_dma_buf_handle_sync_read_start (current_dma_buf_handle, error))
     goto err_sync_read_current;
-
+#endif
   prev_data = cogl_dma_buf_handle_mmap (prev_dma_buf_handle, error);
   if (!prev_data)
     goto err_mmap_prev;
@@ -580,7 +580,7 @@ find_damaged_tiles (ClutterStageView    
             cairo_region_union_rectangle (tile_damage_region, &tile);
         }
     }
-
+#ifdef __linux__
   if (!cogl_dma_buf_handle_sync_read_end (prev_dma_buf_handle, error))
     {
       g_warning ("Failed to end DMA buffer read synchronization: %s",
@@ -594,7 +594,7 @@ find_damaged_tiles (ClutterStageView    
                  (*error)->message);
       g_clear_error (error);
     }
-
+#endif
   cogl_dma_buf_handle_munmap (prev_dma_buf_handle, prev_data, NULL);
   cogl_dma_buf_handle_munmap (current_dma_buf_handle, current_data, NULL);
 
@@ -604,13 +604,16 @@ find_damaged_tiles (ClutterStageView    
 
 err_mmap_current:
   cogl_dma_buf_handle_munmap (prev_dma_buf_handle, prev_data, NULL);
-
+#ifdef __linux__
 err_mmap_prev:
   cogl_dma_buf_handle_sync_read_end (current_dma_buf_handle, NULL);
 
 err_sync_read_current:
   cogl_dma_buf_handle_sync_read_end (prev_dma_buf_handle, NULL);
-
+#else
+err_mmap_prev:
+err_sync_read_current:
+#endif
   return NULL;
 }
 
