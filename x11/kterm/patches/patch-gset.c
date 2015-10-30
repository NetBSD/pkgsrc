$NetBSD: patch-gset.c,v 1.1 2015/10/30 15:53:00 tsutsui Exp $

Fix segmentation faults (out of bound access) on trying to print
10 kanji characters added in JIS X 0213:2004 with fontList 8x16 settings.

--- gset.c.orig	2015-10-28 17:00:59.000000000 +0000
+++ gset.c
@@ -325,7 +325,7 @@ char **
 csnames(fnum)
 int fnum;
 {
-	static char *csnameslist[FCNT][4] = {
+	static char *csnameslist[FCNT][5] = {
 		{"iso8859-1"},				/* F_ISO8859_1 */
 		{"iso8859-2"},				/* F_ISO8859_2 */
 		{"iso8859-3"},				/* F_ISO8859_3 */
