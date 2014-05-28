$NetBSD: patch-dom_plugins_base_npapi.h,v 1.1 2014/05/28 10:08:18 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/npapi.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/npapi.h
@@ -43,7 +43,7 @@
 #define NP_NO_CARBON
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include <ApplicationServices/ApplicationServices.h>
 #include <OpenGL/OpenGL.h>
 #ifndef NP_NO_CARBON
@@ -128,7 +128,7 @@ typedef char*         NPMIMEType;
 /*----------------------------------------------------------------------*/
 
 #if !defined(__LP64__)
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #pragma options align=mac68k
 #endif
 #endif /* __LP64__ */
@@ -269,7 +269,7 @@ typedef struct
 #endif /* XP_UNIX */
 
 typedef enum {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #ifndef NP_NO_QUICKDRAW
   NPDrawingModelQuickDraw = 0,
 #endif
@@ -290,7 +290,7 @@ typedef enum {
 #endif
 } NPDrawingModel;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 typedef enum {
 #ifndef NP_NO_CARBON
   NPEventModelCarbon = 0,
@@ -379,7 +379,7 @@ typedef enum {
 
   /* Used for negotiating drawing models */
   NPPVpluginDrawingModel = 1000
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   /* Used for negotiating event models */
   , NPPVpluginEventModel = 1001
   /* In the NPDrawingModelCoreAnimation drawing model, the browser asks the plug-in for a Core Animation layer. */
@@ -420,7 +420,7 @@ typedef enum {
   NPNVdocumentOrigin = 22,
 
   NPNVpluginDrawingModel = 1000 /* Get the current drawing model (NPDrawingModel) */
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   , NPNVcontentsScaleFactor = 1001
 #ifndef NP_NO_QUICKDRAW
   , NPNVsupportsQuickDrawBool = 2000
@@ -434,7 +434,7 @@ typedef enum {
 #if defined(XP_WIN)
   , NPNVsupportsAsyncWindowsDXGISurfaceBool = 2008
 #endif
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #ifndef NP_NO_CARBON
   , NPNVsupportsCarbonBool = 3000 /* TRUE if the browser supports the Carbon event model */
 #endif
@@ -478,7 +478,7 @@ typedef struct _NPWindow
   uint32_t width;  /* Maximum window size */
   uint32_t height;
   NPRect   clipRect; /* Clipping rectangle in port coordinates */
-#if (defined(XP_UNIX) || defined(XP_SYMBIAN)) && !defined(XP_MACOSX)
+#if (defined(XP_UNIX) || defined(XP_SYMBIAN)) && !defined(MOZ_WIDGET_COCOA)
   void * ws_info; /* Platform-dependent additional data */
 #endif /* XP_UNIX */
   NPWindowType type; /* Is this a window or a drawable? */
@@ -524,7 +524,7 @@ typedef struct _NPPrint
   } print;
 } NPPrint;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #ifndef NP_NO_CARBON
 typedef EventRecord NPEvent;
 #endif
@@ -550,7 +550,7 @@ typedef XEvent NPEvent;
 typedef void*  NPEvent;
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 typedef void* NPRegion;
 #ifndef NP_NO_QUICKDRAW
 typedef RgnHandle NPQDRegion;
@@ -570,7 +570,7 @@ typedef struct _NPNSString NPNSString;
 typedef struct _NPNSWindow NPNSWindow;
 typedef struct _NPNSMenu   NPNSMenu;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 typedef NPNSMenu NPMenu;
 #else
 typedef void *NPMenu;
@@ -584,7 +584,7 @@ typedef enum {
   NPCoordinateSpaceFlippedScreen
 } NPCoordinateSpace;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 
 #ifndef NP_NO_QUICKDRAW
 typedef struct NP_Port
@@ -688,7 +688,7 @@ enum NPEventType {
 };
 #endif /* NP_NO_CARBON */
 
-#endif /* XP_MACOSX */
+#endif /* MOZ_WIDGET_COCOA */
 
 /*
  * Values for mode passed to NPP_New:
@@ -713,7 +713,7 @@ enum NPEventType {
 #define NP_CLEAR_CACHE (1 << 0)
 
 #if !defined(__LP64__)
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #pragma options align=reset
 #endif
 #endif /* __LP64__ */
