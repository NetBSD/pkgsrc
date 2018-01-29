$NetBSD: patch-src_gtk_dcclient.cpp,v 1.1 2018/01/29 15:12:54 jperkin Exp $

Backport narrowing conversion fix from wxGTK30.

--- src/gtk/dcclient.cpp.orig	2011-03-22 12:18:57.000000000 +0000
+++ src/gtk/dcclient.cpp
@@ -428,12 +428,12 @@ void wxWindowDC::SetUpDC()
     if (!hatch_bitmap)
     {
         hatch_bitmap    = hatches;
-        hatch_bitmap[0] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, bdiag_bits, bdiag_width, bdiag_height );
-        hatch_bitmap[1] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, cdiag_bits, cdiag_width, cdiag_height );
-        hatch_bitmap[2] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, fdiag_bits, fdiag_width, fdiag_height );
-        hatch_bitmap[3] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, cross_bits, cross_width, cross_height );
-        hatch_bitmap[4] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, horiz_bits, horiz_width, horiz_height );
-        hatch_bitmap[5] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, verti_bits, verti_width, verti_height );
+        hatch_bitmap[0] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, reinterpret_cast<const char*>(bdiag_bits), bdiag_width, bdiag_height );
+        hatch_bitmap[1] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, reinterpret_cast<const char*>(cdiag_bits), cdiag_width, cdiag_height );
+        hatch_bitmap[2] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, reinterpret_cast<const char*>(fdiag_bits), fdiag_width, fdiag_height );
+        hatch_bitmap[3] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, reinterpret_cast<const char*>(cross_bits), cross_width, cross_height );
+        hatch_bitmap[4] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, reinterpret_cast<const char*>(horiz_bits), horiz_width, horiz_height );
+        hatch_bitmap[5] = gdk_bitmap_create_from_data( (GdkWindow *) NULL, reinterpret_cast<const char*>(verti_bits), verti_width, verti_height );
     }
 }
 
