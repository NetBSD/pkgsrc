$NetBSD: patch-mozilla_gfx_layers_client_ClientPaintedLayer.cpp,v 1.1 2020/06/16 09:09:02 nia Exp $

NetBSD has the same limitation on CrossProcessSemaphore
(non-functioning in NetBSD<9, leaky due to Firefox destroying
semaphores created across processes in NetBSD>=9)

--- mozilla/gfx/layers/client/ClientPaintedLayer.cpp.orig	2020-04-01 11:01:50.000000000 +0000
+++ mozilla/gfx/layers/client/ClientPaintedLayer.cpp
@@ -310,7 +310,7 @@ ClientLayerManager::CreatePaintedLayerWi
   NS_ASSERTION(InConstruction(), "Only allowed in construction phase");
   // The non-tiling ContentClient requires CrossProcessSemaphore which
   // isn't implemented for OSX.
-#ifdef XP_MACOSX
+#if defined(XP_MACOSX) || defined(__NetBSD__)
   if (true) {
 #else
   if (gfxPrefs::LayersTilesEnabled()) {
