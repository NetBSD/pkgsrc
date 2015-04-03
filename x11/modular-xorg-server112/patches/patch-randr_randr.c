$NetBSD: patch-randr_randr.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

Implements RRSetChanged()

--- randr/randr.c.orig	2012-08-02 00:30:15.000000000 +0000
+++ randr/randr.c
@@ -435,6 +435,14 @@ RRTellChanged(ScreenPtr pScreen)
     }
 }
 
+void
+RRSetChanged(ScreenPtr pScreen)
+{
+	rrScrPriv(pScreen);
+
+	pScrPriv->changed = TRUE;
+}
+
 /*
  * Return the first output which is connected to an active CRTC
  * Used in emulating 1.0 behaviour
