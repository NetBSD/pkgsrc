$NetBSD: patch-src_3rdparty_chromium_net_tools_quic_quic__http__proxy__backend.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/tools/quic/quic_http_proxy_backend.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/tools/quic/quic_http_proxy_backend.cc
@@ -162,7 +162,7 @@ void QuicHttpProxyBackend::InitializeURL
   // Enable HTTP2, but disable QUIC on the backend
   context_builder.SetSpdyAndQuicEnabled(true /* http2 */, false /* quic */);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   context_builder.set_proxy_config_service(
