$NetBSD: patch-dom_plugins_base_nsNPAPIPluginInstance.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/nsNPAPIPluginInstance.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/nsNPAPIPluginInstance.h
@@ -41,7 +41,7 @@ class nsPluginInstanceOwner;
 const NPDrawingModel kDefaultDrawingModel = NPDrawingModelSyncWin;
 #elif defined(MOZ_X11)
 const NPDrawingModel kDefaultDrawingModel = NPDrawingModelSyncX;
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #ifndef NP_NO_QUICKDRAW
 const NPDrawingModel kDefaultDrawingModel = NPDrawingModelQuickDraw; // Not supported
 #else
@@ -133,7 +133,7 @@ public:
 
   void SetDrawingModel(NPDrawingModel aModel);
   void RedrawPlugin();
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   void SetEventModel(NPEventModel aModel);
 #endif
 
