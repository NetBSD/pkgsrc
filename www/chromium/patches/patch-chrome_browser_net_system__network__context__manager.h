$NetBSD: patch-chrome_browser_net_system__network__context__manager.h,v 1.15 2026/02/15 09:03:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/net/system_network_context_manager.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/net/system_network_context_manager.h
@@ -222,7 +222,7 @@ class SystemNetworkContextManager {
   class URLLoaderFactoryForSystem;
   class NetworkProcessLaunchWatcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   class GssapiLibraryLoadObserver
       : public network::mojom::GssapiLibraryLoadObserver {
    public:
@@ -305,7 +305,7 @@ class SystemNetworkContextManager {
   std::unique_ptr<NetworkAnnotationMonitor> network_annotation_monitor_;
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GssapiLibraryLoadObserver gssapi_library_loader_observer_{this};
 #endif  // BUILDFLAG(IS_LINUX)
 
