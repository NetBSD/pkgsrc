$NetBSD: patch-dom_plugins_base_nsPluginInstanceOwner.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/nsPluginInstanceOwner.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/nsPluginInstanceOwner.cpp
@@ -75,7 +75,7 @@ static NS_DEFINE_CID(kAppShellCID, NS_AP
 #include <winuser.h>
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include <Carbon/Carbon.h>
 #include "nsPluginUtilsOSX.h"
 #endif
@@ -232,7 +232,7 @@ nsPluginInstanceOwner::EndUpdateBackgrou
 bool
 nsPluginInstanceOwner::UseAsyncRendering()
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (mUseAsyncRendering) {
     return true;
   }
@@ -241,13 +241,13 @@ nsPluginInstanceOwner::UseAsyncRendering
   bool isOOP;
   bool result = (mInstance &&
           NS_SUCCEEDED(mInstance->GetIsOOP(&isOOP)) && isOOP
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
           && (!mPluginWindow ||
            mPluginWindow->type == NPWindowTypeDrawable)
 #endif
           );
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (result) {
     mUseAsyncRendering = true;
   }
@@ -280,7 +280,7 @@ nsPluginInstanceOwner::nsPluginInstanceO
   mObjectFrame = nullptr;
   mContent = nullptr;
   mWidgetCreationComplete = false;
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   memset(&mCGPluginPortCopy, 0, sizeof(NP_CGContext));
   mInCGPaintLevel = 0;
   mSentInitialTopLevelWindowEvent = false;
@@ -297,7 +297,7 @@ nsPluginInstanceOwner::nsPluginInstanceO
   mCachedAttrParamValues = nullptr;
   mLastMouseDownButtonType = -1;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #ifndef NP_NO_CARBON
   // We don't support Carbon, but it is still the default model for i386 NPAPI.
   mEventModel = NPEventModelCarbon;
@@ -601,7 +601,7 @@ NS_IMETHODIMP nsPluginInstanceOwner::Inv
   if (!mObjectFrame || !invalidRect || !mWidgetVisible)
     return NS_ERROR_FAILURE;
 
-#if defined(XP_MACOSX) || defined(MOZ_WIDGET_ANDROID)
+#if defined(MOZ_WIDGET_COCOA) || defined(MOZ_WIDGET_ANDROID)
   // Each time an asynchronously-drawing plugin sends a new surface to display,
   // the image in the ImageContainer is updated and InvalidateRect is called.
   // There are different side effects for (sync) Android plugins.
@@ -609,7 +609,7 @@ NS_IMETHODIMP nsPluginInstanceOwner::Inv
   mInstance->GetImageContainer(getter_AddRefs(container));
 #endif
 
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
   // Windowed plugins should not be calling NPN_InvalidateRect, but
   // Silverlight does and expects it to "work"
   if (mWidget) {
@@ -728,7 +728,7 @@ NS_IMETHODIMP nsPluginInstanceOwner::Get
 
 NS_IMETHODIMP nsPluginInstanceOwner::SetEventModel(int32_t eventModel)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   mEventModel = static_cast<NPEventModel>(eventModel);
   return NS_OK;
 #else
@@ -741,7 +741,7 @@ NPError nsPluginInstanceOwner::ShowNativ
   if (!menu || !event)
     return NPERR_GENERIC_ERROR;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (GetEventModel() != NPEventModelCocoa)
     return NPERR_INCOMPATIBLE_VERSION_ERROR;
 
@@ -755,7 +755,7 @@ NPError nsPluginInstanceOwner::ShowNativ
 NPBool nsPluginInstanceOwner::ConvertPoint(double sourceX, double sourceY, NPCoordinateSpace sourceSpace,
                                            double *destX, double *destY, NPCoordinateSpace destSpace)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (!mWidget)
     return false;
 
@@ -1122,7 +1122,7 @@ nsresult nsPluginInstanceOwner::EnsureCa
   return NS_OK;
 }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 
 static void InitializeNPCocoaEvent(NPCocoaEvent* event)
 {
@@ -1384,7 +1384,7 @@ nsPluginInstanceOwner::GetEventloopNesti
   uint32_t currentLevel = 0;
   if (appShell) {
     appShell->GetEventloopNestingLevel(&currentLevel);
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Cocoa widget code doesn't process UI events through the normal
     // appshell event loop, so it needs an additional count here.
     currentLevel++;
@@ -1598,7 +1598,7 @@ nsresult nsPluginInstanceOwner::Dispatch
   }
 #endif
 
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
   if (!mPluginWindow || (mPluginWindow->type == NPWindowTypeWindow)) {
     // continue only for cases without child window
     return aFocusEvent->PreventDefault(); // consume event
@@ -1622,7 +1622,7 @@ nsresult nsPluginInstanceOwner::Dispatch
 
 nsresult nsPluginInstanceOwner::ProcessKeyPress(nsIDOMEvent* aKeyEvent)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   return DispatchKeyToPlugin(aKeyEvent);
 #else
   if (SendNativeEvents())
@@ -1640,7 +1640,7 @@ nsresult nsPluginInstanceOwner::ProcessK
 
 nsresult nsPluginInstanceOwner::DispatchKeyToPlugin(nsIDOMEvent* aKeyEvent)
 {
-#if !defined(XP_MACOSX)
+#if !defined(MOZ_WIDGET_COCOA)
   if (!mPluginWindow || (mPluginWindow->type == NPWindowTypeWindow))
     return aKeyEvent->PreventDefault(); // consume event
   // continue only for cases without child window
@@ -1664,7 +1664,7 @@ nsresult nsPluginInstanceOwner::Dispatch
 nsresult
 nsPluginInstanceOwner::ProcessMouseDown(nsIDOMEvent* aMouseEvent)
 {
-#if !defined(XP_MACOSX)
+#if !defined(MOZ_WIDGET_COCOA)
   if (!mPluginWindow || (mPluginWindow->type == NPWindowTypeWindow))
     return aMouseEvent->PreventDefault(); // consume event
   // continue only for cases without child window
@@ -1697,7 +1697,7 @@ nsPluginInstanceOwner::ProcessMouseDown(
 
 nsresult nsPluginInstanceOwner::DispatchMouseToPlugin(nsIDOMEvent* aMouseEvent)
 {
-#if !defined(XP_MACOSX)
+#if !defined(MOZ_WIDGET_COCOA)
   if (!mPluginWindow || (mPluginWindow->type == NPWindowTypeWindow))
     return aMouseEvent->PreventDefault(); // consume event
   // continue only for cases without child window
@@ -1802,7 +1802,7 @@ nsEventStatus nsPluginInstanceOwner::Pro
   if (!mInstance || !mObjectFrame)   // if mInstance is null, we shouldn't be here
     return nsEventStatus_eIgnore;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (!mWidget)
     return nsEventStatus_eIgnore;
 
@@ -2338,7 +2338,7 @@ nsPluginInstanceOwner::Destroy()
 {
   SetFrame(nullptr);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   RemoveFromCARefreshTimer();
   if (mColorProfile)
     ::CGColorSpaceRelease(mColorProfile);
@@ -2394,7 +2394,7 @@ nsPluginInstanceOwner::Destroy()
 
 // Paints are handled differently, so we just simulate an update event.
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 void nsPluginInstanceOwner::Paint(const gfxRect& aDirtyRect, CGContextRef cgContext)
 {
   if (!mInstance || !mObjectFrame)
@@ -2813,7 +2813,7 @@ void* nsPluginInstanceOwner::GetPluginPo
       result = mWidget->GetNativeData(NS_NATIVE_GRAPHIC);
     else
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (GetDrawingModel() == NPDrawingModelCoreGraphics || 
         GetDrawingModel() == NPDrawingModelCoreAnimation ||
         GetDrawingModel() == NPDrawingModelInvalidatingCoreAnimation)
@@ -2881,7 +2881,7 @@ NS_IMETHODIMP nsPluginInstanceOwner::Cre
     mWidget->Show(false);
     mWidget->Enable(false);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Now that we have a widget we want to set the event model before
     // any events are processed.
     nsCOMPtr<nsIPluginWidget> pluginWidget = do_QueryInterface(mWidget);
@@ -2942,7 +2942,7 @@ NS_IMETHODIMP nsPluginInstanceOwner::Cre
 }
 
 // Mac specific code to fix up the port location and clipping region
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 
 void* nsPluginInstanceOwner::FixUpPluginWindow(int32_t inPaintState)
 {
@@ -3062,7 +3062,7 @@ nsPluginInstanceOwner::HidePluginWindow(
   }
 }
 
-#else // XP_MACOSX
+#else // MOZ_WIDGET_COCOA
 
 void nsPluginInstanceOwner::UpdateWindowPositionAndClipRect(bool aSetWindow)
 {
@@ -3137,7 +3137,7 @@ nsPluginInstanceOwner::UpdateDocumentAct
   }
 #endif
 }
-#endif // XP_MACOSX
+#endif // MOZ_WIDGET_COCOA
 
 NS_IMETHODIMP
 nsPluginInstanceOwner::CallSetWindow()
@@ -3163,7 +3163,7 @@ nsPluginInstanceOwner::GetContentsScaleF
   // On Mac, device pixels need to be translated to (and from) "display pixels"
   // for plugins. On other platforms, plugin coordinates are always in device
   // pixels.
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   nsIPresShell* presShell = nsContentUtils::FindPresShellForDocument(mContent->OwnerDoc());
   if (presShell) {
     scaleFactor = double(nsPresContext::AppUnitsPerCSSPixel())/
