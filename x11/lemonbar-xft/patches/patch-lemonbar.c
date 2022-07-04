$NetBSD: patch-lemonbar.c,v 1.1 2022/07/04 19:56:05 pin Exp $

Adapt pkgsrc lemonbar patch

--- lemonbar.c.orig	2020-12-13 07:41:32.000000000 +0000
+++ lemonbar.c
@@ -616,7 +616,7 @@ parse (char *text)
             p++;
             while (p < block_end) {
                 int w;
-                while (isspace(*p))
+                while (isspace((unsigned char)*p))
                     p++;
 
                 switch (*p++) {
@@ -638,7 +638,7 @@ parse (char *text)
                     case 'A':
                               button = XCB_BUTTON_INDEX_1;
                               // The range is 1-5
-                              if (isdigit(*p) && (*p > '0' && *p < '6'))
+                              if (isdigit((unsigned char)*p) && (*p > '0' && *p < '6'))
                                   button = *p++ - '0';
                               if (!area_add(p, block_end, &p, cur_mon, pos_x, align, button))
                                   return;
@@ -657,7 +657,7 @@ parse (char *text)
                               { cur_mon = monhead; }
                               else if (*p == 'l')
                               { cur_mon = montail ? montail : monhead; }
-                              else if (isdigit(*p))
+                              else if (isdigit((unsigned char)*p))
                               { cur_mon = monhead;
                                 for (int i = 0; i != *p-'0' && cur_mon->next; i++)
                                     cur_mon = cur_mon->next;
@@ -689,7 +689,7 @@ parse (char *text)
                                   font_index = -1;
                                   p++;
                                   break;
-                              } else if (isdigit(*p)) {
+                              } else if (isdigit((unsigned char)*p)) {
                                   font_index = (int)strtoul(p, &ep, 10);
                                   // User-specified 'font_index' ∊ (0,font_count]
                                   // Otherwise just fallback to the automatic font selection
@@ -1214,7 +1214,7 @@ parse_geometry_string (char *str, int *t
             p++; continue;
         }
         // A digit must follow
-        if (!isdigit(*p)) {
+        if (!isdigit((unsigned char)*p)) {
             fprintf(stderr, "Invalid geometry specified\n");
             return false;
         }
