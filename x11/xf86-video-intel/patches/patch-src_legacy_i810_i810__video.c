$NetBSD: patch-src_legacy_i810_i810__video.c,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/legacy/i810/i810_video.c.orig	2014-08-29 09:33:11.000000000 +0000
+++ src/legacy/i810/i810_video.c
@@ -77,7 +77,11 @@ static int I810PutImage( ScrnInfoPtr,
 static int I810QueryImageAttributes(ScrnInfoPtr, 
 	int, unsigned short *, unsigned short *,  int *, int *);
 
+#if !HAVE_NOTIFY_FD
 static void I810BlockHandler(BLOCKHANDLER_ARGS_DECL);
+#else
+static void I810BlockHandler(void *data, void *_timeout);
+#endif
 
 #define MAKE_ATOM(a) MakeAtom(a, sizeof(a) - 1, TRUE)
 
@@ -418,8 +422,14 @@ I810SetupImageVideo(ScreenPtr screen)
 
     pI810->adaptor = adapt;
 
+#if !HAVE_NOTIFY_FD
     pI810->BlockHandler = screen->BlockHandler;
     screen->BlockHandler = I810BlockHandler;
+#else
+    RegisterBlockAndWakeupHandlers(I810BlockHandler,
+				   (ServerWakeupHandlerProcPtr)NoopDDA,
+				   pScrn);
+#endif
 
     xvBrightness = MAKE_ATOM("XV_BRIGHTNESS");
     xvContrast   = MAKE_ATOM("XV_CONTRAST");
@@ -1135,6 +1145,7 @@ I810QueryImageAttributes(
     return size;
 }
 
+#if !HAVE_NOTIFY_FD
 static void
 I810BlockHandler (BLOCKHANDLER_ARGS_DECL)
 {
@@ -1172,7 +1183,38 @@ I810BlockHandler (BLOCKHANDLER_ARGS_DECL
         }
     }
 }
+#else
+static void
+I810BlockHandler(void *data, void *_timeout)
+{
+    ScrnInfoPtr pScrn = data;
+    I810Ptr      pI810 = I810PTR(pScrn);
+    I810PortPrivPtr pPriv = GET_PORT_PRIVATE(pScrn);
+    I810OverlayRegPtr overlay = (I810OverlayRegPtr) (pI810->FbBase + pI810->OverlayStart);
 
+    if(pPriv->videoStatus & TIMER_MASK) {
+	UpdateCurrentTime();
+	if(pPriv->videoStatus & OFF_TIMER) {
+	    if(pPriv->offTime < currentTime.milliseconds) {
+		/* Turn off the overlay */
+		overlay->OV0CMD &= 0xFFFFFFFE;
+		OVERLAY_UPDATE(pI810->OverlayPhysical);
+
+		pPriv->videoStatus = FREE_TIMER;
+		pPriv->freeTime = currentTime.milliseconds + FREE_DELAY;
+	    }
+	} else {  /* FREE_TIMER */
+	    if(pPriv->freeTime < currentTime.milliseconds) {
+		if(pPriv->linear) {
+		   xf86FreeOffscreenLinear(pPriv->linear);
+		   pPriv->linear = NULL;
+		}
+		pPriv->videoStatus = 0;
+	    }
+        }
+    }
+}
+#endif
 
 /***************************************************************************
  * Offscreen Images
@@ -1373,7 +1415,6 @@ I810DisplaySurface(
       UpdateCurrentTime();
       pI810Priv->videoStatus = FREE_TIMER;
       pI810Priv->freeTime = currentTime.milliseconds + FREE_DELAY;
-      pScrn->pScreen->BlockHandler = I810BlockHandler;
     }
 
     return Success;
