$NetBSD: patch-src_3rdparty_chromium_content_browser_ppapi__plugin__process__host.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/ppapi_plugin_process_host.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/ppapi_plugin_process_host.cc
@@ -364,7 +364,7 @@ bool PpapiPluginProcessHost::Init(const 
   base::CommandLine::StringType plugin_launcher =
       browser_command_line.GetSwitchValueNative(switches::kPpapiPluginLauncher);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int flags = plugin_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                         ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
