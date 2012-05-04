$NetBSD: patch-libAfterImage_asfont.c,v 1.1 2012/05/04 16:36:10 joerg Exp $

--- libAfterImage/asfont.c.orig	2012-05-04 14:38:20.000000000 +0000
+++ libAfterImage/asfont.c
@@ -1352,7 +1352,7 @@ utf8_to_unicode ( const unsigned char *s
     return 0;
 }
 
-inline ASGlyph *get_utf8_glyph( const char *utf8, ASFont *font )
+static ASGlyph *get_utf8_glyph( const char *utf8, ASFont *font )
 {
 	UNICODE_CHAR uc = utf8_to_unicode ( (const unsigned char*)utf8 );
 	return get_unicode_glyph( uc, font );
