$NetBSD: patch-src_sna_sna__accel.c,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/sna/sna_accel.c.orig	2014-12-20 13:29:27.000000000 +0000
+++ src/sna/sna_accel.c
@@ -115,6 +115,11 @@
 #define RECTILINEAR	0x4
 #define OVERWRITES	0x8
 
+#if XFONT2_CLIENT_FUNCS_VERSION >= 1
+#define AllocateFontPrivateIndex() xfont2_allocate_font_private_index()
+#define FontSetPrivate(font, idx, data) xfont2_font_set_private(font, idx, data)
+#endif
+
 #if 0
 static void __sna_fallback_flush(DrawablePtr d)
 {
@@ -17811,6 +17816,13 @@ static bool sna_option_accel_blt(struct
 	return strcasecmp(s, "blt") == 0;
 }
 
+#if HAVE_NOTIFY_FD
+static void sna_accel_notify(int fd, int ready, void *data)
+{
+	sna_mode_wakeup(data);
+}
+#endif
+
 bool sna_accel_init(ScreenPtr screen, struct sna *sna)
 {
 	const char *backend;
@@ -17822,7 +17834,7 @@ bool sna_accel_init(ScreenPtr screen, st
 	list_init(&sna->flush_pixmaps);
 	list_init(&sna->active_pixmaps);
 
-	AddGeneralSocket(sna->kgem.fd);
+	SetNotifyFd(sna->kgem.fd, sna_accel_notify, X_NOTIFY_READ, sna);
 
 #ifdef DEBUG_MEMORY
 	sna->timer_expire[DEBUG_MEMORY_TIMER] = GetTimeInMillis()+ 10 * 1000;
@@ -17998,7 +18010,7 @@ void sna_accel_close(struct sna *sna)
 	sna_pixmap_expire(sna);
 
 	DeleteCallback(&FlushCallback, sna_accel_flush_callback, sna);
-	RemoveGeneralSocket(sna->kgem.fd);
+	RemoveNotifyFd(sna->kgem.fd);
 
 	kgem_cleanup_cache(&sna->kgem);
 }
