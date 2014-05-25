$NetBSD: patch-Source_NSBitmapImageRep+GIF.m,v 1.2 2014/05/25 07:18:44 obache Exp $

* Fixes build with giflib>5

--- Source/NSBitmapImageRep+GIF.m.orig	2011-02-28 15:43:25.000000000 +0000
+++ Source/NSBitmapImageRep+GIF.m
@@ -140,7 +140,7 @@ static int gs_gif_output(GifFileType *fi
     }
 
   gs_gif_init_input_source(&src, imageData);
-  file = DGifOpen(&src, gs_gif_input);
+  file = DGifOpen(&src, gs_gif_input, NULL);
   if (file == NULL)
     {
       /* we do not use giferror here because it doesn't
@@ -149,7 +149,7 @@ static int gs_gif_output(GifFileType *fi
       return NO;
     }
 
-  DGifCloseFile(file);
+  DGifCloseFile(file, NULL);
   return YES;
 }
 
@@ -168,7 +168,7 @@ static int gs_gif_output(GifFileType *fi
    SET_ERROR_MSG(msg); \
    if (file != NULL) \
      {\
-       DGifCloseFile(file); \
+       DGifCloseFile(file, NULL); \
      }\
    if (imgBuffer != NULL) \
      {\
@@ -214,7 +214,7 @@ static int gs_gif_output(GifFileType *fi
 
   /* open the image */
   gs_gif_init_input_source(&src, imageData);
-  file = DGifOpen(&src, gs_gif_input);
+  file = DGifOpen(&src, gs_gif_input, NULL);
   if (file == NULL)
     {
       /* we do not use giferror here because it doesn't
@@ -376,7 +376,7 @@ static int gs_gif_output(GifFileType *fi
           withValue: [NSNumber numberWithInt: 0]];
 
   /* don't forget to close the gif */
-  DGifCloseFile(file);
+  DGifCloseFile(file, NULL);
 
   return self;
 }
@@ -457,10 +457,10 @@ static int gs_gif_output(GifFileType *fi
   // If you have a color table, you must be certain that it is GIF format
   colorTable = [self valueForProperty: NSImageRGBColorTable];	// nil is OK
   colorMapSize = (colorTable)? [colorTable length]/sizeof(GifColorType) : 256;
-  GIFColorMap = MakeMapObject(colorMapSize, [colorTable bytes]);
+  GIFColorMap = GifMakeMapObject(colorMapSize, [colorTable bytes]);
   if (!GIFColorMap)
     {
-      SET_ERROR_MSG(@"GIFRepresentation (giflib): MakeMapObject() failed.");
+      SET_ERROR_MSG(@"GIFRepresentation (giflib): GifMakeMapObject() failed.");
       free(rgbPlanes);
       return nil;
     }
@@ -471,7 +471,7 @@ static int gs_gif_output(GifFileType *fi
       SET_ERROR_MSG(@"GIFRepresentation: malloc out of memory.");
       free(rgbPlanes);
     }
-  status = QuantizeBuffer(width, height, &colorMapSize,
+  status = GifQuantizeBuffer(width, height, &colorMapSize,
 		       redPlane, greenPlane, bluePlane,
 		       GIFImage, GIFColorMap->Colors);
   if (status == GIF_ERROR)
@@ -481,7 +481,7 @@ static int gs_gif_output(GifFileType *fi
       return nil;
     }
 
-  // QuantizeBuffer returns an optimized colorMapSize,
+  // GifQuantizeBuffer returns an optimized colorMapSize,
   // but we must round up to nearest power of 2
   // otherwise MakeColorMap() fails
   for (h = 0; h < 8; h++)
@@ -499,7 +499,7 @@ static int gs_gif_output(GifFileType *fi
       free(GIFImage);
       return nil;
     }
-  GIFFile = EGifOpen(GIFRep, gs_gif_output);
+  GIFFile = EGifOpen(GIFRep, gs_gif_output, NULL);
   status = EGifPutScreenDesc(GIFFile, width, height, 8, 0, NULL);
   if (status == GIF_ERROR)
     {
@@ -509,7 +509,7 @@ static int gs_gif_output(GifFileType *fi
     }
 
   // note we are not supporting interlaced mode
-  status = EGifPutImageDesc(GIFFile, 0, 0, width, height, FALSE, GIFColorMap);
+  status = EGifPutImageDesc(GIFFile, 0, 0, width, height, 0, GIFColorMap);
   if (status == GIF_ERROR)
     {
       SET_ERROR_MSG(@"GIFRepresentation (giflib): EGifPutImageDesc() failed.");
@@ -529,7 +529,7 @@ static int gs_gif_output(GifFileType *fi
 	}
       GIFImageP += width;
     }
-  status = EGifCloseFile(GIFFile);
+  status = EGifCloseFile(GIFFile, NULL);
 
   free(GIFImage);
 
