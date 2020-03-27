$NetBSD: patch-main.c,v 1.1 2020/03/27 06:19:47 rillig Exp $

main.c:1225:29: error: array subscript has type 'char' [-Werror=char-subscripts]
   (prec_num || (GlobalKeymap[c] == FUNCNAME_nulcmd))) {
                             ^

The variable c is used for reading characters via getc(), without
checking for EOF. And yes, the declaration of that variable is indeed
more than 800 lines away from its first use, even though the use is
constrained to a single tiny block of code.

The code is safe though since line 1225 above is only reached for
'0' to '9'.

https://sourceforge.net/p/w3m/patches/76/

--- main.c.orig	2019-01-05 08:41:27.000000000 +0000
+++ main.c
@@ -395,8 +395,8 @@ int
 main(int argc, char **argv, char **envp)
 {
     Buffer *newbuf = NULL;
-    char *p, c;
-    int i;
+    char *p;
+    int c, i;
     InputStream redin;
     char *line_str = NULL;
     char **load_argv;
