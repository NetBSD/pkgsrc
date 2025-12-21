$NetBSD: patch-src_3rdparty_chromium_net_dns_public_scoped__res__state.h,v 1.1 2025/12/21 09:38:34 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/dns/public/scoped_res_state.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/net/dns/public/scoped_res_state.h
@@ -5,6 +5,7 @@
 #ifndef NET_DNS_PUBLIC_SCOPED_RES_STATE_H_
 #define NET_DNS_PUBLIC_SCOPED_RES_STATE_H_
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 #include <optional>
