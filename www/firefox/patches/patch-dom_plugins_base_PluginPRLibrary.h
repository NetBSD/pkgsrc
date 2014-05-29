$NetBSD: patch-dom_plugins_base_PluginPRLibrary.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/PluginPRLibrary.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/PluginPRLibrary.h
@@ -17,17 +17,17 @@ class PluginPRLibrary : public PluginLib
 {
 public:
     PluginPRLibrary(const char* aFilePath, PRLibrary* aLibrary) :
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
         mNP_Initialize(nullptr),
 #else
         mNP_Initialize(nullptr),
 #endif
         mNP_Shutdown(nullptr),
         mNP_GetMIMEDescription(nullptr),
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
         mNP_GetValue(nullptr),
 #endif
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
         mNP_GetEntryPoints(nullptr),
 #endif
         mNPP_New(nullptr),
@@ -60,19 +60,19 @@ public:
 
         mNP_GetMIMEDescription = (NP_GetMIMEDescriptionFunc)
             PR_FindFunctionSymbol(mLibrary, "NP_GetMIMEDescription");
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
         if (!mNP_GetMIMEDescription)
             return false;
 #endif
 
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
         mNP_GetValue = (NP_GetValueFunc)
             PR_FindFunctionSymbol(mLibrary, "NP_GetValue");
         if (!mNP_GetValue)
             return false;
 #endif
 
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
         mNP_GetEntryPoints = (NP_GetEntryPointsFunc)
             PR_FindFunctionSymbol(mLibrary, "NP_GetEntryPoints");
         if (!mNP_GetEntryPoints)
@@ -81,7 +81,7 @@ public:
         return true;
     }
 
-#if defined(XP_UNIX) && !defined(XP_MACOSX) && !defined(MOZ_WIDGET_GONK)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA) && !defined(MOZ_WIDGET_GONK)
     virtual nsresult NP_Initialize(NPNetscapeFuncs* bFuncs,
                                    NPPluginFuncs* pFuncs, NPError* error);
 #else
@@ -95,7 +95,7 @@ public:
     virtual nsresult NP_GetValue(void *future, NPPVariable aVariable,
                                  void *aValue, NPError* error);
 
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
     virtual nsresult NP_GetEntryPoints(NPPluginFuncs* pFuncs, NPError* error);
 #endif
 
@@ -112,7 +112,7 @@ public:
     virtual nsresult GetImageContainer(NPP instance, mozilla::layers::ImageContainer** aContainer);
     virtual nsresult GetImageSize(NPP instance, nsIntSize* aSize);
     virtual bool IsOOP() MOZ_OVERRIDE { return false; }
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     virtual nsresult IsRemoteDrawingCoreAnimation(NPP instance, bool *aDrawing);
     virtual nsresult ContentsScaleFactorChanged(NPP instance, double aContentsScaleFactor);
 #endif
@@ -127,10 +127,10 @@ private:
     NP_InitializeFunc mNP_Initialize;
     NP_ShutdownFunc mNP_Shutdown;
     NP_GetMIMEDescriptionFunc mNP_GetMIMEDescription;
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     NP_GetValueFunc mNP_GetValue;
 #endif
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
     NP_GetEntryPointsFunc mNP_GetEntryPoints;
 #endif
     NPP_NewProcPtr mNPP_New;
