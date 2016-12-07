$NetBSD: patch-src_uxa_intel__display.c,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/uxa/intel_display.c.orig	2014-12-09 20:43:16.000000000 +0000
+++ src/uxa/intel_display.c
@@ -2072,6 +2072,7 @@ intel_pageflip_abort(ScrnInfoPtr scrn, x
 /*
  * Check for pending DRM events and process them.
  */
+#if !HAVE_NOTIFY_FD
 static void
 drm_wakeup_handler(pointer data, int err, pointer p)
 {
@@ -2086,6 +2087,14 @@ drm_wakeup_handler(pointer data, int err
 	if (FD_ISSET(mode->fd, read_mask))
 		drmHandleEvent(mode->fd, &mode->event_context);
 }
+#else
+static void
+drm_notify_fd(int fd, int ready, void *data)
+{
+	struct intel_mode *mode = data;
+	drmHandleEvent(mode->fd, &mode->event_context);
+}
+#endif
 
 /*
  * If there are any available, read drm_events
@@ -2250,9 +2259,11 @@ intel_mode_init(struct intel_screen_priv
 	 * registration within ScreenInit and not PreInit.
 	 */
 	mode->flip_count = 0;
-	AddGeneralSocket(mode->fd);
+	SetNotifyFd(mode->fd, drm_notify_fd, X_NOTIFY_READ, mode);
+#if !HAVE_NOTIFY_FD
 	RegisterBlockAndWakeupHandlers((BlockHandlerProcPtr)NoopDDA,
 				       drm_wakeup_handler, mode);
+#endif
 }
 
 void
@@ -2276,9 +2287,11 @@ intel_mode_close(intel_screen_private *i
 
         intel_drm_abort_scrn(intel->scrn);
 
+#if !HAVE_NOTIFY_FD
 	RemoveBlockAndWakeupHandlers((BlockHandlerProcPtr)NoopDDA,
 				     drm_wakeup_handler, mode);
-	RemoveGeneralSocket(mode->fd);
+#endif
+	RemoveNotifyFd(mode->fd);
 }
 
 void
