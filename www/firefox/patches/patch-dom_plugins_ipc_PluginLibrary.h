$NetBSD: patch-dom_plugins_ipc_PluginLibrary.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginLibrary.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginLibrary.h
@@ -45,7 +45,7 @@ public:
 
   virtual bool HasRequiredFunctions() = 0;
 
-#if defined(XP_UNIX) && !defined(XP_MACOSX) && !defined(MOZ_WIDGET_GONK)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA) && !defined(MOZ_WIDGET_GONK)
   virtual nsresult NP_Initialize(NPNetscapeFuncs* bFuncs, NPPluginFuncs* pFuncs, NPError* error) = 0;
 #else
   virtual nsresult NP_Initialize(NPNetscapeFuncs* bFuncs, NPError* error) = 0;
@@ -54,7 +54,7 @@ public:
   virtual nsresult NP_GetMIMEDescription(const char** mimeDesc) = 0;
   virtual nsresult NP_GetValue(void *future, NPPVariable aVariable,
                                void *aValue, NPError* error) = 0;
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
   virtual nsresult NP_GetEntryPoints(NPPluginFuncs* pFuncs, NPError* error) = 0;
 #endif
   virtual nsresult NPP_New(NPMIMEType pluginType, NPP instance,
@@ -70,7 +70,7 @@ public:
   virtual nsresult GetImageContainer(NPP instance, mozilla::layers::ImageContainer** aContainer) = 0;
   virtual nsresult GetImageSize(NPP instance, nsIntSize* aSize) = 0;
   virtual bool IsOOP() = 0;
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   virtual nsresult IsRemoteDrawingCoreAnimation(NPP instance, bool *aDrawing) = 0;
   virtual nsresult ContentsScaleFactorChanged(NPP instance, double aContentsScaleFactor) = 0;
 #endif
