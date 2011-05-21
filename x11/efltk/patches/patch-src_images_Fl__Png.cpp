$NetBSD: patch-src_images_Fl__Png.cpp,v 1.1 2011/05/21 08:18:16 obache Exp $

* fixes build with libpng>=1.5.

--- src/images/Fl_Png.cpp.orig	2003-07-13 15:07:26.000000000 +0000
+++ src/images/Fl_Png.cpp
@@ -18,17 +18,17 @@ bool setup_png_transformations(png_struc
 static void my_png_warning(png_structp png_ptr, png_const_charp message)
 {
     const char *name = "PNG: Unknown (WARNING!)";
-    if (png_ptr != NULL && png_ptr->error_ptr != NULL)
-        name = (const char *)png_ptr->error_ptr;
+    if (png_ptr != NULL && png_get_error_ptr(png_ptr) != NULL)
+        name = (const char *)png_get_error_ptr(png_ptr);
     Fl::warning("%s: libpng warning: %s", name, message);
 }
 
 static void my_png_error(png_structp png_ptr, png_const_charp message)
 {
     png_last_error = (volatile char*)"PNG: Unknown (ERROR!)";
-    if (png_ptr != NULL && png_ptr->error_ptr != NULL)
+    if (png_ptr != NULL && png_get_error_ptr(png_ptr) != NULL)
         png_last_error = (volatile char*)message;
-    longjmp(png_ptr->jmpbuf, 0);
+    png_longjmp(png_ptr, 0);
 }
 
 static bool png_is_valid_file(const char *filename)
@@ -56,7 +56,7 @@ static bool png_is_valid_mem(const uint8
 // PNG READ METHODS:
 
 static void read_data_fn(png_structp png_ptr, png_bytep d, png_size_t length) {
-    ((Fl_IO*)png_ptr->io_ptr)->read(d, length);
+    ((Fl_IO*)png_get_io_ptr(png_ptr))->read(d, length);
 }
 
 #define return_error() \
@@ -81,7 +81,7 @@ static bool png_create(Fl_IO &png_io, ui
     if(!end_info_ptr) { return_error(); }
 
     png_bytepp rows = 0;
-    if(setjmp(png_ptr->jmpbuf)) {
+    if(setjmp(png_jmpbuf(png_ptr))) {
         if(rows) free(rows);
         if(png_ptr) png_destroy_read_struct (&png_ptr, &info_ptr, &end_info_ptr);
         fputs((const char *)png_last_error, stderr);
@@ -94,6 +94,8 @@ static bool png_create(Fl_IO &png_io, ui
     int i=0;
     uint32 Rmask=0, Gmask=0, Bmask=0, Amask=0;
     png_color_16 *transv=0;
+    png_colorp png_palette;
+    int png_num_palette;
     Fl_Colormap *palette=0;
 
     png_set_error_fn(png_ptr, (png_voidp)0, my_png_error, my_png_warning);
@@ -108,15 +110,15 @@ static bool png_create(Fl_IO &png_io, ui
         Rmask = 0x000000FF;
         Gmask = 0x0000FF00;
         Bmask = 0x00FF0000;
-        Amask = (info_ptr->channels == 4) ? 0xFF000000 : 0;
+        Amask = (png_get_channels(png_ptr, info_ptr) == 4) ? 0xFF000000 : 0;
 #else
-        int s = (info_ptr->channels == 4) ? 0 : 8;
+        int s = (png_get_channels(png_ptr, info_ptr) == 4) ? 0 : 8;
         Rmask = 0xFF000000 >> s;
         Gmask = 0x00FF0000 >> s;
         Bmask = 0x0000FF00 >> s;
         Amask = 0x000000FF >> s;
 #endif
-        if(info_ptr->channels == 4)
+        if(png_get_channels(png_ptr, info_ptr) == 4)
             fmt.masktype = FL_MASK_ALPHA;
     }
 
@@ -144,13 +146,13 @@ static bool png_create(Fl_IO &png_io, ui
                 palette->colors[i].g = i;
                 palette->colors[i].b = i;
             }
-        } else if(info_ptr->num_palette > 0 )
+        } else if(png_get_PLTE(png_ptr, info_ptr, &png_palette, &png_num_palette) != 0 )
         {
-            palette->ncolors = info_ptr->num_palette;
-            for( i=0; i<info_ptr->num_palette; ++i ) {
-                palette->colors[i].b = info_ptr->palette[i].blue;
-                palette->colors[i].g = info_ptr->palette[i].green;
-                palette->colors[i].r = info_ptr->palette[i].red;
+            palette->ncolors = png_num_palette;
+            for( i=0; i<png_num_palette; ++i ) {
+                palette->colors[i].b = png_palette[i].blue;
+                palette->colors[i].g = png_palette[i].green;
+                palette->colors[i].r = png_palette[i].red;
             }
         }
     }
@@ -178,10 +180,11 @@ bool setup_png_transformations(png_struc
 {
     int bit_depth, interlace_type, compression_type, filter_type;
     int channels;
+    png_uint_32 w, h;
 
     /* Get the image info */
     png_get_IHDR(png_ptr, info_ptr,
-                 (ulong*)&width, (ulong*)&height,
+                 &w, &h,
                  &bit_depth,
                  &col_type,
                  &interlace_type,
@@ -191,10 +194,10 @@ bool setup_png_transformations(png_struc
     /* Extract multiple pixels with bit depths of 1, 2, and 4 from a single
      * byte into separate bytes (useful for paletted and grayscale images).
      */
-    if (info_ptr->bit_depth < 8)
+    if (png_get_bit_depth(png_ptr, info_ptr) < 8)
         png_set_packing(png_ptr);
     /* tell libpng to strip 16 bit/color files down to 8 bits/color */
-    else if (info_ptr->bit_depth == 16)
+    else if (png_get_bit_depth(png_ptr, info_ptr) == 16)
         png_set_strip_16(png_ptr) ;
 
     /* scale greyscale values to the range 0..255 */
@@ -234,7 +237,7 @@ bool setup_png_transformations(png_struc
     /* Update the info the reflect our transformations */
     png_read_update_info(png_ptr, info_ptr);
     png_get_IHDR(png_ptr, info_ptr,
-                 (ulong*)&width, (ulong*)&height,
+                 &w, &h,
                  &bit_depth,
                  &col_type,
                  &interlace_type,
@@ -242,6 +245,8 @@ bool setup_png_transformations(png_struc
                  &filter_type);
     channels = png_get_channels(png_ptr, info_ptr);
     bitspp = bit_depth*channels;
+    width = w;
+    height = h;
 
     if(channels < 1 || channels > 4) {
         return false;
@@ -254,7 +259,7 @@ bool setup_png_transformations(png_struc
 // PNG WRITE METHODS:
 
 static void write_data_fn(png_structp png_ptr, png_bytep d, png_size_t length) {
-    ((Fl_IO*)png_ptr->io_ptr)->write(d, length);
+    ((Fl_IO*)png_get_io_ptr(png_ptr))->write(d, length);
     //png_io.write(d, length);
 }
 
@@ -318,7 +323,7 @@ static bool png_write(Fl_IO &png_io, con
 
     bool allocated = false;
     uint8 *wr_data = (uint8*)data;
-    if(setjmp(png_ptr->jmpbuf)) {
+    if(setjmp(png_jmpbuf(png_ptr))) {
         if(png_ptr) png_destroy_write_struct(&png_ptr, &info_ptr);
         if(allocated && wr_data) free(wr_data);
         return false;
@@ -373,7 +378,6 @@ static bool png_write(Fl_IO &png_io, con
      * PNG_INTERLACE_ADAM7, and the compression_type and filter_type MUST
      * currently be PNG_COMPRESSION_TYPE_BASE and PNG_FILTER_TYPE_BASE. REQUIRED
      */
-    info_ptr->channels = wr_fmt->bytespp;
     png_set_IHDR(png_ptr, info_ptr, w, h,
                  (wr_fmt->bitspp==1) == 1 ? 1 : 8 /* per channel */,
 
@@ -385,9 +389,14 @@ static bool png_write(Fl_IO &png_io, con
                  PNG_FILTER_TYPE_BASE
                 );
 
-    info_ptr->sig_bit.red = 8;
-    info_ptr->sig_bit.green = 8;
-    info_ptr->sig_bit.blue = 8;
+    png_color_8 sig_bit;
+    sig_bit.red = 8;
+    sig_bit.green = 8;
+    sig_bit.blue = 8;
+    if(wr_fmt->Amask) {
+        sig_bit.alpha = 8;
+    }
+    png_set_sBIT(png_ptr, info_ptr, &sig_bit);
 #if !WORDS_BIGENDIAN
     if(wr_fmt->bitspp==1) png_set_packswap(png_ptr);
 #endif
@@ -418,10 +427,6 @@ static bool png_write(Fl_IO &png_io, con
         png_set_PLTE(png_ptr, info_ptr, palette, wr_fmt->palette->ncolors);
     }
 
-    if(wr_fmt->Amask) {
-        info_ptr->sig_bit.alpha = 8;
-    }
-
     /* Write the file header information.  REQUIRED */
     png_write_info(png_ptr, info_ptr);
 
