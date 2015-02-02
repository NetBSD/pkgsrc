$NetBSD: patch-cursor_parse__cursor__file.c,v 1.1 2015/02/02 14:41:16 wiz Exp $

Simplified version of
http://cgit.freedesktop.org/xcb/util-cursor/commit/?id=f03cc278c6cce0cf721adf9c3764d3c5fba63392

--- cursor/parse_cursor_file.c.orig	2013-11-09 10:15:12.000000000 +0000
+++ cursor/parse_cursor_file.c
@@ -48,6 +48,9 @@
 # ifndef HAVE_LE32TOH
 #  define le32toh(x) LE_32(x)
 # endif
+#elif defined(__APPLE__)
+#include <libkern/OSByteOrder.h>
+#define le32toh(x) OSSwapLittleToHostInt32(x)
 #endif
 
 #include <xcb/xcb.h>
