$NetBSD: patch-services_network_network__service.cc,v 1.16 2026/03/14 12:40:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/network_service.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ services/network/network_service.cc
@@ -105,11 +105,11 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "services/network/network_change_notifier_passive_factory.h"
 #endif
 
@@ -1014,7 +1014,7 @@ void NetworkService::SetExplicitlyAllowe
   net::SetExplicitlyAllowedPorts(ports);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::SetGssapiLibraryLoadObserver(
     mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
         gssapi_library_load_observer) {
@@ -1154,7 +1154,7 @@ NetworkService::CreateHttpAuthHandlerFac
   );
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::OnBeforeGssapiLibraryLoad() {
   if (gssapi_library_load_observer_.is_bound()) {
     gssapi_library_load_observer_->OnBeforeGssapiLibraryLoad();
