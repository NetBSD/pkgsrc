$NetBSD: patch-lemonbar.c,v 1.2 2025/06/12 20:04:10 vins Exp $

* pledge support uses err() on OpenBSD.
* iovec struct has a iov_base member of type caddr_t on SunOS.
* Argument to ctype functions must be unsigned char.

--- lemonbar.c.orig	2024-04-30 07:50:08.000000000 +0000
+++ lemonbar.c
@@ -8,6 +8,9 @@
 #include <poll.h>
 #include <getopt.h>
 #include <unistd.h>
+#ifdef __OpenBSD__
+#include <err.h>
+#endif
 #include <errno.h>
 #include <assert.h>
 #include <xcb/xcb.h>
@@ -134,7 +137,11 @@ xcb_void_cookie_t xcb_poly_text_16_simpl
         1                 // isvoid
     };
     struct iovec xcb_parts[7];
+#ifdef __sun
+    char xcb_lendelta[2];
+#else
     uint8_t xcb_lendelta[2];
+#endif
     xcb_void_cookie_t xcb_ret;
     xcb_poly_text_8_request_t xcb_out;
 
@@ -510,7 +517,7 @@ parse (char *text)
         if (p[0] == '%' && p[1] == '{' && (block_end = strchr(p++, '}'))) {
             p++;
             while (p < block_end) {
-                while (isspace(*p))
+                while (isspace((unsigned char)*p))
                     p++;
 
                 switch (*p++) {
@@ -564,7 +571,7 @@ parse (char *text)
                     case 'A': {
                         button = XCB_BUTTON_INDEX_1;
                         // The range is 1-5
-                        if (isdigit(*p) && (*p > '0' && *p < '6'))
+                        if (isdigit((unsigned char)*p) && (*p > '0' && *p < '6'))
                             button = *p++ - '0';
                         if (!area_add(p, block_end, &p, cur_mon, pos_x, align, button))
                             return;
@@ -644,7 +651,7 @@ parse (char *text)
                               // Switch to automatic font selection.
                               font_index = -1;
                               p++;
-                          } else if (isdigit(*p)) {
+                          } else if (isdigit((unsigned char)*p)) {
                               font_index = (int)strtoul(p, &ep, 10);
                               // User-specified 'font_index' ∊ (0,font_count]
                               // Otherwise just fallback to the automatic font selection
@@ -1176,7 +1183,7 @@ parse_geometry_string (char *str, int *t
             p++; continue;
         }
         // A digit must follow
-        if (!isdigit(*p)) {
+        if (!isdigit((unsigned char)*p)) {
             fprintf(stderr, "Invalid geometry specified\n");
             return false;
         }
