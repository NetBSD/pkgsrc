$NetBSD: patch-common_regexpr.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.
- Do not define own libc symbols.

--- common/regexpr.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/regexpr.c
@@ -23,6 +23,8 @@
  * regular-expression syntax might require a total rethink.
  */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "regexpr.h"
 
@@ -198,7 +200,6 @@ regexpr *reg_compile(char *exp)
 	register char *longest;
 	register int len;
 	int flags;
-	extern char *malloc();
 
 	if (exp == NULL)
 		FAIL("NULL argument");
@@ -682,7 +683,6 @@ STATIC char *regprop(char *);
 int reg_execute(register regexpr *prog, register char *string)
 {
 	register char *s;
-	extern char *strchr();
 
 	/* Be paranoid... */
 	if (prog == NULL || string == NULL) {
@@ -776,7 +776,6 @@ static int regmatch(char *prog)
 {
 	register char *scan;	/* Current node. */
 	char *next;		/* Next node. */
-	extern char *strchr();
 
 	scan = prog;
 #ifdef DEBUG
@@ -964,7 +963,6 @@ static int regrepeat(char *p)
 	register int count = 0;
 	register char *scan;
 	register char *opnd;
-        extern char *strchr();
 
 	scan = reginput;
 	opnd = OPERAND(p);
@@ -1031,7 +1029,6 @@ void reg_substitute(regexpr *prog, char 
 	register char c;
 	register int no;
 	register int len;
-	extern char *strncpy();
 
 	if (prog == NULL || source == NULL || dest == NULL) {
 		reg_error("NULL parm to reg_substitute");
@@ -1086,7 +1083,6 @@ void regdump(regexpr *r)
 	register char *s;
 	register char op = EXACTLY;	/* Arbitrary non-END op. */
 	register char *next;
-	extern char *strchr();
 
 
 	s = r->program + 1;
