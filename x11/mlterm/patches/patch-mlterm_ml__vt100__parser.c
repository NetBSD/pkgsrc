$NetBSD: patch-mlterm_ml__vt100__parser.c,v 1.1 2013/12/14 16:30:18 tsutsui Exp $

Pull fix from upstream ba3a5a22ae82b7c227cfd9f952881a281c53f82a:
 * ml_vt100_parser.c: U+200c-200f and U+202a-202e aren't converted
  even if -n option is specified.

--- mlterm/ml_vt100_parser.c.orig	2013-11-22 15:31:23.000000000 +0000
+++ mlterm/ml_vt100_parser.c
@@ -246,7 +246,7 @@ is_noconv_unicode(
 	u_char *  ch
 	)
 {
-	if( unicode_noconv_areas)
+	if( unicode_noconv_areas || ch[2] == 0x20)
 	{
 		u_int  count ;
 		u_int32_t  code ;
@@ -261,6 +261,16 @@ is_noconv_unicode(
 				return  1 ;
 			}
 		}
+
+		/*
+		 * Don't convert these characters in order not to show them.
+		 * see ml_char_cols().
+		 */
+		if( ( 0x200c <= code && code <= 0x200f) ||
+		    ( 0x202a <= code && code <= 0x202e))
+		{
+			return  1 ;
+		}
 	}
 
 	return  0 ;
