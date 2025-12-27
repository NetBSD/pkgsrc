$NetBSD: patch-i3-config-wizard_main.c,v 1.1 2025/12/27 15:37:50 wiz Exp $

Fix ctype(3) usage.
https://github.com/i3/i3/issues/6566

--- i3-config-wizard/main.c.orig	2025-12-19 07:19:53.000000000 +0000
+++ i3-config-wizard/main.c
@@ -732,7 +732,7 @@ static void finish(void) {
 
         /* Skip leading whitespace */
         char *walk = line;
-        while (isspace(*walk) && walk < (line + len)) {
+        while (isspace((unsigned char)*walk) && walk < (line + len)) {
             /* Pre-output the skipped whitespaces to keep proper indentation */
             fputc(*walk, ks_config);
             walk++;
