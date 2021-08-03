$NetBSD: patch-src_3rdparty_chromium_net_tools_cert__verify__tool_cert__verify__tool.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/net/tools/cert_verify_tool/cert_verify_tool.cc
@@ -29,7 +29,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -51,7 +51,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
