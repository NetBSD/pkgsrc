$NetBSD: patch-src_modules_perl_mod__perl.c,v 1.1 2011/09/21 14:59:32 obache Exp $

* fixes build with perl-5.14.

--- src/modules/perl/mod_perl.c.orig	2008-11-20 18:12:31.000000000 +0000
+++ src/modules/perl/mod_perl.c
@@ -785,7 +785,7 @@ void perl_startup (server_rec *s, pool *
     /* *CORE::GLOBAL::exit = \&Apache::exit */
     if(gv_stashpv("CORE::GLOBAL", FALSE)) {
 	GV *exitgp = gv_fetchpv("CORE::GLOBAL::exit", TRUE, SVt_PVCV);
-	GvCV(exitgp) = perl_get_cv("Apache::exit", TRUE);
+	GvCV_set(exitgp, perl_get_cv("Apache::exit", TRUE));
 	GvIMPORTED_CV_on(exitgp);
     }
 
