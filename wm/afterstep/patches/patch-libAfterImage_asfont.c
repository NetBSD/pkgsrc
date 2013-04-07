$NetBSD: patch-libAfterImage_asfont.c,v 1.2 2013/04/07 10:36:54 cheusov Exp $

--- libAfterImage/asfont.c.orig	2008-08-15 21:47:37.000000000 +0000
+++ libAfterImage/asfont.c
@@ -367,7 +367,7 @@ release_font( ASFont *font )
 	return res ;
 }
 
-static inline void
+static void
 free_glyph_data( register ASGlyph *asg )
 {
     if( asg->pixmap )
@@ -1268,7 +1268,7 @@ load_freetype_glyphs( ASFont *font )
 }
 #endif
 
-static inline ASGlyph *get_unicode_glyph( const UNICODE_CHAR uc, ASFont *font )
+static ASGlyph *get_unicode_glyph( const UNICODE_CHAR uc, ASFont *font )
 {
 	register ASGlyphRange *r;
 	ASGlyph *asg = NULL ;
@@ -1300,7 +1300,7 @@ LOCAL_DEBUG_OUT( "%sFound glyph for char
 }
 
 
-static inline ASGlyph *get_character_glyph( const unsigned char c, ASFont *font )
+static ASGlyph *get_character_glyph( const unsigned char c, ASFont *font )
 {
 	return get_unicode_glyph( CHAR2UNICODE(c), font );
 }
@@ -1368,7 +1368,7 @@ utf8_to_unicode ( const unsigned char *s
     return 0;
 }
 
-static inline ASGlyph *get_utf8_glyph( const char *utf8, ASFont *font )
+static ASGlyph *get_utf8_glyph( const char *utf8, ASFont *font )
 {
 	UNICODE_CHAR uc = utf8_to_unicode ( (const unsigned char*)utf8 );
 	LOCAL_DEBUG_OUT( "translated to Unicode 0x%lX(%ld), UTF8 size = %d", uc, uc, UTF8_CHAR_SIZE(utf8[0]) );
@@ -1773,7 +1773,7 @@ get_fancy_text_size( const void *src_tex
 	return get_text_size_internal( src_text, font, &internal_attr, width, height, length, x_positions );
 }
 
-inline static void
+static void
 render_asglyph( CARD8 **scanlines, CARD8 *row,
                 int start_x, int y, int width, int height,
 				CARD32 ratio )
@@ -1812,7 +1812,7 @@ render_asglyph( CARD8 **scanlines, CARD8
 	}
 }
 
-inline static void
+static void
 render_asglyph_over( CARD8 **scanlines, CARD8 *row,
                 int start_x, int y, int width, int height,
 				CARD32 value )
