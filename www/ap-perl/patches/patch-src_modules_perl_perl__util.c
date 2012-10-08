$NetBSD: patch-src_modules_perl_perl__util.c,v 1.1 2012/10/08 11:49:40 marino Exp $

GCC 4.7 requires variable declaration before use.

--- src/modules/perl/perl_util.c.orig	2007-12-03 07:19:59.000000000 +0000
+++ src/modules/perl/perl_util.c
@@ -670,6 +670,7 @@ void mod_perl_init_ids(void)  /* $$, $>,
     if(set_ids++) return;
     sv_setiv(GvSV(gv_fetchpv("$", TRUE, SVt_PV)), (I32)getpid());
 #ifndef WIN32
+    int uid, euid, gid, egid;
     uid  = (int)getuid(); 
     euid = (int)geteuid(); 
     gid  = (int)getgid(); 
