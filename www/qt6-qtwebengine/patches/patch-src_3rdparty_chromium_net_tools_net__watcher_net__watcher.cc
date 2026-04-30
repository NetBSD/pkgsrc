$NetBSD: patch-src_3rdparty_chromium_net_tools_net__watcher_net__watcher.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/tools/net_watcher/net_watcher.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/net/tools/net_watcher/net_watcher.cc
@@ -31,7 +31,7 @@
 #include "net/proxy_resolution/proxy_config_service.h"
 #include "net/proxy_resolution/proxy_config_with_annotation.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_linux.h"
 #endif
 
@@ -41,7 +41,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Flag to specifies which network interfaces to ignore. Interfaces should
 // follow as a comma seperated list.
 const char kIgnoreNetifFlag[] = "ignore-netif";
@@ -160,7 +160,7 @@ int main(int argc, char* argv[]) {
 
   NetWatcher net_watcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   std::string ignored_netifs_str =
       command_line->GetSwitchValueASCII(kIgnoreNetifFlag);
