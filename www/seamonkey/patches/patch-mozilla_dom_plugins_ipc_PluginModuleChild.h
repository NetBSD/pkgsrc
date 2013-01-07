$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.h,v 1.6 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.h.orig	2012-11-18 10:19:34.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.h
@@ -320,7 +320,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
