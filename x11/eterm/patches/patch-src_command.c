$NetBSD: patch-src_command.c,v 1.1 2012/12/25 21:00:00 joerg Exp $

--- src/command.c.orig	2012-12-25 16:04:29.000000000 +0000
+++ src/command.c
@@ -1387,9 +1387,7 @@ sco_get_pty(void)
 #endif
 
 #ifdef HAVE_DEV_PTMX
-inline int svr_get_pty(void);
-
-inline int
+static int
 svr_get_pty(void)
 {
 
@@ -1420,9 +1418,7 @@ svr_get_pty(void)
 #define PTYCHAR1 "pqrstuvwxyz"
 #define PTYCHAR2 "0123456789abcdefghijklmnopqrstuvwxyz"
 
-inline int gen_get_pty(void);
-
-inline int
+static int
 gen_get_pty(void)
 {
 
