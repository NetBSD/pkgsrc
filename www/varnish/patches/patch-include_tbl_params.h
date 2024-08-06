$NetBSD: patch-include_tbl_params.h,v 1.2 2024/08/06 01:34:41 tnn Exp $

Change some default limits to cover NetBSD defaults.

--- include/tbl/params.h.orig	2024-03-18 13:37:59.000000000 +0000
+++ include/tbl/params.h
@@ -897,7 +897,7 @@ PARAM_SIMPLE(
 	/* name */	tcp_keepalive_intvl,
 	/* type */	duration,
 	/* min */	"1",
-	/* max */	"100",
+	/* max */	"150",
 	/* def */	NULL,
 	/* units */	"seconds",
 	/* descr */
@@ -930,7 +930,7 @@ PARAM_SIMPLE(
 	/* name */	tcp_keepalive_time,
 	/* type */	duration,
 	/* min */	"1",
-	/* max */	"7200",
+	/* max */	"14400",
 	/* def */	NULL,
 	/* units */	"seconds",
 	/* descr */
