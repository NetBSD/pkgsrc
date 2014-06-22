$NetBSD: patch-mozilla_dom_plugins_ipc_PluginProcessChild.cpp,v 1.1 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginProcessChild.cpp.orig	2014-06-13 00:45:23.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginProcessChild.cpp
@@ -42,7 +42,7 @@ namespace plugins {
 bool
 PluginProcessChild::Init()
 {
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // Remove the trigger for "dyld interposing" that we added in
     // GeckoChildProcessHost::PerformAsyncLaunchInternal(), in the host
     // process just before we were launched.  Dyld interposing will still
