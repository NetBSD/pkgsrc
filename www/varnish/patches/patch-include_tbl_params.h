$NetBSD: patch-include_tbl_params.h,v 1.1 2021/06/25 12:21:08 tnn Exp $

Change some default limits to cover NetBSD defaults.

--- include/tbl/params.h.orig	2021-03-12 15:02:41.000000000 +0000
+++ include/tbl/params.h
@@ -856,7 +856,7 @@ PARAM_SIMPLE(
 	/* name */	tcp_keepalive_intvl,
 	/* type */	timeout,
 	/* min */	"1",
-	/* max */	"100",
+	/* max */	"150",
 	/* def */	NULL,
 	/* units */	"seconds",
 	/* descr */
@@ -889,7 +889,7 @@ PARAM_SIMPLE(
 	/* name */	tcp_keepalive_time,
 	/* type */	timeout,
 	/* min */	"1",
-	/* max */	"7200",
+	/* max */	"14400",
 	/* def */	NULL,
 	/* units */	"seconds",
 	/* descr */
