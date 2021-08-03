$NetBSD: patch-src_3rdparty_chromium_net_proxy__resolution_configured__proxy__resolution__service.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/proxy_resolution/configured_proxy_resolution_service.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/net/proxy_resolution/configured_proxy_resolution_service.cc
@@ -47,7 +47,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy_resolution/proxy_config_service_mac.h"
 #include "net/proxy_resolution/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "net/proxy_resolution/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy_resolution/proxy_config_service_android.h"
@@ -61,7 +61,7 @@ namespace net {
 namespace {
 
 #if defined(OS_WIN) || defined(OS_IOS) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 constexpr net::NetworkTrafficAnnotationTag kSystemProxyConfigTrafficAnnotation =
     net::DefineNetworkTrafficAnnotation("proxy_config_system", R"(
       semantics {
@@ -1410,7 +1410,7 @@ ConfiguredProxyResolutionService::Create
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return std::make_unique<UnsetProxyConfigService>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
