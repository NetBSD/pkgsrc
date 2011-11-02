$NetBSD: patch-entry.c,v 1.1 2011/11/02 23:47:37 sbd Exp $

Make the crontab entry '-q' option work.

--- entry.c.orig	2011-05-01 12:04:30.412434092 +0000
+++ entry.c
@@ -336,7 +336,8 @@ load_entry(FILE *file, void (*error_func

 	/* If the first character of the command is '-' it is a cron option.
 	 */
-	while ((ch = get_char(file)) == '-') {
+	Skip_Blanks(ch, file)
+	while (ch == '-') {
 		switch (ch = get_char(file)) {
 		case 'q':
 			e->flags |= DONT_LOG;
