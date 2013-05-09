$NetBSD: patch-Tools_DumpRenderTree_gtk_ImageDiff.cpp,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Tools/DumpRenderTree/gtk/ImageDiff.cpp.orig	2013-05-02 21:03:34.000000000 +0000
+++ Tools/DumpRenderTree/gtk/ImageDiff.cpp
@@ -30,6 +30,7 @@
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
+#include <cstdlib>
 #include <cstring>
 #include <gdk/gdk.h>
 
@@ -157,7 +158,7 @@ void printImage(GdkPixbuf* image)
         return; // Don't bail out, as we can still use the percentage output.
     }
 
-    printf("Content-Length: %"G_GSIZE_FORMAT"\n", bufferSize);
+    printf("Content-Length: %" G_GSIZE_FORMAT "\n", bufferSize);
     fwrite(buffer, 1, bufferSize, stdout);
 }
 
