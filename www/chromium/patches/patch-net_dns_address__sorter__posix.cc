$NetBSD: patch-net_dns_address__sorter__posix.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/address_sorter_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/dns/address_sorter_posix.cc
@@ -32,6 +32,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 #include <vector>
