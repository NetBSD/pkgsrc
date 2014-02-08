$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.h,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.h.orig	2014-01-28 04:03:39.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -328,7 +328,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
