$NetBSD: patch-randr_randrstr.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

Implements RRSetChanged()

--- randr/randrstr.h.orig	2012-05-17 17:09:05.000000000 +0000
+++ randr/randrstr.h
@@ -438,6 +438,9 @@ extern _X_EXPORT void
 extern _X_EXPORT void
  RRTellChanged(ScreenPtr pScreen);
 
+extern _X_EXPORT void
+ RRSetChanged(ScreenPtr pScreen);
+
 /*
  * Poll the driver for changed information
  */
