$NetBSD: patch-bin__varnishd__mgt_child.c,v 1.1 2011/05/09 11:11:11 fhajny Exp $

Patch varnishd to run on recent (snv_140+) versions of OpenSolaris.
See http://www.varnish-cache.org/trac/ticket/912
--- bin/varnishd/mgt_child.c.orig	2010-10-21 08:57:22.000000000 +0000
+++ bin/varnishd/mgt_child.c
@@ -298,6 +298,7 @@ waive_privileges(void)
 
 	/* new privilege, silently ignore any errors if it doesn't exist */
 	priv_addset(minimal, "net_access");
+	priv_addset(minimal, "file_read");
 
 #define SETPPRIV(which, set)				       \
 	if (setppriv(PRIV_SET, which, set))		       \
