$NetBSD: patch-lemonbar.c,v 1.1 2020/11/23 14:07:27 nia Exp $

Argument to ctype functions must be unsigned char.

--- lemonbar.c.orig	2020-11-20 08:32:06.000000000 +0000
+++ lemonbar.c
@@ -539,7 +539,7 @@ parse (char *text)
         if (p[0] == '%' && p[1] == '{' && (block_end = strchr(p++, '}'))) {
             p++;
             while (p < block_end) {
-                while (isspace(*p))
+                while (isspace((unsigned char)*p))
                     p++;
 
                 switch (*p++) {
@@ -593,7 +593,7 @@ parse (char *text)
                     case 'A': {
                         button = XCB_BUTTON_INDEX_1;
                         // The range is 1-5
-                        if (isdigit(*p) && (*p > '0' && *p < '6'))
+                        if (isdigit((unsigned char)*p) && (*p > '0' && *p < '6'))
                             button = *p++ - '0';
                         if (!area_add(p, block_end, &p, cur_mon, pos_x, align, button))
                             return;
@@ -671,7 +671,7 @@ parse (char *text)
                               // Switch to automatic font selection.
                               font_index = -1;
                               p++;
-                          } else if (isdigit(*p)) {
+                          } else if (isdigit((unsigned char)*p)) {
                               font_index = (int)strtoul(p, &ep, 10);
                               // User-specified 'font_index' ∊ (0,font_count]
                               // Otherwise just fallback to the automatic font selection
@@ -1217,7 +1217,7 @@ parse_geometry_string (char *str, int *t
             p++; continue;
         }
         // A digit must follow
-        if (!isdigit(*p)) {
+        if (!isdigit((unsigned char)*p)) {
             fprintf(stderr, "Invalid geometry specified\n");
             return false;
         }
