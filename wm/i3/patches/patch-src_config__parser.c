$NetBSD: patch-src_config__parser.c,v 1.1 2021/11/01 20:42:58 wiz Exp $

NetBSD does not provide get_current_dir_name().

--- src/config_parser.c.orig	2021-10-19 06:37:59.902370500 +0000
+++ src/config_parser.c
@@ -864,7 +864,7 @@ parse_file_result_t parse_file(struct pa
     FILE *fstr;
     char buffer[4096], key[512], value[4096], *continuation = NULL;
 
-    char *old_dir = get_current_dir_name();
+    char *old_dir = getwd(NULL);
     char *dir = NULL;
     /* dirname(3) might modify the buffer, so make a copy: */
     char *dirbuf = sstrdup(f);
