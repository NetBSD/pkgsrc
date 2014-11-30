$NetBSD: patch-mlterm_ml__term.c,v 1.1 2014/11/30 13:26:00 tsutsui Exp $

--- mlterm/ml_term.c.orig	2014-10-27 22:25:45.000000000 +0000
+++ mlterm/ml_term.c
@@ -1353,7 +1353,7 @@ ml_term_get_config(
 	}
 	else
 	{
-		ml_response_config( term->pty , key , value , to_menu) ;
+		ml_response_config( output->pty , key , value , to_menu) ;
 	}
 
 	return  1 ;
