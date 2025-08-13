$NetBSD: patch-net_dns_public_scoped__res__state.h,v 1.5 2025/08/13 07:44:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/public/scoped_res_state.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ net/dns/public/scoped_res_state.h
@@ -5,6 +5,7 @@
 #ifndef NET_DNS_PUBLIC_SCOPED_RES_STATE_H_
 #define NET_DNS_PUBLIC_SCOPED_RES_STATE_H_
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 #include <optional>
