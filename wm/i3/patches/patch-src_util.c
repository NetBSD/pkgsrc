$NetBSD: patch-src_util.c,v 1.1 2025/12/27 15:37:50 wiz Exp $

Check for uselocale() before using it.
Fix ctype(3) abuse.
https://github.com/i3/i3/issues/6566

--- src/util.c.orig	2025-12-19 07:19:53.000000000 +0000
+++ src/util.c
@@ -67,7 +67,7 @@ __attribute__((__const__)) bool rect_equ
 __attribute__((pure)) bool name_is_digits(const char *name) {
     /* positive integers and zero are interpreted as numbers */
     for (size_t i = 0; i < strlen(name); i++) {
-        if (!isdigit(name[i])) {
+        if (!isdigit((unsigned char)name[i])) {
             return false;
         }
     }
@@ -221,12 +221,20 @@ static char **add_argument(char **origin
 #define ystr(str) yajl_gen_string(gen, (unsigned char *)str, strlen(str))
 
 static char *store_restart_layout(void) {
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     yajl_gen gen = yajl_gen_alloc(NULL);
 
     dump_node(gen, croot, true);
 
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
 
     const unsigned char *payload;
     size_t length;
