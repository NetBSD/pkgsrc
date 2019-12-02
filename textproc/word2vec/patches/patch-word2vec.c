$NetBSD: patch-word2vec.c,v 1.1 2019/12/02 02:00:41 minskim Exp $

Portability fix.
https://github.com/tmikolov/word2vec/pull/40

--- word2vec.c.orig	2017-07-16 22:46:08.000000000 +0000
+++ word2vec.c
@@ -71,7 +71,7 @@ void InitUnigramTable() {
 void ReadWord(char *word, FILE *fin, char *eof) {
   int a = 0, ch;
   while (1) {
-    ch = fgetc_unlocked(fin);
+    ch = getc_unlocked(fin);
     if (ch == EOF) {
       *eof = 1;
       break;
