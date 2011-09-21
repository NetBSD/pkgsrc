$NetBSD: patch-src_modules_perl_perl__config.c,v 1.1 2011/09/21 14:59:32 obache Exp $

* fixes build with perl-5.14.

--- src/modules/perl/perl_config.c.orig	2003-03-14 04:55:59.000000000 +0000
+++ src/modules/perl/perl_config.c
@@ -1720,7 +1720,7 @@ void perl_clear_symtab(HV *symtab) 
 	if((cv = GvCV((GV*)val)) && (GvSTASH((GV*)val) == GvSTASH(CvGV(cv)))) {
             GV *gv = CvGV(cv);
             cv_undef(cv);
-            CvGV(cv) = gv;
+            CvGV_set(cv, gv);
             GvCVGEN(gv) = 1; /* invalidate method cache */
         }
     }
