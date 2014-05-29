$NetBSD: patch-layout_generic_nsObjectFrame.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- layout/generic/nsObjectFrame.cpp.orig	2014-05-06 22:55:54.000000000 +0000
+++ layout/generic/nsObjectFrame.cpp
@@ -65,7 +65,7 @@
 #endif /* MOZ_LOGGING */
 #include "prlog.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "gfxQuartzNativeDrawing.h"
 #include "nsPluginUtilsOSX.h"
 #include "mozilla/gfx/QuartzSupport.h"
@@ -108,7 +108,7 @@ GetObjectFrameLog()
 }
 #endif /* PR_LOGGING */
 
-#if defined(XP_MACOSX) && !defined(__LP64__)
+#if defined(MOZ_WIDGET_COCOA) && !defined(__LP64__)
 
 // The header files QuickdrawAPI.h and QDOffscreen.h are missing on OS X 10.7
 // and up (though the QuickDraw APIs defined in them are still present) -- so
@@ -143,7 +143,7 @@ extern "C" {
   #endif /* __QDOFFSCREEN__ */
 }
 
-#endif /* #if defined(XP_MACOSX) && !defined(__LP64__) */
+#endif /* #if defined(MOZ_WIDGET_COCOA) && !defined(__LP64__) */
 
 using namespace mozilla;
 using namespace mozilla::gfx;
@@ -367,7 +367,7 @@ nsObjectFrame::PrepForDrawing(nsIWidget 
     nsRefPtr<nsDeviceContext> dx = viewMan->GetDeviceContext();
     mInnerView->AttachWidgetEventHandler(mWidget);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // On Mac, we need to invalidate ourselves since even windowed
     // plugins are painted through Thebes and we need to ensure
     // the Thebes layer containing the plugin is updated.
@@ -394,7 +394,7 @@ nsObjectFrame::PrepForDrawing(nsIWidget 
     // Changing to windowless mode changes the NPWindow geometry.
     FixupWindow(GetContentRectRelativeToSelf().Size());
 
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
     RegisterPluginForGeometryUpdates();
 #endif
   }
@@ -582,7 +582,7 @@ nsObjectFrame::FixupWindow(const nsSize&
 
   NS_ENSURE_TRUE_VOID(window);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   nsWeakFrame weakFrame(this);
   mInstanceOwner->FixUpPluginWindow(nsPluginInstanceOwner::ePluginPaintDisable);
   if (!weakFrame.IsAlive()) {
@@ -608,7 +608,7 @@ nsObjectFrame::FixupWindow(const nsSize&
   // on the Mac we need to set the clipRect to { 0, 0, 0, 0 } for now. This will keep
   // us from drawing on screen until the widget is properly positioned, which will not
   // happen until we have finished the reflow process.
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   window->clipRect.top = 0;
   window->clipRect.left = 0;
   window->clipRect.bottom = 0;
@@ -635,7 +635,7 @@ nsObjectFrame::CallSetWindow(bool aCheck
     return rv;
 
   nsPluginNativeWindow *window = (nsPluginNativeWindow *)win;
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   nsWeakFrame weakFrame(this);
   mInstanceOwner->FixUpPluginWindow(nsPluginInstanceOwner::ePluginPaintDisable);
   if (!weakFrame.IsAlive()) {
@@ -1090,7 +1090,7 @@ nsObjectFrame::NotifyPluginReflowObserve
 void
 nsObjectFrame::DidSetWidgetGeometry()
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   if (mInstanceOwner) {
     mInstanceOwner->FixUpPluginWindow(nsPluginInstanceOwner::ePluginPaintEnable);
   }
@@ -1111,7 +1111,7 @@ nsObjectFrame::DidSetWidgetGeometry()
 bool
 nsObjectFrame::IsOpaque() const
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   // ???
   return false;
 #elif defined(MOZ_WIDGET_ANDROID)
@@ -1125,7 +1125,7 @@ nsObjectFrame::IsOpaque() const
 bool
 nsObjectFrame::IsTransparentMode() const
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   // ???
   return false;
 #else
@@ -1172,7 +1172,7 @@ nsObjectFrame::BuildDisplayList(nsDispla
 
   DO_GLOBAL_REFLOW_COUNT_DSP("nsObjectFrame");
 
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
   if (mWidget && aBuilder->IsInTransform()) {
     // Windowed plugins should not be rendered inside a transform.
     return;
@@ -1184,7 +1184,7 @@ nsObjectFrame::BuildDisplayList(nsDispla
     mInstanceOwner->GetWindow(window);
     bool isVisible = window && window->width > 0 && window->height > 0;
     if (isVisible && aBuilder->ShouldSyncDecodeImages()) {
-  #ifndef XP_MACOSX
+  #ifndef MOZ_WIDGET_COCOA
       mInstanceOwner->UpdateWindowVisibility(true);
   #endif
     }
@@ -1292,7 +1292,7 @@ nsObjectFrame::PrintPlugin(nsRenderingCo
   window.clipRect.left = 0; window.clipRect.right = 0;
 
 // platform specific printing code
-#if defined(XP_MACOSX) && !defined(__LP64__)
+#if defined(MOZ_WIDGET_COCOA) && !defined(__LP64__)
 #pragma clang diagnostic ignored "-Wdeprecated-declarations"
   // Don't use this code if any of the QuickDraw APIs it currently requires
   // are missing (as they probably will be on OS X 10.8 and up).
@@ -1556,7 +1556,7 @@ nsObjectFrame::BuildLayer(nsDisplayListB
 
     NS_ASSERTION(layer->GetType() == Layer::TYPE_IMAGE, "Bad layer type");
     ImageLayer* imglayer = static_cast<ImageLayer*>(layer.get());
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (!mInstanceOwner->UseAsyncRendering()) {
       mInstanceOwner->DoCocoaEventDrawRect(r, nullptr);
     }
@@ -1666,7 +1666,7 @@ nsObjectFrame::PaintPlugin(nsDisplayList
 #endif
 
   // Screen painting code
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   // delegate all painting to the plugin instance.
   if (mInstanceOwner) {
     if (mInstanceOwner->GetDrawingModel() == NPDrawingModelCoreGraphics ||
@@ -1987,7 +1987,7 @@ nsObjectFrame::HandleEvent(nsPresContext
       return fm->FocusPlugin(GetContent());
   }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (anEvent->message == NS_PLUGIN_RESOLUTION_CHANGED) {
     double scaleFactor = 1.0;
     mInstanceOwner->GetContentsScaleFactor(&scaleFactor);
@@ -2009,7 +2009,7 @@ nsObjectFrame::HandleEvent(nsPresContext
   return rv;
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // we want to process some native mouse events in the cocoa event model
   if ((anEvent->message == NS_MOUSE_ENTER ||
        anEvent->message == NS_WHEEL_WHEEL) &&
@@ -2034,7 +2034,7 @@ nsObjectFrame::HandleEvent(nsPresContext
   // We need to be careful from this point because the call to
   // nsObjectFrameSuper::HandleEvent() might have killed us.
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (anEvent->message == NS_MOUSE_BUTTON_UP) {
     nsIPresShell::SetCapturingContent(nullptr, 0);
   }
@@ -2079,7 +2079,7 @@ nsObjectFrame::GetCursor(const nsPoint& 
 void
 nsObjectFrame::SetIsDocumentActive(bool aIsActive)
 {
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
   if (mInstanceOwner) {
     mInstanceOwner->UpdateDocumentActiveState(aIsActive);
   }
@@ -2154,7 +2154,7 @@ nsObjectFrame::EndSwapDocShells(nsIConte
     }
   }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (objectFrame->mWidget) {
     objectFrame->RegisterPluginForGeometryUpdates();
   }
@@ -2172,7 +2172,7 @@ NS_NewObjectFrame(nsIPresShell* aPresShe
 bool
 nsObjectFrame::IsPaintedByGecko() const
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   return true;
 #else
   return !mWidget;
