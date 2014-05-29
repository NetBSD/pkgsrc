$NetBSD: patch-dom_plugins_ipc_PluginMessageUtils.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginMessageUtils.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginMessageUtils.cpp
@@ -50,14 +50,14 @@ namespace plugins {
 
 NPRemoteWindow::NPRemoteWindow() :
   window(0), x(0), y(0), width(0), height(0), type(NPWindowTypeDrawable)
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
   , visualID(0)
   , colormap(0)
 #endif /* XP_UNIX */
 #if defined(XP_WIN)
   ,surfaceHandle(0)
 #endif
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   ,contentsScaleFactor(1.0)
 #endif
 {
