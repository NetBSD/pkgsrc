$NetBSD: patch-src_command.c,v 1.3 2020/04/20 00:47:34 joerg Exp $

--- src/command.c.orig	2020-04-19 17:56:09.198252388 +0000
+++ src/command.c
@@ -1388,9 +1388,9 @@ sco_get_pty(void)
 #endif
 
 #if defined(HAVE_POSIX_OPENPT) || defined(HAVE_DEV_PTMX)
-inline int posix_get_pty(void);
+static inline int posix_get_pty(void);
 
-inline int
+static inline int
 posix_get_pty(void)
 {
 
