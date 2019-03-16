$NetBSD: patch-src_libxosd_intern.h,v 1.1 2019/03/16 08:50:48 bsiegert Exp $

Support for y-offset monitors, http://gnats.netbsd.org/53994

--- src/libxosd/intern.h.orig	2004-11-04 19:50:45.000000000 +0000
+++ src/libxosd/intern.h
@@ -107,6 +107,7 @@ struct xosd
   int screen_width;             /* CONST x11 */
   int screen_height;            /* CONST x11 */
   int screen_xpos;              /* CONST x11 */
+  int screen_ypos;              /* CONST x11 */
   int height;                   /* CACHE (font) */
   int line_height;              /* CACHE (font) */
   xosd_pos pos;                 /* CONF */
