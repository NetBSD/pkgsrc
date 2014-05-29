$NetBSD: patch-dom_plugins_base_nsPluginInstanceOwner.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/nsPluginInstanceOwner.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/nsPluginInstanceOwner.h
@@ -18,7 +18,7 @@
 #include "nsWeakReference.h"
 #include "gfxRect.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "mozilla/gfx/QuartzSupport.h"
 #include <ApplicationServices/ApplicationServices.h>
 #endif
@@ -142,7 +142,7 @@ public:
 
 #ifdef XP_WIN
   void Paint(const RECT& aDirty, HDC aDC);
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
   void Paint(const gfxRect& aDirtyRect, CGContextRef cgContext);  
   void RenderCoreAnimation(CGContextRef aCGContext, int aWidth, int aHeight);
   void DoCocoaEventDrawRect(const gfxRect& aDrawRect, CGContextRef cgContext);
@@ -163,7 +163,7 @@ public:
 
   nsEventStatus ProcessEvent(const mozilla::WidgetGUIEvent& anEvent);
   
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   enum { ePluginPaintEnable, ePluginPaintDisable };
   
   NPDrawingModel GetDrawingModel();
@@ -194,11 +194,11 @@ public:
   // CoreGraphics drawing model).
   void BeginCGPaint();
   void EndCGPaint();
-#else // XP_MACOSX
+#else // MOZ_WIDGET_COCOA
   void UpdateWindowPositionAndClipRect(bool aSetWindow);
   void UpdateWindowVisibility(bool aVisible);
   void UpdateDocumentActiveState(bool aIsActive);
-#endif // XP_MACOSX
+#endif // MOZ_WIDGET_COCOA
 
   void SetFrame(nsObjectFrame *aFrame);
   nsObjectFrame* GetFrame();
@@ -250,7 +250,7 @@ public:
     return mPluginWindow->type == NPWindowTypeDrawable &&
     (MatchPluginName("Shockwave Flash") ||
      MatchPluginName("Test Plug-in"));
-#elif defined(MOZ_X11) || defined(XP_MACOSX)
+#elif defined(MOZ_X11) || defined(MOZ_WIDGET_COCOA)
     return true;
 #else
     return false;
@@ -328,7 +328,7 @@ private:
   nsCOMPtr<nsIWidget>         mWidget;
   nsRefPtr<nsPluginHost>      mPluginHost;
   
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   NP_CGContext                              mCGPluginPortCopy;
   int32_t                                   mInCGPaintLevel;
   mozilla::RefPtr<MacIOSurface>             mIOSurface;
@@ -345,7 +345,7 @@ private:
   uint32_t                    mLastEventloopNestingLevel;
   bool                        mContentFocused;
   bool                        mWidgetVisible;    // used on Mac to store our widget's visible state
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   bool                        mPluginPortChanged;
 #endif
 #ifdef MOZ_X11
@@ -360,7 +360,7 @@ private:
   char              **mCachedAttrParamNames;
   char              **mCachedAttrParamValues;
   
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   NPEventModel mEventModel;
   // This is a hack! UseAsyncRendering() can incorrectly return false
   // when we don't have an object frame (possible as of bug 90268).
