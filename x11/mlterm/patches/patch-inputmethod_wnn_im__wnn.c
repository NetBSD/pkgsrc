$NetBSD: patch-inputmethod_wnn_im__wnn.c,v 1.1 2015/06/13 21:25:45 tsutsui Exp $

- Pull the following Romanized Japanese conversion updates for wnn:
 https://bitbucket.org/arakiken/mlterm/commits/8de212cf5b3ec7f77ce1f9f6aa66770cb28b935e

--- inputmethod/wnn/im_wnn.c.orig	2015-06-07 01:36:25.000000000 +0000
+++ inputmethod/wnn/im_wnn.c
@@ -407,12 +407,12 @@ insert_char(
 		{ 0xa4d0 , 0xa4d3 , 0xa4d6 , 0xa4d9 , 0xa4dc } , /* b */
 		{ 0xa4ab , 0xa4ad , 0xa4af , 0xa4b1 , 0xa4b3 } , /* c */
 		{ 0xa4c0 , 0xa4c2 , 0xa4c5 , 0xa4c7 , 0xa4c9 } , /* d */
-		{ 0xa4e3 , 0 ,      0xa4e5 , 0      , 0xa4e7 } , /* xy */
-		{ 0 ,      0 ,      0 ,      0 ,      0 ,    } ,
+		{ 0xa4e3 , 0xa4a3 , 0xa4e5 , 0xa4a7 , 0xa4e7 } , /* xy */
+		{ 0 ,      0 ,      0xa4d5 , 0 ,      0 ,    } , /* f */
 		{ 0xa4ac , 0xa4ae , 0xa4b0 , 0xa4b2 , 0xa4b4 } , /* g */
 		{ 0xa4cf , 0xa4d2 , 0xa4d5 , 0xa4d8 , 0xa4db } , /* h */
-		{ 0 ,      0 ,      0 ,      0 ,      0 ,    } ,
-		{ 0 ,      0 ,      0 ,      0 ,      0 ,    } ,
+		{ 0xa4e3 , 0 ,      0xa4e5 , 0xa4a7 , 0xa4e7 } , /* ch/sh */
+		{ 0 ,      0xa4b8 , 0 ,      0 ,      0 ,    } , /* j */
 		{ 0xa4ab , 0xa4ad , 0xa4af , 0xa4b1 , 0xa4b3 } , /* k */
 		{ 0xa4a1 , 0xa4a3 , 0xa4a5 , 0xa4a7 , 0xa4a9 } , /* l */
 		{ 0xa4de , 0xa4df , 0xa4e0 , 0xa4e1 , 0xa4e2 } , /* m */
@@ -433,7 +433,7 @@ insert_char(
 	static wchar  sign_table1[] =
 	{
 	                 0xa1aa , 0xa1c9 , 0xa1f4 , 0xa1f0 , 0xa1f3 , 0xa1f5 , 0xa1c7 ,
-		0xa1ca , 0xa1cb , 0xa1f6 , 0xa1dc , 0xa1a4 , 0xa1bd , 0xa1a3 , 0xa1bf ,
+		0xa1ca , 0xa1cb , 0xa1f6 , 0xa1dc , 0xa1a4 , 0xa1bc , 0xa1a3 , 0xa1bf ,
 		0xa3b0 , 0xa3b1 , 0xa3b2 , 0xa3b3 , 0xa3b4 , 0xa3b5 , 0xa3b6 , 0xa3b7 ,
 		0xa3b8 , 0xa3b9 , 0xa1a7 , 0xa1a8 , 0xa1e3 , 0xa1e1 , 0xa1e4 , 0xa1a9 ,
 		0xa1f7 ,
@@ -453,30 +453,83 @@ insert_char(
 		jcDeleteChar( wnn->convbuf , 1) ;
 	}
 
-	if( key_char == 'a')
-	{
-		wch = kana_table[wnn->dan].a ;
-		wnn->dan = 0 ;
-	}
-	else if( key_char == 'i')
-	{
-		wch = kana_table[wnn->dan].i ;
-		wnn->dan = 0 ;
-	}
-	else if( key_char == 'u')
+	if( key_char == 'a' || key_char == 'i' || key_char == 'u' ||
+	    key_char == 'e' || key_char == 'o')
 	{
-		wch = kana_table[wnn->dan].u ;
-		wnn->dan = 0 ;
-	}
-	else if( key_char == 'e')
-	{
-		wch = kana_table[wnn->dan].e ;
-		wnn->dan = 0 ;
-	}
-	else if( key_char == 'o')
-	{
-		wch = kana_table[wnn->dan].o ;
-		wnn->dan = 0 ;
+		if( wnn->dan == 'f' - 'a')
+		{
+			if( key_char != 'u')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4d5) ;	/* hu */
+				wnn->dan = 'x' - 'a' ;
+			}
+		}
+		else if( wnn->dan == 'j' - 'a')
+		{
+			if( key_char != 'i')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b8) ;	/* zi */
+				wnn->dan = 'e' - 'a' ;
+			}
+		}
+
+		if( key_char == 'a')
+		{
+			wch = kana_table[wnn->dan].a ;
+			wnn->dan = 0 ;
+		}
+		else if( key_char == 'i')
+		{
+			if( wnn->dan == 'i' - 'a')
+			{
+				wnn->dan = 0 ;
+
+				return  0 ;	/* shi/chi */
+			}
+
+			wch = kana_table[wnn->dan].i ;
+			wnn->dan = 0 ;
+		}
+		else if( key_char == 'u')
+		{
+			if( wnn->dan == 'j' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b8) ;	/* zi */
+				wnn->dan = 'e' - 'a' ;
+			}
+			wch = kana_table[wnn->dan].u ;
+			wnn->dan = 0 ;
+		}
+		else if( key_char == 'e')
+		{
+			if( wnn->dan == 'f' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4d5) ;	/* hu */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'j' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b8) ;	/* zi */
+				wnn->dan = 'x' - 'a' ;
+			}
+			wch = kana_table[wnn->dan].e ;
+			wnn->dan = 0 ;
+		}
+		else /* if( key_char == 'o') */
+		{
+			if( wnn->dan == 'f' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4d5) ;	/* hu */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'j' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b8) ;	/* zi */
+				wnn->dan = 'e' - 'a' ;
+			}
+			wch = kana_table[wnn->dan].o ;
+			wnn->dan = 0 ;
+		}
 	}
 	else if( ( '!' <= key_char && key_char <= '@') ||
 	         ( '[' <= key_char && key_char <= '_') ||
@@ -508,6 +561,11 @@ insert_char(
 			wch = 0xa4f3 ;	/* n */
 			wnn->dan = 0 ;
 		}
+		else if( key_char == wnn->dan + 'a')
+		{
+			jcInsertChar( wnn->convbuf , 0xa4c3) ;
+			wch = key_char ;
+		}
 		else if( key_char == 'y')
 		{
 			if( wnn->dan == 'k' - 'a')
@@ -520,6 +578,56 @@ insert_char(
 				jcInsertChar( wnn->convbuf , 0xa4ae) ;	/* gi */
 				wnn->dan = 'x' - 'a' ;
 			}
+			else if( wnn->dan == 's' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b7) ;	/* si */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'z' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b8) ;	/* zi */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 't' - 'a' || wnn->dan == 'c' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4c1) ;	/* ti */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'd' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4c2) ;	/* di */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'n' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4cb) ;	/* ni */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'h' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4d2) ;	/* hi */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'b' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4d3) ;	/* bi */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'p' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4d4) ;	/* pi */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'm' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4df) ;	/* mi */
+				wnn->dan = 'x' - 'a' ;
+			}
+			else if( wnn->dan == 'r' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4ea) ;	/* ri */
+				wnn->dan = 'x' - 'a' ;
+			}
 
 			if( wnn->dan == 'x' - 'a')
 			{
@@ -546,6 +654,24 @@ insert_char(
 				goto  normal ;
 			}
 		}
+		else if( key_char == 'h')
+		{
+			if( wnn->dan == 'c' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4c1) ;	/* ti */
+			}
+			else if( wnn->dan == 's' - 'a')
+			{
+				jcInsertChar( wnn->convbuf , 0xa4b7) ;	/* si */
+			}
+			else
+			{
+				goto  normal ;
+			}
+
+			wnn->dan = 'i' - 'a' ;
+			wch = 'h' ;
+		}
 		else
 		{
 		normal:
