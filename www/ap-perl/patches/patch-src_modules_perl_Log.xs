$NetBSD: patch-src_modules_perl_Log.xs,v 1.1 2011/09/21 14:59:32 obache Exp $

* fixes build with perl-5.14.

--- src/modules/perl/Log.xs.orig	2001-01-25 07:43:05.000000000 +0000
+++ src/modules/perl/Log.xs
@@ -10,7 +10,7 @@
 static void perl_cv_alias(char *to, char *from)
 {
     GV *gp = gv_fetchpv(to, TRUE, SVt_PVCV);
-    GvCV(gp) = perl_get_cv(from, TRUE);
+    GvCV_set(gp, perl_get_cv(from, TRUE));
 }
 
 static void ApacheLog(int level, SV *sv, SV *msg)
