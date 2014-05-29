$NetBSD: patch-dom_plugins_ipc_PluginInstanceParent.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginInstanceParent.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginInstanceParent.cpp
@@ -32,7 +32,7 @@
 #include "GLContext.h"
 #include "GLContextProvider.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "MacIOSurfaceImage.h"
 #endif
 
@@ -48,9 +48,9 @@ UINT gOOPPPluginFocusEvent =
 extern const wchar_t* kFlashFullscreenClass;
 #elif defined(MOZ_WIDGET_GTK)
 #include <gdk/gdk.h>
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include <ApplicationServices/ApplicationServices.h>
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
 
 using namespace mozilla::plugins;
 using namespace mozilla::layers;
@@ -78,7 +78,7 @@ PluginInstanceParent::PluginInstancePare
     , mPluginWndProc(nullptr)
     , mNestedEventState(false)
 #endif // defined(XP_WIN)
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     , mShWidth(0)
     , mShHeight(0)
     , mShColorSpace(nullptr)
@@ -202,7 +202,7 @@ PluginInstanceParent::AnswerNPN_GetValue
     HWND id;
 #elif defined(MOZ_X11)
     XID id;
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     intptr_t id;
 #elif defined(ANDROID)
     // TODO: Need Android impl
@@ -357,7 +357,7 @@ PluginInstanceParent::AnswerNPN_SetValue
 {
     *shmem = null_t();
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (drawingModel == NPDrawingModelCoreAnimation ||
         drawingModel == NPDrawingModelInvalidatingCoreAnimation) {
         // We need to request CoreGraphics otherwise
@@ -411,7 +411,7 @@ PluginInstanceParent::AnswerNPN_SetValue
     } else if (
 #if defined(XP_WIN)
                drawingModel == NPDrawingModelSyncWin
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
                drawingModel == NPDrawingModelOpenGL ||
                drawingModel == NPDrawingModelCoreGraphics
 #elif defined(MOZ_X11)
@@ -444,7 +444,7 @@ bool
 PluginInstanceParent::AnswerNPN_SetValue_NPPVpluginEventModel(
     const int& eventModel, NPError* result)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     *result = mNPNIface->setvalue(mNPP, NPPVpluginEventModel,
                                   (void*)(intptr_t)eventModel);
     return true;
@@ -564,7 +564,7 @@ PluginInstanceParent::RecvShow(const NPR
         }
         surface = gfxSharedImageSurface::Open(newSurface.get_Shmem());
     }
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     else if (newSurface.type() == SurfaceDescriptor::TIOSurfaceDescriptor) {
         IOSurfaceDescriptor iodesc = newSurface.get_IOSurfaceDescriptor();
 
@@ -674,7 +674,7 @@ PluginInstanceParent::AsyncSetWindow(NPW
     window.height = aWindow->height;
     window.clipRect = aWindow->clipRect;
     window.type = aWindow->type;
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     double scaleFactor = 1.0;
     mNPNIface->getvalue(mNPP, NPNVcontentsScaleFactor, &scaleFactor);
     window.contentsScaleFactor = scaleFactor;
@@ -689,7 +689,7 @@ PluginInstanceParent::AsyncSetWindow(NPW
 nsresult
 PluginInstanceParent::GetImageContainer(ImageContainer** aContainer)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     MacIOSurface* ioSurface = nullptr;
   
     if (mFrontIOSurface) {
@@ -716,7 +716,7 @@ PluginInstanceParent::GetImageContainer(
       return NS_OK;
     }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (ioSurface) {
         nsRefPtr<Image> image = container->CreateImage(ImageFormat::MAC_IOSURFACE);
         if (!image) {
@@ -750,7 +750,7 @@ PluginInstanceParent::GetImageSize(nsInt
         return NS_OK;
     }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (mFrontIOSurface) {
         *aSize = nsIntSize(mFrontIOSurface->GetWidth(), mFrontIOSurface->GetHeight());
         return NS_OK;
@@ -763,7 +763,7 @@ PluginInstanceParent::GetImageSize(nsInt
     return NS_ERROR_NOT_AVAILABLE;
 }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 nsresult
 PluginInstanceParent::IsRemoteDrawingCoreAnimation(bool *aDrawing)
 {
@@ -778,7 +778,7 @@ PluginInstanceParent::ContentsScaleFacto
     bool rv = SendContentsScaleFactorChanged(aContentsScaleFactor);
     return rv ? NS_OK : NS_ERROR_FAILURE;
 }
-#endif // #ifdef XP_MACOSX
+#endif // #ifdef MOZ_WIDGET_COCOA
 
 nsresult
 PluginInstanceParent::SetBackgroundUnknown()
@@ -988,7 +988,7 @@ PluginInstanceParent::NPP_SetWindow(cons
     window.type = aWindow->type;
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     double floatScaleFactor = 1.0;
     mNPNIface->getvalue(mNPP, NPNVcontentsScaleFactor, &floatScaleFactor);
     int scaleFactor = ceil(floatScaleFactor);
@@ -1020,7 +1020,7 @@ PluginInstanceParent::NPP_SetWindow(cons
     }
 #endif
 
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     const NPSetWindowCallbackStruct* ws_info =
       static_cast<NPSetWindowCallbackStruct*>(aWindow->ws_info);
     window.visualID = ws_info->visual ? ws_info->visual->visualid : None;
@@ -1165,14 +1165,14 @@ PluginInstanceParent::NPP_HandleEvent(vo
 {
     PLUGIN_LOG_DEBUG_FUNCTION;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     NPCocoaEvent* npevent = reinterpret_cast<NPCocoaEvent*>(event);
 #else
     NPEvent* npevent = reinterpret_cast<NPEvent*>(event);
 #endif
     NPRemoteEvent npremoteevent;
     npremoteevent.event = *npevent;
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     double scaleFactor = 1.0;
     mNPNIface->getvalue(mNPP, NPNVcontentsScaleFactor, &scaleFactor);
     npremoteevent.contentsScaleFactor = scaleFactor;
@@ -1266,7 +1266,7 @@ PluginInstanceParent::NPP_HandleEvent(vo
     }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (npevent->type == NPCocoaEventDrawRect) {
         if (mDrawingModel == NPDrawingModelCoreAnimation ||
             mDrawingModel == NPDrawingModelInvalidatingCoreAnimation) {
