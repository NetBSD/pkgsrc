$NetBSD: patch-src_wmapp.cc,v 1.2 2018/11/22 04:56:03 ryo Exp $

* Avoid passing 4-byte aligned data to 8-byte aligned needing functions.
* Avoid calling method with null instance.

--- src/wmapp.cc.orig	2009-11-08 18:59:46.000000000 +0000
+++ src/wmapp.cc
@@ -219,6 +219,7 @@ static void registerProtocols2(Window xi
 #endif
 
     pid_t pid = getpid();
+    long lpid = (long)pid;
     const char wmname[] = "IceWM "VERSION" ("HOSTOS"/"HOSTCPU")";
 
 #ifdef GNOME1_HINTS
@@ -238,7 +239,7 @@ static void registerProtocols2(Window xi
 
     XChangeProperty(xapp->display(), xid,
                     _XA_NET_WM_PID, XA_CARDINAL, 32,
-                    PropModeReplace, (unsigned char *)&pid, 1);
+                    PropModeReplace, (unsigned char *)&lpid, 1);
 
     XChangeProperty(xapp->display(), xid,
                     _XA_NET_WM_NAME, XA_STRING, 8,
@@ -607,14 +608,21 @@ static void initPixmaps() {
 
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
 
         menuButton[0] = paths.loadPixmap(0, "menuButtonI.xpm");
