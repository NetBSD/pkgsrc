$NetBSD: patch-net_dns_address__sorter__posix.cc,v 1.17 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/address_sorter_posix.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ net/dns/address_sorter_posix.cc
@@ -29,6 +29,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 #include <vector>
