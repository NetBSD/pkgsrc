$NetBSD: patch-dom_plugins_ipc_PluginInstanceChild.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginInstanceChild.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginInstanceChild.cpp
@@ -84,11 +84,11 @@ const int kFlashWMUSERMessageThrottleDel
 
 static const TCHAR kPluginIgnoreSubclassProperty[] = TEXT("PluginIgnoreSubclassProperty");
 
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include <ApplicationServices/ApplicationServices.h>
 #include "nsCocoaFeatures.h"
 #include "PluginUtilsOSX.h"
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
 
 template<>
 struct RunnableMethodTraits<PluginInstanceChild>
@@ -99,7 +99,7 @@ struct RunnableMethodTraits<PluginInstan
 
 PluginInstanceChild::PluginInstanceChild(const NPPluginFuncs* aPluginIface)
     : mPluginIface(aPluginIface)
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     , mContentsScaleFactor(1.0)
 #endif
     , mDrawingModel(kDefaultDrawingModel)
@@ -149,7 +149,7 @@ PluginInstanceChild::PluginInstanceChild
     mWindow.type = NPWindowTypeWindow;
     mData.ndata = (void*) this;
     mData.pdata = nullptr;
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     mWindow.ws_info = &mWsInfo;
     memset(&mWsInfo, 0, sizeof(mWsInfo));
 #if (MOZ_WIDGET_GTK == 2)
@@ -158,7 +158,7 @@ PluginInstanceChild::PluginInstanceChild
 #else
     mWsInfo.display = DefaultXDisplay();
 #endif
-#endif // MOZ_X11 && XP_UNIX && !XP_MACOSX
+#endif // MOZ_X11 && XP_UNIX && !MOZ_WIDGET_COCOA
 #if defined(OS_WIN)
     memset(&mAlphaExtract, 0, sizeof(mAlphaExtract));
 #endif // OS_WIN
@@ -378,7 +378,7 @@ PluginInstanceChild::NPN_GetValue(NPNVar
     }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
    case NPNVsupportsCoreGraphicsBool: {
         *((NPBool*)aValue) = true;
         return NPERR_NO_ERROR;
@@ -427,7 +427,7 @@ PluginInstanceChild::NPN_GetValue(NPNVar
         *static_cast<double*>(aValue) = mContentsScaleFactor;
         return NPERR_NO_ERROR;
     }
-#endif /* XP_MACOSX */
+#endif /* MOZ_WIDGET_COCOA */
 
 #ifdef DEBUG
     case NPNVjavascriptEnabledBool:
@@ -541,7 +541,7 @@ PluginInstanceChild::NPN_SetValue(NPPVar
         }
         mDrawingModel = drawingModel;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         if (drawingModel == NPDrawingModelCoreAnimation) {
             mCARefreshTimer = ScheduleTimer(DEFAULT_REFRESH_MS, true, CAUpdate);
         }
@@ -553,7 +553,7 @@ PluginInstanceChild::NPN_SetValue(NPPVar
         return rv;
     }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     case NPPVpluginEventModel: {
         NPError rv;
         int eventModel = (int16_t) (intptr_t) aValue;
@@ -723,7 +723,7 @@ PluginInstanceChild::AnswerNPP_HandleEve
                           event.event.xgraphicsexpose.drawable));
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Mac OS X does not define an NPEvent structure. It defines more specific types.
     NPCocoaEvent evcopy = event.event;
     // event.contentsScaleFactor <= 0 is a signal we shouldn't use it,
@@ -775,7 +775,7 @@ PluginInstanceChild::AnswerNPP_HandleEve
     else
         *handled = mPluginIface->event(&mData, reinterpret_cast<void*>(&evcopy));
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Release any reference counted objects created in the child process.
     if (evcopy.type == NPCocoaEventKeyDown ||
         evcopy.type == NPCocoaEventKeyUp) {
@@ -803,7 +803,7 @@ PluginInstanceChild::AnswerNPP_HandleEve
     return true;
 }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 
 bool
 PluginInstanceChild::AnswerNPP_HandleEvent_Shmem(const NPRemoteEvent& event,
@@ -881,7 +881,7 @@ PluginInstanceChild::AnswerNPP_HandleEve
 }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 
 void CallCGDraw(CGContextRef ref, void* aPluginInstance, nsIntRect aUpdateRect) {
   PluginInstanceChild* pluginInstance = (PluginInstanceChild*)aPluginInstance;
@@ -1001,7 +1001,7 @@ PluginInstanceChild::RecvWindowPosChange
 bool
 PluginInstanceChild::RecvContentsScaleFactorChanged(const double& aContentsScaleFactor)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     mContentsScaleFactor = aContentsScaleFactor;
     if (mShContext) {
         // Release the shared context so that it is reallocated
@@ -1016,7 +1016,7 @@ PluginInstanceChild::RecvContentsScaleFa
 #endif
 }
 
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
 // Create a new window from NPWindow
 bool PluginInstanceChild::CreateWindow(const NPRemoteWindow& aWindow)
 { 
@@ -1080,7 +1080,7 @@ PluginInstanceChild::AnswerNPP_SetWindow
                  "Shouldn't be receiving NPP_SetWindow with layer rendering");
     AssertPluginThread();
 
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     NS_ASSERTION(mWsInfo.display, "We should have a valid display!");
 
     // The minimum info is sent over IPC to allow this
@@ -1202,7 +1202,7 @@ PluginInstanceChild::AnswerNPP_SetWindow
       break;
     }
 
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 
     mWindow.x = aWindow.x;
     mWindow.y = aWindow.y;
@@ -2741,7 +2741,7 @@ PluginInstanceChild::DoAsyncSetWindow(co
     mWindow.height = aWindow.height;
     mWindow.clipRect = aWindow.clipRect;
     mWindow.type = aWindow.type;
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     mContentsScaleFactor = aWindow.contentsScaleFactor;
 #endif
 
@@ -2901,7 +2901,7 @@ PluginInstanceChild::MaybeCreatePlatform
 bool
 PluginInstanceChild::EnsureCurrentBuffer(void)
 {
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
     nsIntRect toInvalidate(0, 0, 0, 0);
     gfxIntSize winSize = gfxIntSize(mWindow.width, mWindow.height);
 
@@ -2947,7 +2947,7 @@ PluginInstanceChild::EnsureCurrentBuffer
     }
 
     return true;
-#else // XP_MACOSX
+#else // MOZ_WIDGET_COCOA
 
     if (!mDoubleBufferCARenderer.HasCALayer()) {
         void *caLayer = nullptr;
@@ -3044,7 +3044,7 @@ PluginInstanceChild::UpdateWindowAttribu
         return;
     }
 
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
     // Adjusting the window isn't needed for OSX
 #ifndef XP_WIN
     // On Windows, we translate the device context, in order for the window
@@ -3066,7 +3066,7 @@ PluginInstanceChild::UpdateWindowAttribu
         mWindow.clipRect.right = clipRect.XMost();
         mWindow.clipRect.bottom = clipRect.YMost();
     }
-#endif // XP_MACOSX
+#endif // MOZ_WIDGET_COCOA
 
 #ifdef XP_WIN
     // Windowless plugins on Windows need a WM_WINDOWPOSCHANGED event to update
@@ -3995,7 +3995,7 @@ PluginInstanceChild::AnswerNPP_Destroy(N
       xt_client_xloop_destroy();
     }
 #endif
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     DeleteWindow();
 #endif
 
