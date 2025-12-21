$NetBSD: patch-src_3rdparty_chromium_net_socket_socks5__client__socket.cc,v 1.1 2025/12/21 09:38:34 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/socket/socks5_client_socket.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/net/socket/socks5_client_socket.cc
@@ -24,6 +24,9 @@
 #include "net/log/net_log_event_type.h"
 #include "net/traffic_annotation/network_traffic_annotation.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
+
 namespace net {
 
 const unsigned int SOCKS5ClientSocket::kGreetReadHeaderSize = 2;
