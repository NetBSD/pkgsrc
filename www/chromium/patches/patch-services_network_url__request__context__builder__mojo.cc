$NetBSD: patch-services_network_url__request__context__builder__mojo.cc,v 1.1 2026/11/08 15:39:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/url_request_context_builder_mojo.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ services/network/url_request_context_builder_mojo.cc
@@ -19,7 +19,7 @@
 #elif BUILDFLAG(IS_MAC)
 #include "net/proxy_resolution/mac/mac_system_proxy_resolution_service.h"
 #include "services/network/mac_system_proxy_resolver_mojo.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/linux/linux_system_proxy_resolution_service.h"
 #include "services/network/linux_system_proxy_resolver_mojo.h"
 #elif BUILDFLAG(IS_CHROMEOS)
@@ -39,7 +39,7 @@ void URLRequestContextBuilderMojo::SetMo
   mojo_proxy_resolver_factory_ = std::move(mojo_proxy_resolver_factory);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void URLRequestContextBuilderMojo::SetMojoSystemProxyResolver(
     mojo::PendingRemote<proxy_resolver::mojom::SystemProxyResolver>
         mojo_system_proxy_resolver) {
@@ -102,7 +102,7 @@ URLRequestContextBuilderMojo::CreateProx
       return proxy_resolution_service;
     }
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mojo_system_proxy_resolver_) {
     std::unique_ptr<net::ProxyResolutionService> proxy_resolution_service =
         net::LinuxSystemProxyResolutionService::Create(
