$NetBSD: patch-net_dns_dns__util.cc,v 1.23 2026/07/08 13:42:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/dns_util.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ net/dns/dns_util.cc
@@ -27,6 +27,8 @@
 #include "net/dns/public/util.h"
 #include "net/third_party/uri_template/uri_template.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <net/if.h>
 #include <netinet/in.h>
