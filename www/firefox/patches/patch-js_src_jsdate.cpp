$NetBSD: patch-js_src_jsdate.cpp,v 1.1 2015/02/16 16:16:17 bad Exp $

--- js/src/jsdate.cpp.orig	2015-01-23 06:00:01.000000000 +0000
+++ js/src/jsdate.cpp	2015-02-05 12:54:32.000000000 +0000
@@ -2651,11 +2651,11 @@
         if (strcmp(format, "%x") == 0 && result_len >= 6 &&
             /* Format %x means use OS settings, which may have 2-digit yr, so
                hack end of 3/11/22 or 11.03.22 or 11Mar22 to use 4-digit yr...*/
-            !isdigit(buf[result_len - 3]) &&
-            isdigit(buf[result_len - 2]) && isdigit(buf[result_len - 1]) &&
+            !isdigit(((unsigned char)buf[result_len - 3])) &&
+            isdigit(((unsigned char)buf[result_len - 2])) && isdigit(((unsigned char)buf[result_len - 1])) &&
             /* ...but not if starts with 4-digit year, like 2022/3/11. */
-            !(isdigit(buf[0]) && isdigit(buf[1]) &&
-              isdigit(buf[2]) && isdigit(buf[3]))) {
+            !(isdigit(((unsigned char)buf[0])) && isdigit(((unsigned char)buf[1])) &&
+              isdigit(((unsigned char)buf[2])) && isdigit(((unsigned char)buf[3])))) {
             JS_snprintf(buf + (result_len - 2), (sizeof buf) - (result_len - 2),
                         "%d", js_DateGetYear(cx, obj));
         }
