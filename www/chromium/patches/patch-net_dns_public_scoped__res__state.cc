$NetBSD: patch-net_dns_public_scoped__res__state.cc,v 1.33 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/public/scoped_res_state.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ net/dns/public/scoped_res_state.cc
@@ -29,7 +29,7 @@ ScopedResState::~ScopedResState() {
 #if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_FUCHSIA)
 
   // Prefer res_ndestroy where available.
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   res_ndestroy(&res_);
 #else
   res_nclose(&res_);
