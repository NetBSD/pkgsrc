$NetBSD: patch-src_3rdparty_chromium_net_http_http__network__session.cc,v 1.1 2025/12/21 09:38:34 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/http/http_network_session.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/net/http/http_network_session.cc
@@ -20,7 +20,9 @@
 #include "build/build_config.h"
 #include "net/base/features.h"
 #include "net/dns/host_resolver.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory.h"
 #include "net/http/http_stream_pool.h"
