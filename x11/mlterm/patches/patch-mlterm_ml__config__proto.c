$NetBSD: patch-mlterm_ml__config__proto.c,v 1.1 2014/06/08 16:46:25 tsutsui Exp $

Pull post-3.3.6 fix:
 * Fix the failure of saving font configurations from mlconfig.
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.6/mlterm-3.3.6-fixes.patch/download

--- mlterm/ml_config_proto.c.orig	2014-05-25 05:42:15.000000000 +0000
+++ mlterm/ml_config_proto.c
@@ -63,27 +63,6 @@ read_challenge(void)
 	return  1 ;
 }
 
-static int
-challenge_it(
-	char *  chal
-	)
-{
-	if( challenge && strcmp( chal , challenge) == 0)
-	{
-		return  1 ;
-	}
-	
-	/*
-	 * Challenge could be re-generated.
-	 */
-	if( read_challenge() && challenge && strcmp( chal , challenge) == 0)
-	{
-		return  1 ;
-	}
-	
-	return  0 ;
-}
-
 
 /* --- global functions --- */
 
@@ -138,15 +117,44 @@ ml_gen_proto_challenge(void)
 	return  1 ;
 }
 
-char *
+/*
+ * Returns 0 if dev is not found.
+ * Returns -1 if do_challenge is 1 and challenge failed.
+ */
+int
 ml_parse_proto_prefix(
-	char **  str
+	char **  dev ,	/* can be NULL */
+	char **  str ,
+	int  do_challenge
 	)
 {
-	char *  beg ;
 	char *  p ;
 
-	beg = p = *str ;
+	p = *str ;
+
+	while( do_challenge)
+	{
+		char *  chal ;
+
+		chal = p ;
+
+		if( ( p = strchr( p , ';')))
+		{
+			*(p ++) = '\0' ;
+
+			if( ( challenge && strcmp( chal , challenge) == 0) ||
+			    /* Challenge could have been re-generated. */
+			    ( read_challenge() && challenge && strcmp( chal , challenge) == 0))
+			{
+				/* challenge succeeded. */
+				break ;
+			}
+		}
+
+		return  -1 ;
+	}
+
+	*str = p ;	/* for no_dev */
 
 	if( strncmp( p , "/dev" , 4) == 0)
 	{
@@ -161,7 +169,7 @@ ml_parse_proto_prefix(
 				kik_warn_printf( KIK_DEBUG_TAG " Illegal protocol format.\n") ;
 			#endif
 
-				return  NULL ;
+				goto  no_dev ;
 			}
 		}
 	}
@@ -187,15 +195,28 @@ ml_parse_proto_prefix(
 			}
 			else
 			{
-				return  NULL ;
+				goto  no_dev ;
 			}
 		}
 	}
 
+	if( dev)
+	{
+		*dev = *str ;
+	}
+
 	*(p ++) = '\0' ;
 	*str = p ;
 
-	return  beg ;
+	return  1 ;
+
+no_dev:
+	if( dev)
+	{
+		*dev = NULL ;
+	}
+
+	return  0 ;
 }
 
 /*
@@ -214,36 +235,12 @@ ml_parse_proto(
 	)
 {
 	char *  p ;
-	char *  _dev ;
 
 	p = *str ;
-	
-	if( do_challenge)
-	{
-		char *  chal ;
-
-		chal = p ;
 
-		if( ( p = strchr( p , ';')) == NULL)
-		{
-			/* Illegal format */
-
-		#ifdef  DEBUG
-			kik_warn_printf( KIK_DEBUG_TAG " Illegal protocol format.\n") ;
-		#endif
-
-			return  0 ;
-		}
-
-		*(p ++) = '\0' ;
-
-		if( ! challenge_it( chal))
-		{
-			kik_msg_printf( "Protocol 5380 is not permitted "
-				"because client password is wrong.\n") ;
-
-			return  -1 ;
-		}
+	if( ml_parse_proto_prefix( dev , &p , do_challenge) < 0)
+	{
+		return  -1 ;
 	}
 
 	if( sep_by_semicolon)
@@ -259,12 +256,6 @@ ml_parse_proto(
 		*str = NULL ;
 	}
 
-	_dev = ml_parse_proto_prefix( &p) ;
-	if( dev)
-	{
-		*dev = _dev ;
-	}
-	
 	if( key)
 	{
 		*key = p ;
