$NetBSD: patch-dom_plugins_ipc_PluginModuleParent.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginModuleParent.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginModuleParent.cpp
@@ -43,7 +43,7 @@
 
 #ifdef MOZ_WIDGET_GTK
 #include <glib.h>
-#elif XP_MACOSX
+#elif MOZ_WIDGET_COCOA
 #include "PluginInterposeOSX.h"
 #include "PluginUtilsOSX.h"
 #endif
@@ -1181,7 +1181,7 @@ PluginModuleParent::EndUpdateBackground(
     return i->EndUpdateBackground(aCtx, aRect);
 }
 
-#if defined(XP_UNIX) && !defined(XP_MACOSX) && !defined(MOZ_WIDGET_GONK)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA) && !defined(MOZ_WIDGET_GONK)
 nsresult
 PluginModuleParent::NP_Initialize(NPNetscapeFuncs* bFuncs, NPPluginFuncs* pFuncs, NPError* error)
 {
@@ -1298,7 +1298,7 @@ PluginModuleParent::NP_GetValue(void *fu
     return NS_OK;
 }
 
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(XP_OS2)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(XP_OS2)
 nsresult
 PluginModuleParent::NP_GetEntryPoints(NPPluginFuncs* pFuncs, NPError* error)
 {
@@ -1411,7 +1411,7 @@ PluginModuleParent::NPP_GetSitesWithData
     return NS_OK;
 }
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 nsresult
 PluginModuleParent::IsRemoteDrawingCoreAnimation(NPP instance, bool *aDrawing)
 {
@@ -1431,7 +1431,7 @@ PluginModuleParent::ContentsScaleFactorC
 
     return i->ContentsScaleFactorChanged(aContentsScaleFactor);
 }
-#endif // #if defined(XP_MACOSX)
+#endif // #if defined(MOZ_WIDGET_COCOA)
 
 bool
 PluginModuleParent::AnswerNPN_GetValue_WithBoolReturn(const NPNVariable& aVariable,
@@ -1457,7 +1457,7 @@ PluginModuleParent::AnswerProcessSomeEve
     return true;
 }
 
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 bool
 PluginModuleParent::AnswerProcessSomeEvents()
 {
@@ -1523,7 +1523,7 @@ PluginModuleParent::RecvPluginShowWindow
                                          const size_t& aWidth, const size_t& aHeight)
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     CGRect windowBound = ::CGRectMake(aX, aY, aWidth, aHeight);
     mac_plugin_interposing::parent::OnPluginShowWindow(aWindowId, windowBound, aModal);
     return true;
@@ -1538,7 +1538,7 @@ bool
 PluginModuleParent::RecvPluginHideWindow(const uint32_t& aWindowId)
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     mac_plugin_interposing::parent::OnPluginHideWindow(aWindowId, OtherSidePID());
     return true;
 #else
@@ -1578,7 +1578,7 @@ bool
 PluginModuleParent::RecvSetCursor(const NSCursorInfo& aCursorInfo)
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     mac_plugin_interposing::parent::OnSetCursor(aCursorInfo);
     return true;
 #else
@@ -1592,7 +1592,7 @@ bool
 PluginModuleParent::RecvShowCursor(const bool& aShow)
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     mac_plugin_interposing::parent::OnShowCursor(aShow);
     return true;
 #else
@@ -1606,7 +1606,7 @@ bool
 PluginModuleParent::RecvPushCursor(const NSCursorInfo& aCursorInfo)
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     mac_plugin_interposing::parent::OnPushCursor(aCursorInfo);
     return true;
 #else
@@ -1620,7 +1620,7 @@ bool
 PluginModuleParent::RecvPopCursor()
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     mac_plugin_interposing::parent::OnPopCursor();
     return true;
 #else
@@ -1634,7 +1634,7 @@ bool
 PluginModuleParent::RecvGetNativeCursorsSupported(bool* supported)
 {
     PLUGIN_LOG_DEBUG(("%s", FULLFUNCTION));
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     *supported =
       Preferences::GetBool("dom.ipc.plugins.nativeCursorSupport", false);
     return true;
