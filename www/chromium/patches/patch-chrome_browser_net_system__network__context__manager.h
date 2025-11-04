$NetBSD: patch-chrome_browser_net_system__network__context__manager.h,v 1.9 2025/11/04 14:55:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/net/system_network_context_manager.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/net/system_network_context_manager.h
@@ -212,7 +212,7 @@ class SystemNetworkContextManager {
   class URLLoaderFactoryForSystem;
   class NetworkProcessLaunchWatcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   class GssapiLibraryLoadObserver
       : public network::mojom::GssapiLibraryLoadObserver {
    public:
@@ -295,7 +295,7 @@ class SystemNetworkContextManager {
   std::unique_ptr<NetworkAnnotationMonitor> network_annotation_monitor_;
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GssapiLibraryLoadObserver gssapi_library_loader_observer_{this};
 #endif  // BUILDFLAG(IS_LINUX)
 
