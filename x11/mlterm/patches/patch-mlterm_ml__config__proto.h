$NetBSD: patch-mlterm_ml__config__proto.h,v 1.1 2014/06/08 16:46:25 tsutsui Exp $

Pull post-3.3.6 fix:
 * Fix the failure of saving font configurations from mlconfig.
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.6/mlterm-3.3.6-fixes.patch/download

--- mlterm/ml_config_proto.h.orig	2014-05-25 05:42:15.000000000 +0000
+++ mlterm/ml_config_proto.h
@@ -16,7 +16,7 @@ int  ml_config_proto_final(void) ;
 
 int  ml_gen_proto_challenge(void) ;
 
-char *  ml_parse_proto_prefix( char **  str) ;
+int  ml_parse_proto_prefix( char **  dev , char **  str , int  do_challenge) ;
 
 int  ml_parse_proto( char **  dev , char **  key , char **  val , char **  str ,
 			int  do_challenge , int  sep_by_semicolon) ;
