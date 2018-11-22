$NetBSD: patch-src_wmapp.cc,v 1.1 2018/11/22 04:56:03 ryo Exp $

--- src/wmapp.cc.orig	2013-11-17 16:54:39.000000000 +0000
+++ src/wmapp.cc
@@ -621,14 +621,21 @@ static void initPixmaps() {
 
         for (int a = 0; a <= 1; a++) {
             for (int b = 0; b <= 1; b++) {
-                frameT[a][b]->replicate(true, copyMask);
-                frameB[a][b]->replicate(true, copyMask);
-                frameL[a][b]->replicate(false, copyMask);
-                frameR[a][b]->replicate(false, copyMask);
+                if (frameT[a][b] != null)
+                    frameT[a][b]->replicate(true, copyMask);
+                if (frameB[a][b] != null)
+                    frameB[a][b]->replicate(true, copyMask);
+                if (frameL[a][b] != null)
+                    frameL[a][b]->replicate(false, copyMask);
+                if (frameR[a][b] != null)
+                    frameR[a][b]->replicate(false, copyMask);
             }
-            titleS[a]->replicate(true, copyMask);
-            titleT[a]->replicate(true, copyMask);
-            titleB[a]->replicate(true, copyMask);
+            if (titleS[a] != null)
+                titleS[a]->replicate(true, copyMask);
+            if (titleT[a] != null)
+                titleT[a]->replicate(true, copyMask);
+            if (titleB[a] != null)
+                titleB[a]->replicate(true, copyMask);
         }
 
         menuButton[0] = paths->loadPixmap(0, "menuButtonI.xpm");
