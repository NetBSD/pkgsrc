$NetBSD: patch-src_uxa_intel__driver.c,v 1.2 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/uxa/intel_driver.c.orig	2014-12-09 20:43:22.000000000 +0000
+++ src/uxa/intel_driver.c
@@ -642,7 +642,11 @@ redisplay_dirty(ScreenPtr screen, Pixmap
 		return;
 
 	PixmapRegionInit(&pixregion, dirty->slave_dst->master_pixmap);
+#ifdef HAS_DIRTYTRACKING_ROTATION
+	PixmapSyncDirtyHelper(dirty);
+#else
 	PixmapSyncDirtyHelper(dirty, &pixregion);
+#endif
 	RegionUninit(&pixregion);
 
         intel_flush(intel);
@@ -659,8 +663,9 @@ redisplay_dirty(ScreenPtr screen, Pixmap
 }
 
 static void
-intel_dirty_update(ScreenPtr screen)
+intel_dirty_update(intel_screen_private *intel)
 {
+	ScreenPtr screen = xf86ScrnToScreen(intel->scrn);
 	RegionPtr region;
 	PixmapDirtyUpdatePtr ent;
 
@@ -677,6 +682,7 @@ intel_dirty_update(ScreenPtr screen)
 }
 #endif
 
+#if !HAVE_NOTIFY_FD
 static void
 I830BlockHandler(BLOCKHANDLER_ARGS_DECL)
 {
@@ -694,9 +700,22 @@ I830BlockHandler(BLOCKHANDLER_ARGS_DECL)
 	intel_uxa_block_handler(intel);
 	intel_video_block_handler(intel);
 #ifdef INTEL_PIXMAP_SHARING
-	intel_dirty_update(screen);
+	intel_dirty_update(intel);
 #endif
 }
+#else
+static void
+I830BlockHandler(void *data, void *timeout)
+{
+	intel_screen_private *intel = data;
+
+	intel_uxa_block_handler(intel);
+	intel_video_block_handler(intel);
+#ifdef INTEL_PIXMAP_SHARING
+	intel_dirty_update(intel);
+#endif
+}
+#endif
 
 static Bool
 intel_init_initial_framebuffer(ScrnInfoPtr scrn)
@@ -939,8 +958,14 @@ I830ScreenInit(SCREEN_INIT_ARGS_DECL)
 			   "Hardware cursor initialization failed\n");
 	}
 
+#if !HAVE_NOTIFY_FD
 	intel->BlockHandler = screen->BlockHandler;
 	screen->BlockHandler = I830BlockHandler;
+#else
+	RegisterBlockAndWakeupHandlers(I830BlockHandler,
+				       (ServerWakeupHandlerProcPtr)NoopDDA,
+				       intel);
+#endif
 
 #ifdef INTEL_PIXMAP_SHARING
 	screen->StartPixmapTracking = PixmapStartDirtyTracking;
