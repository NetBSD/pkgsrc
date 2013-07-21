$NetBSD: patch-cursor_cursor.h,v 1.1 2013/07/21 21:44:18 wiz Exp $

Don't define xcb_cursor_context_t twice.

--- cursor/cursor.h.orig	2013-07-09 20:30:14.000000000 +0000
+++ cursor/cursor.h
@@ -32,6 +32,8 @@
 #include <stdbool.h>
 #include <xcb/render.h>
 
+#include "xcb_cursor.h"
+
 enum {
     RM_XCURSOR_THEME = 0,
     RM_XCURSOR_SIZE,
@@ -61,7 +63,7 @@ typedef struct xcb_cursor_context_t {
     const char *path;
 
     bool render_present;
-} xcb_cursor_context_t;
+};
 
 /*
  * Cursor files start with a header.  The header
