$NetBSD: patch-khtml_imload_decoders_gifloader.cpp,v 1.1 2014/05/18 12:27:51 markd Exp $

Fix build with giflib 5.1.

--- khtml/imload/decoders/gifloader.cpp.orig	2014-01-02 19:26:52.000000000 +0000
+++ khtml/imload/decoders/gifloader.cpp
@@ -369,7 +369,7 @@ public:
         
         if (DGifSlurp(file) == GIF_ERROR)
         {
-            DGifCloseFile(file);
+            DGifCloseFile(file, NULL);
             return Error;
         }
         
@@ -378,7 +378,7 @@ public:
         if (file->ImageCount > 1) {
             // Verify it..
             if (!ImageManager::isAcceptableSize(file->SWidth, file->SHeight)) {
-                DGifCloseFile(file);
+                DGifCloseFile(file, NULL);
                 return Error;
             }
             notifyImageInfo(file->SWidth, file->SHeight);
@@ -390,7 +390,7 @@ public:
             //Extract colormap, geometry, so that we can create the frame
             SavedImage* curFrame = &file->SavedImages[frame];
             if (!ImageManager::isAcceptableSize(curFrame->ImageDesc.Width, curFrame->ImageDesc.Height)) {
-                DGifCloseFile(file);
+                DGifCloseFile(file, NULL);
                 return Error;
             }
         }
@@ -574,7 +574,7 @@ public:
             frame0->animProvider = new GIFAnimProvider(frame0, image, frameProps, bgColor);
         }
         
-        DGifCloseFile(file);
+        DGifCloseFile(file, NULL);
 
         return Done;
     }
