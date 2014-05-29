$NetBSD: patch-dom_plugins_ipc_PluginInstanceChild.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/ipc/PluginInstanceChild.h.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginInstanceChild.h
@@ -195,7 +195,7 @@ protected:
     virtual bool
     RecvNPP_DidComposite() MOZ_OVERRIDE;
 
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     bool CreateWindow(const NPRemoteWindow& aWindow);
     void DeleteWindow();
 #endif
@@ -361,7 +361,7 @@ private:
     const NPPluginFuncs* mPluginIface;
     NPP_t mData;
     NPWindow mWindow;
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     double mContentsScaleFactor;
 #endif
     int16_t               mDrawingModel;
@@ -383,7 +383,7 @@ private:
     PluginScriptableObjectChild* mCachedWindowActor;
     PluginScriptableObjectChild* mCachedElementActor;
 
-#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(MOZ_X11) && defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
     NPSetWindowCallbackStruct mWsInfo;
 #if (MOZ_WIDGET_GTK == 2)
     bool mXEmbed;
@@ -468,7 +468,7 @@ private:
     bool CanPaintOnBackground();
 
     bool IsVisible() {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         return mWindow.clipRect.top != mWindow.clipRect.bottom &&
                mWindow.clipRect.left != mWindow.clipRect.right;
 #else
@@ -553,7 +553,7 @@ private:
     // surface which is on ParentProcess side
     nsRefPtr<gfxASurface> mBackSurface;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Current IOSurface available for rendering
     // We can't use thebes gfxASurface like other platforms.
     PluginUtilsOSX::nsDoubleBufferCARenderer mDoubleBufferCARenderer; 
