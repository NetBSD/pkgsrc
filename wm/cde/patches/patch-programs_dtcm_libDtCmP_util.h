$NetBSD: patch-programs_dtcm_libDtCmP_util.h,v 1.1 2023/02/12 16:34:15 vins Exp $

Do not redefine strncat().

--- programs/dtcm/libDtCmP/util.h.orig	2022-10-01 17:18:27.000000000 +0000
+++ programs/dtcm/libDtCmP/util.h
@@ -269,7 +269,6 @@ extern void print_tick(time_t);
 extern boolean_t same_path(char*, char*);
 extern boolean_t same_user(char*, char*);
 extern char * str_to_cr(char*);
-extern char * strncat(char *, const char *, size_t n);
 extern char * substr(char*, int, int n);
 extern void syserr(char*, int, int, int);
 extern Lines * text_to_lines	(char*, int);
