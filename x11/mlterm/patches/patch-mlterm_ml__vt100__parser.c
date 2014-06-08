$NetBSD: patch-mlterm_ml__vt100__parser.c,v 1.3 2014/06/08 16:46:25 tsutsui Exp $

Pull post-3.3.6 fix:
 * Fix the failure of saving font configurations from mlconfig.
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.6/mlterm-3.3.6-fixes.patch/download

--- mlterm/ml_vt100_parser.c.orig	2014-05-25 05:42:15.000000000 +0000
+++ mlterm/ml_vt100_parser.c
@@ -1553,7 +1553,12 @@ config_protocol_set(
 {
 	char *  dev ;
 
-	dev = ml_parse_proto_prefix( &pt) ;
+	if( ml_parse_proto_prefix( &dev , &pt , save) == -1)
+	{
+		kik_msg_printf( "Forbid config protocol.\n") ;
+
+		return ;
+	}
 
 	if( strcmp( pt , "gen_proto_challenge") == 0)
 	{
@@ -1689,7 +1694,7 @@ config_protocol_set(
 		char *  key ;
 		char *  val ;
 
-		if( ml_parse_proto( NULL , &key , &val , &pt , save , 0) && val &&
+		if( ml_parse_proto( NULL , &key , &val , &pt , 0 , 0) && val &&
 		    HAS_CONFIG_LISTENER(vt100_parser,set_font))
 		{
 			/*
@@ -1716,7 +1721,7 @@ config_protocol_set(
 		char *  key ;
 		char *  val ;
 
-		if( ml_parse_proto( NULL , &key , &val , &pt , save , 0) && val &&
+		if( ml_parse_proto( NULL , &key , &val , &pt , 0 , 0) && val &&
 		    HAS_CONFIG_LISTENER(vt100_parser,set_color))
 		{
 			/*
@@ -1772,7 +1777,7 @@ config_protocol_set(
 				char *  val ;
 
 				if( ! ml_parse_proto( dev ? NULL : &dev ,
-						&key , &val , &pt , save , 1))
+						&key , &val , &pt , 0 , 1))
 				{
 					break ;
 				}
