$NetBSD: patch-dom_plugins_ipc_PluginProcessChild.cpp,v 1.1 2014/11/03 12:18:32 ryoon Exp $

Just because OS_ARCH is Darwin does not mean
libplugin_child_interpose.dylib is used.

--- dom/plugins/ipc/PluginProcessChild.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/ipc/PluginProcessChild.cpp
@@ -42,7 +42,7 @@ namespace plugins {
 bool
 PluginProcessChild::Init()
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // Remove the trigger for "dyld interposing" that we added in
     // GeckoChildProcessHost::PerformAsyncLaunchInternal(), in the host
     // process just before we were launched.  Dyld interposing will still
