$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.h,v 1.4 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.h.orig	2012-08-27 04:49:08.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.h
@@ -330,7 +330,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
