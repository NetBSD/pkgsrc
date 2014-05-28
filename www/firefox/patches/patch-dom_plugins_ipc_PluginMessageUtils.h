$NetBSD: patch-dom_plugins_ipc_PluginMessageUtils.h,v 1.1 2014/05/28 10:08:18 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginMessageUtils.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginMessageUtils.h
@@ -25,7 +25,7 @@
 #ifdef MOZ_CRASHREPORTER
 #  include "nsExceptionHandler.h"
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "PluginInterposeOSX.h"
 #else
 namespace mac_plugin_interposing { class NSCursorInfo { }; }
@@ -99,14 +99,14 @@ struct NPRemoteWindow
   uint32_t height;
   NPRect clipRect;
   NPWindowType type;
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX)
   VisualID visualID;
   Colormap colormap;
 #endif /* XP_UNIX */
 #if defined(XP_WIN)
   base::SharedMemoryHandle surfaceHandle;
 #endif
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   double contentsScaleFactor;
 #endif
 };
@@ -115,7 +115,7 @@ struct NPRemoteWindow
 typedef HWND NativeWindowHandle;
 #elif defined(MOZ_X11)
 typedef XID NativeWindowHandle;
-#elif defined(XP_MACOSX) || defined(ANDROID) || defined(MOZ_WIDGET_QT)
+#elif defined(MOZ_WIDGET_COCOA) || defined(ANDROID) || defined(MOZ_WIDGET_QT)
 typedef intptr_t NativeWindowHandle; // never actually used, will always be 0
 #else
 #error Need NativeWindowHandle for this platform
@@ -160,7 +160,7 @@ NPPVariableToString(NPPVariable aVar)
   
         VARSTR(NPPVpluginWantsAllNetworkStreams);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         VARSTR(NPPVpluginDrawingModel);
         VARSTR(NPPVpluginEventModel);
 #endif
@@ -377,14 +377,14 @@ struct ParamTraits<mozilla::plugins::NPR
     WriteParam(aMsg, aParam.height);
     WriteParam(aMsg, aParam.clipRect);
     WriteParam(aMsg, aParam.type);
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX)
     aMsg->WriteULong(aParam.visualID);
     aMsg->WriteULong(aParam.colormap);
 #endif
 #if defined(XP_WIN)
     WriteParam(aMsg, aParam.surfaceHandle);
 #endif
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     aMsg->WriteDouble(aParam.contentsScaleFactor);
 #endif
   }
@@ -405,7 +405,7 @@ struct ParamTraits<mozilla::plugins::NPR
           ReadParam(aMsg, aIter, &type)))
       return false;
 
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX)
     unsigned long visualID;
     unsigned long colormap;
     if (!(aMsg->ReadULong(aIter, &visualID) &&
@@ -419,7 +419,7 @@ struct ParamTraits<mozilla::plugins::NPR
       return false;
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     double contentsScaleFactor;
     if (!aMsg->ReadDouble(aIter, &contentsScaleFactor))
       return false;
@@ -432,14 +432,14 @@ struct ParamTraits<mozilla::plugins::NPR
     aResult->height = height;
     aResult->clipRect = clipRect;
     aResult->type = type;
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX)
     aResult->visualID = visualID;
     aResult->colormap = colormap;
 #endif
 #if defined(XP_WIN)
     aResult->surfaceHandle = surfaceHandle;
 #endif
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     aResult->contentsScaleFactor = contentsScaleFactor;
 #endif
     return true;
@@ -492,7 +492,7 @@ struct ParamTraits<NPString>
   }
 };
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 template <>
 struct ParamTraits<NPNSString*>
 {
@@ -563,7 +563,7 @@ struct ParamTraits<NPNSString*>
 };
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 template <>
 struct ParamTraits<NSCursorInfo>
 {
@@ -655,7 +655,7 @@ struct ParamTraits<NSCursorInfo>
     return false;
   }
 };
-#endif // #ifdef XP_MACOSX
+#endif // #ifdef MOZ_WIDGET_COCOA
 
 template <>
 struct ParamTraits<NPVariant>
@@ -900,7 +900,7 @@ struct ParamTraits<NPCoordinateSpace>
 // 
 // NB: these guards are based on those where struct NPEvent is defined
 // in npapi.h.  They should be kept in sync.
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #  include "mozilla/plugins/NPEventOSX.h"
 #elif defined(XP_WIN)
 #  include "mozilla/plugins/NPEventWindows.h"
