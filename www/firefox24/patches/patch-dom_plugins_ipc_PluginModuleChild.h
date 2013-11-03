$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.h.orig	2013-05-11 19:19:27.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -325,7 +325,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
