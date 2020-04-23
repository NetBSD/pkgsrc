$NetBSD: patch-src_capture.c,v 1.1 2020/04/23 14:31:12 nia Exp $

Fix build without SHMAT.

--- src/capture.c.orig	2008-05-25 22:01:53.000000000 +0000
+++ src/capture.c
@@ -647,6 +647,7 @@ XGetZPixmapToXImage (Display * dpy, Draw
                         image->width, image->height);
 }
 
+#ifdef HAVE_SHMAT
 /**
  * \brief reads data from the Xserver to a chunk of memory on the client.
  *      This version uses shared memory access to X11.
@@ -706,6 +707,7 @@ XGetZPixmapSHM (Display * dpy, Drawable 
     return (True);
 #undef DEBUGFUNCTION
 }
+#endif
 
 /**
  * \brief copies a small image into another larger image
@@ -1653,13 +1655,17 @@ commonCapture (enum captureFunctions cap
                 XDestroyImage (image);
                 image = NULL;
             }
+#ifdef HAVE_SHMAT
             if (capfunc == SHM)
                 XShmDetach (app->dpy, &shminfo);
+#endif
 
 #ifdef USE_XDAMAGE
             if (app->flags & FLG_USE_XDAMAGE) {
+#ifdef HAVE_SHMAT
                 if (capfunc == SHM)
                     XShmDetach (app->dpy, &dmg_shminfo);
+#endif
                 if (dmg_image)
                     XDestroyImage (dmg_image);
             }
