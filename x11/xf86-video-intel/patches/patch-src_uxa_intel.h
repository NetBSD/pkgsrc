$NetBSD: patch-src_uxa_intel.h,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/uxa/intel.h.orig	2014-12-09 20:41:25.000000000 +0000
+++ src/uxa/intel.h
@@ -196,7 +196,10 @@ typedef struct intel_screen_private {
 
 	int colorKey;
 	XF86VideoAdaptorPtr adaptor;
+
+#if !HAVE_NOTIFY_FD
 	ScreenBlockHandlerProcPtr BlockHandler;
+#endif
 	Bool overlayOn;
 
 	struct {
