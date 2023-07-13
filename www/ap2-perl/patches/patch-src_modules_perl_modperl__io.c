$NetBSD: patch-src_modules_perl_modperl__io.c,v 1.1 2023/07/13 18:29:37 jperkin Exp $

Pull in upstream fix for newer perl.
https://github.com/apache/mod_perl/commit/991cfeca9bac185f191510e0064f174d45718e6a

--- src/modules/perl/modperl_io.c.orig	2022-01-30 13:02:22.000000000 +0000
+++ src/modules/perl/modperl_io.c
@@ -116,8 +116,8 @@ modperl_io_perlio_override_stdhandle(pTH
     save_gp(handle, 1);
 
     sv_setref_pv(sv, "Apache2::RequestRec", (void*)r);
-    status = do_open9(handle, mode == O_RDONLY ? "<:Apache2" : ">:Apache2",
-                      9, FALSE, mode, 0, (PerlIO *)NULL, sv, 1);
+    status = do_openn(handle, mode == O_RDONLY ? "<:Apache2" : ">:Apache2",
+                      9, FALSE, mode, 0, (PerlIO *)NULL, &sv, 1);
     if (status == 0) {
         Perl_croak(aTHX_ "Failed to open STD%s: %" SVf,
                    mode == O_RDONLY ? "IN" : "OUT", get_sv("!", TRUE));
