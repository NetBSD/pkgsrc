$NetBSD: patch-dom_plugins_base_nsNPAPIPluginInstance.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/nsNPAPIPluginInstance.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/nsNPAPIPluginInstance.cpp
@@ -807,7 +807,7 @@ void nsNPAPIPluginInstance::RedrawPlugin
   mOwner->RedrawPlugin();
 }
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 void nsNPAPIPluginInstance::SetEventModel(NPEventModel aModel)
 {
   // the event model needs to be set for the object frame immediately
@@ -1092,7 +1092,7 @@ nsNPAPIPluginInstance* nsNPAPIPluginInst
 
 nsresult nsNPAPIPluginInstance::GetDrawingModel(int32_t* aModel)
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   *aModel = (int32_t)mDrawingModel;
   return NS_OK;
 #else
@@ -1102,7 +1102,7 @@ nsresult nsNPAPIPluginInstance::GetDrawi
 
 nsresult nsNPAPIPluginInstance::IsRemoteDrawingCoreAnimation(bool* aDrawing)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (!mPlugin)
       return NS_ERROR_FAILURE;
 
@@ -1118,7 +1118,7 @@ nsresult nsNPAPIPluginInstance::IsRemote
 
 nsresult nsNPAPIPluginInstance::ContentsScaleFactorChanged(double aContentsScaleFactor)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (!mPlugin)
       return NS_ERROR_FAILURE;
 
