$NetBSD: patch-netbsd_util.h,v 1.1 2018/12/20 12:33:24 jaapb Exp $

Changes from the freebsd Makefile to NetBSD
--- netbsd/util.h.orig	2018-12-20 10:44:24.500489587 +0000
+++ netbsd/util.h
@@ -1,5 +1,3 @@
-#include <libutil.h>
-
 #ifndef TAILQ_END
 #define TAILQ_END(head)			NULL
 #endif
