$NetBSD: patch-net_dns_host__resolver__proc.cc,v 1.27 2026/09/29 07:43:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/host_resolver_proc.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ net/dns/host_resolver_proc.cc
@@ -16,10 +16,6 @@
 #include "net/base/net_errors.h"
 #include "net/dns/host_resolver_system_task.h"
 
-#if BUILDFLAG(IS_OPENBSD)
-#define AI_ADDRCONFIG 0
-#endif
-
 namespace net {
 
 HostResolverProc* HostResolverProc::default_proc_ = nullptr;
