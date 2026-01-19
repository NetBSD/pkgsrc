$NetBSD: patch-net_tools_net__watcher_net__watcher.cc,v 1.15 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/tools/net_watcher/net_watcher.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/tools/net_watcher/net_watcher.cc
@@ -32,7 +32,7 @@
 #include "net/proxy_resolution/proxy_config_service.h"
 #include "net/proxy_resolution/proxy_config_with_annotation.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_linux.h"
 #endif
 
@@ -42,7 +42,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Flag to specifies which network interfaces to ignore. Interfaces should
 // follow as a comma seperated list.
 const char kIgnoreNetifFlag[] = "ignore-netif";
@@ -177,7 +177,7 @@ int main(int argc, char* argv[]) {
 
   NetWatcher net_watcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   std::string ignored_netifs_str =
       command_line->GetSwitchValueASCII(kIgnoreNetifFlag);
