$NetBSD: patch-uitoolkit_ui__xic.h,v 1.1 2024/02/23 12:44:28 tsutsui Exp $

- pull an XIM fix commit to avoid possible stall with ibus-mozc
 https://github.com/arakiken/mlterm/commit/b8750c1

--- uitoolkit/ui_xic.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_xic.h
@@ -23,6 +23,7 @@ typedef struct ui_xic {
 #elif defined(USE_XLIB)
   XFontSet fontset;
   XIMStyle style;
+  XPoint spot;
 #endif
 
 } ui_xic_t;
