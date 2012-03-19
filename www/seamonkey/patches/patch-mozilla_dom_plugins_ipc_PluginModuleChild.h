$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.h,v 1.2 2012/03/19 10:35:59 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.h.orig	2012-03-13 05:32:27.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.h
@@ -360,7 +360,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
