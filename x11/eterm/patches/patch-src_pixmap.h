$NetBSD: patch-src_pixmap.h,v 1.1 2022/07/29 06:05:49 rin Exp $

imlib_strerror() has been introduced to imlib2; mangle local version.

--- src/pixmap.h.orig	2022-07-29 04:41:21.385340371 +0900
+++ src/pixmap.h	2022-07-29 04:41:31.374499903 +0900
@@ -221,7 +221,7 @@ _XFUNCPROTOBEGIN
 extern const char *get_image_type(unsigned char);
 extern unsigned char image_mode_any(unsigned char);
 #ifdef PIXMAP_SUPPORT
-extern const char *imlib_strerror(Imlib_Load_Error);
+extern const char *eterm_imlib_strerror(Imlib_Load_Error);
 extern unsigned short parse_pixmap_ops(char *);
 extern unsigned short set_pixmap_scale(const char *, pixmap_t *);
 extern unsigned char check_image_ipc(unsigned char);
