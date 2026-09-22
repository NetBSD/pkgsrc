$NetBSD: patch-net_dns_dns__util.cc,v 1.26 2026/09/22 13:41:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/dns_util.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ net/dns/dns_util.cc
@@ -27,6 +27,8 @@
 #include "net/third_party/uri_template/uri_template.h"
 #include "third_party/abseil-cpp/absl/container/flat_hash_map.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <net/if.h>
 #include <netinet/in.h>
