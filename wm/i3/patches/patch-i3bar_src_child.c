$NetBSD: patch-i3bar_src_child.c,v 1.1 2025/12/27 15:37:50 wiz Exp $

Fix ctype(3) usage.
https://github.com/i3/i3/issues/6566

--- i3bar/src/child.c.orig	2025-12-19 07:19:53.000000000 +0000
+++ i3bar/src/child.c
@@ -525,7 +525,7 @@ static void stdin_io_first_line_cb(int f
 
 static bool isempty(char *s) {
     while (*s != '\0') {
-        if (!isspace(*s)) {
+        if (!isspace((unsigned char)*s)) {
             return false;
         }
         s++;
