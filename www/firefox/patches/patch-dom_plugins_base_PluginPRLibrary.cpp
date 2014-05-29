$NetBSD: patch-dom_plugins_base_PluginPRLibrary.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/PluginPRLibrary.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/PluginPRLibrary.cpp
@@ -63,7 +63,7 @@ PluginPRLibrary::NP_Initialize(NPNetscap
 {
   return NS_OK;
 }
-#elif defined(XP_UNIX) && !defined(XP_MACOSX)
+#elif defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
 nsresult
 PluginPRLibrary::NP_Initialize(NPNetscapeFuncs* bFuncs,
                                NPPluginFuncs* pFuncs, NPError* error)
@@ -149,7 +149,7 @@ nsresult
 PluginPRLibrary::NP_GetValue(void *future, NPPVariable aVariable,
 			     void *aValue, NPError* error)
 {
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
   if (mNP_GetValue) {
     *error = mNP_GetValue(future, aVariable, aValue);
   } else {
@@ -164,7 +164,7 @@ PluginPRLibrary::NP_GetValue(void *futur
 #endif
 }
 
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
 nsresult
 PluginPRLibrary::NP_GetEntryPoints(NPPluginFuncs* pFuncs, NPError* error)
 {
@@ -265,7 +265,7 @@ PluginPRLibrary::GetImageContainer(NPP i
   return NS_ERROR_NOT_IMPLEMENTED;
 }
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 nsresult
 PluginPRLibrary::IsRemoteDrawingCoreAnimation(NPP instance, bool *aDrawing)
 {
