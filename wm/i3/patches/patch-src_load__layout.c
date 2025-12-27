$NetBSD: patch-src_load__layout.c,v 1.1 2025/12/27 15:37:50 wiz Exp $

Check for uselocale() before using it.
https://github.com/i3/i3/issues/6566

--- src/load_layout.c.orig	2025-12-19 07:19:53.000000000 +0000
+++ src/load_layout.c
@@ -634,14 +634,22 @@ bool json_validate(const char *buf, cons
     /* Allow multiple values, i.e. multiple nodes to attach */
     yajl_config(hand, yajl_allow_multiple_values, true);
 
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     if (yajl_parse(hand, (const unsigned char *)buf, len) != yajl_status_ok) {
         unsigned char *str = yajl_get_error(hand, 1, (const unsigned char *)buf, len);
         ELOG("JSON parsing error: %s\n", str);
         yajl_free_error(hand, str);
         valid = false;
     }
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
 
     yajl_complete_parse(hand);
     yajl_free(hand);
@@ -671,7 +679,11 @@ json_content_t json_determine_content(co
     yajl_config(hand, yajl_allow_comments, true);
     /* Allow multiple values, i.e. multiple nodes to attach */
     yajl_config(hand, yajl_allow_multiple_values, true);
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     const yajl_status stat = yajl_parse(hand, (const unsigned char *)buf, len);
     if (stat != yajl_status_ok && stat != yajl_status_client_canceled) {
         unsigned char *str = yajl_get_error(hand, 1, (const unsigned char *)buf, len);
@@ -679,7 +691,11 @@ json_content_t json_determine_content(co
         yajl_free_error(hand, str);
     }
 
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
     yajl_complete_parse(hand);
     yajl_free(hand);
 
@@ -725,7 +741,11 @@ void tree_append_json(Con *con, const ch
     parsing_geometry = false;
     parsing_focus = false;
     parsing_marks = false;
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     const yajl_status stat = yajl_parse(hand, (const unsigned char *)buf, len);
     if (stat != yajl_status_ok) {
         unsigned char *str = yajl_get_error(hand, 1, (const unsigned char *)buf, len);
@@ -750,7 +770,11 @@ void tree_append_json(Con *con, const ch
      * next time. */
     con_fix_percent(con);
 
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
     yajl_complete_parse(hand);
     yajl_free(hand);
 
