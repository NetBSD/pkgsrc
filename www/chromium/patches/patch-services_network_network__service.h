$NetBSD: patch-services_network_network__service.h,v 1.19 2026/05/10 15:30:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/network_service.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ services/network/network_service.h
@@ -237,7 +237,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
       const std::vector<ContentSettingPatternSource>& settings) override;
 
   void SetExplicitlyAllowedPorts(const std::vector<uint16_t>& ports) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetGssapiLibraryLoadObserver(
       mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
           gssapi_library_load_observer) override;
@@ -300,7 +300,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   std::unique_ptr<net::HttpAuthHandlerFactory> CreateHttpAuthHandlerFactory(
       NetworkContext* network_context);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This is called just before a GSSAPI library may be loaded.
   void OnBeforeGssapiLibraryLoad();
 #endif  // BUILDFLAG(IS_LINUX)
@@ -575,7 +575,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   // leaking stale listeners between tests.
   std::unique_ptr<net::NetworkChangeNotifier> mock_network_change_notifier_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   mojo::Remote<mojom::GssapiLibraryLoadObserver> gssapi_library_load_observer_;
 #endif  // BUILDFLAG(IS_LINUX)
 
