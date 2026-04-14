$NetBSD: patch-config.c,v 1.1 2026/04/14 12:11:48 kikadf Exp $

* Fix ctype usage

--- config.c.orig	2026-02-05 16:28:45.447020587 +0000
+++ config.c
@@ -755,7 +755,7 @@ value_to_fonts(struct context *ctx)
          font = strtok(NULL, ","))
     {
         /* Trim spaces, strictly speaking not necessary, but looks nice :) */
-        while (isspace(font[0]))
+        while (isspace((unsigned char)font[0]))
             font++;
 
         if (font[0] == '\0')
@@ -1374,7 +1374,7 @@ parse_color_theme(struct context *ctx, s
     uint8_t last_digit = (unsigned char)key[key_len - 1] - '0';
     uint32_t *color = NULL;
 
-    if (isdigit(key[0])) {
+    if (isdigit((unsigned char)key[0])) {
         unsigned long index;
         if (!str_to_ulong(key, 0, &index) || index >= ALEN(theme->table)) {
             LOG_CONTEXTUAL_ERR(
@@ -2188,7 +2188,7 @@ pipe_argv_from_value(struct context *ctx
 
     ssize_t remove_len = pipe_cmd_end + 1 - ctx->value;
     ctx->value = pipe_cmd_end + 1;
-    while (isspace(*ctx->value)) {
+    while (isspace((unsigned char)*ctx->value)) {
         ctx->value++;
         remove_len++;
     }
@@ -2216,7 +2216,7 @@ regex_name_from_value(struct context *ct
 
     ssize_t remove_len = regex_end + 1 - ctx->value;
     ctx->value = regex_end + 1;
-    while (isspace(*ctx->value)) {
+    while (isspace((unsigned char)*ctx->value)) {
         ctx->value++;
         remove_len++;
     }
@@ -2890,7 +2890,7 @@ parse_key_value(char *kv, char **section
     bool section_is_needed = section != NULL;
 
     /* Strip leading whitespace */
-    while (isspace(kv[0]))
+    while (isspace((unsigned char)kv[0]))
         ++kv;
 
     if (section_is_needed)
@@ -2905,7 +2905,7 @@ parse_key_value(char *kv, char **section
     size_t kvlen = strlen(kv);
 
     /* Strip trailing whitespace */
-    while (isspace(kv[kvlen - 1]))
+    while (isspace((unsigned char)kv[kvlen - 1]))
         kvlen--;
     kv[kvlen] = '\0';
 
@@ -2932,16 +2932,16 @@ parse_key_value(char *kv, char **section
 
     /* Strip trailing whitespace from key (leading stripped earlier) */
     {
-        xassert(!isspace(*key[0]));
+        xassert(!isspace((unsigned char)*key[0]));
 
         char *end = (char *)*key + strlen(*key) - 1;
-        while (isspace(end[0]))
+        while (isspace((unsigned char)end[0]))
             end--;
         end[1] = '\0';
     }
 
     /* Strip leading whitespace from value (trailing stripped earlier) */
-    while (isspace(*value[0]))
+    while (isspace((unsigned char)*value[0]))
         ++*value;
 
     return true;
@@ -3073,7 +3073,7 @@ parse_config_file(FILE *f, struct config
         char *line = _line;
 
         /* Strip leading whitespace */
-        while (isspace(line[0])) {
+        while (isspace((unsigned char)line[0])) {
             line++;
             len--;
         }
@@ -3091,7 +3091,7 @@ parse_config_file(FILE *f, struct config
         char *kv_trailing = &line[len - 1];
         char *comment = &line[1];
         while (comment[1] != '\0') {
-            if (isblank(comment[0]) && comment[1] == '#') {
+            if (isblank((unsigned char)comment[0]) && comment[1] == '#') {
                 comment[1] = '\0'; /* Terminate key/value pair */
                 kv_trailing = comment++;
                 break;
@@ -3101,7 +3101,7 @@ parse_config_file(FILE *f, struct config
         comment++;
 
         /* Strip trailing whitespace */
-        while (isspace(kv_trailing[0]))
+        while (isspace((unsigned char)kv_trailing[0]))
             kv_trailing--;
         kv_trailing[1] = '\0';
 
