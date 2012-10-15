$NetBSD: patch-src_modules_perl_perl__util.c,v 1.3 2012/10/15 13:14:26 wiz Exp $

Remove uid code; similar to changes done to mod_perl-2.x, see
https://rt.cpan.org/Public/Bug/Display.html?id=77129

--- src/modules/perl/perl_util.c.orig	2007-12-03 07:19:59.000000000 +0000
+++ src/modules/perl/perl_util.c
@@ -669,15 +669,6 @@ void mod_perl_init_ids(void)  /* $$, $>,
 {
     if(set_ids++) return;
     sv_setiv(GvSV(gv_fetchpv("$", TRUE, SVt_PV)), (I32)getpid());
-#ifndef WIN32
-    uid  = (int)getuid(); 
-    euid = (int)geteuid(); 
-    gid  = (int)getgid(); 
-    egid = (int)getegid(); 
-    MP_TRACE_g(fprintf(stderr, 
-		     "perl_init_ids: uid=%d, euid=%d, gid=%d, egid=%d\n",
-		     uid, euid, gid, egid));
-#endif
 }
 
 int perl_eval_ok(server_rec *s)
