$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.h,v 1.8 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.h.orig	2013-08-04 03:05:22.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.h
@@ -328,7 +328,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
