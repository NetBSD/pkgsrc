$NetBSD: patch-cfg__param.c,v 1.4 2019/10/03 16:34:59 sborrill Exp $

Fix compilation.

--- cfg_param.c.orig	2018-09-13 15:15:05.000000000 +0100
+++ cfg_param.c	2019-10-03 13:26:05.000000000 +0100
@@ -780,11 +780,11 @@
 {
     char *end, *table, *s;
     end = str;
-    while (*end != '\0' && !isspace(*end))
+    while (*end != '\0' && !isspace((unsigned char)*end))
         end++;
     *end = '\0';               /*Mark the end of Variable...... */
     end++;                     /*... and continue.... */
-    while (*end != '\0' && isspace(*end))      /*Find the start of arguments ...... */
+    while (*end != '\0' && isspace((unsigned char)*end))      /*Find the start of arguments ...... */
         end++;
     *arg = end;
     if ((s = strchr(str, '.')) != NULL) {
@@ -820,7 +820,7 @@
         } else {
             /*Support arguments in the form arg{a, b...}*/
             brkt = 0;
-            while (*end != '\0' && (!isspace(*end) || brkt)) {
+            while (*end != '\0' && (!isspace((unsigned char)*end) || brkt)) {
                 if (*end == '{') brkt = 1;
                 else if (brkt && *end == '}') brkt = 0;
                 end++;
@@ -839,7 +839,7 @@
 
         if (*end == '"')
             end++;
-        while (*end != '\0' && isspace(*end))
+        while (*end != '\0' && isspace((unsigned char)*end))
             end++;
 
     } while (*end != '\0');
@@ -871,7 +871,7 @@
     line[LINESIZE-1] = '\0';
 
     str = line;
-    while (*str != '\0' && isspace(*str))      /*Eat the spaces in the begging */
+    while (*str != '\0' && isspace((unsigned char)*str))      /*Eat the spaces in the begging */
         str++;
     if (*str == '\0' || *str == '#')   /*Empty line or comment */
         return 1;
