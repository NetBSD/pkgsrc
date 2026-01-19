$NetBSD: patch-net_http_http__network__session.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_network_session.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/http/http_network_session.cc
@@ -21,7 +21,9 @@
 #include "build/build_config.h"
 #include "net/base/features.h"
 #include "net/dns/host_resolver.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory.h"
 #include "net/http/http_stream_pool.h"
