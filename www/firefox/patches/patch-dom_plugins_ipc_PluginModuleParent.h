$NetBSD: patch-dom_plugins_ipc_PluginModuleParent.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginModuleParent.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginModuleParent.h
@@ -251,7 +251,7 @@ private:
                                          gfxContext* aCtx,
                                          const nsIntRect& aRect) MOZ_OVERRIDE;
 
-#if defined(XP_UNIX) && !defined(XP_MACOSX) && !defined(MOZ_WIDGET_GONK)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA) && !defined(MOZ_WIDGET_GONK)
     virtual nsresult NP_Initialize(NPNetscapeFuncs* bFuncs, NPPluginFuncs* pFuncs, NPError* error);
 #else
     virtual nsresult NP_Initialize(NPNetscapeFuncs* bFuncs, NPError* error);
@@ -260,7 +260,7 @@ private:
     virtual nsresult NP_GetMIMEDescription(const char** mimeDesc);
     virtual nsresult NP_GetValue(void *future, NPPVariable aVariable,
                                  void *aValue, NPError* error);
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
     virtual nsresult NP_GetEntryPoints(NPPluginFuncs* pFuncs, NPError* error);
 #endif
     virtual nsresult NPP_New(NPMIMEType pluginType, NPP instance,
@@ -271,7 +271,7 @@ private:
                                        uint64_t maxAge);
     virtual nsresult NPP_GetSitesWithData(InfallibleTArray<nsCString>& result);
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     virtual nsresult IsRemoteDrawingCoreAnimation(NPP instance, bool *aDrawing);
     virtual nsresult ContentsScaleFactorChanged(NPP instance, double aContentsScaleFactor);
 #endif
