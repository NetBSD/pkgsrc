$NetBSD: patch-dom_plugins_base_npfunctions.h,v 1.1 2014/05/28 10:08:18 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/npfunctions.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/npfunctions.h
@@ -191,7 +191,7 @@ typedef struct _NPNetscapeFuncs {
   NPN_SetCurrentAsyncSurfacePtr setcurrentasyncsurface;
 } NPNetscapeFuncs;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 /*
  * Mac OS X version(s) of NP_GetMIMEDescription(const char *)
  * These can be called to retreive MIME information from the plugin dynamically
@@ -281,7 +281,7 @@ typedef char*          (*NP_GetPluginVer
 NP_EXPORT(char*)       NP_GetPluginVersion(void);
 typedef const char*    (*NP_GetMIMEDescriptionFunc)(void);
 NP_EXPORT(const char*) NP_GetMIMEDescription(void);
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 typedef NPError        (*NP_InitializeFunc)(NPNetscapeFuncs*);
 NP_EXPORT(NPError)     NP_Initialize(NPNetscapeFuncs* bFuncs);
 typedef NPError        (*NP_GetEntryPointsFunc)(NPPluginFuncs*);
