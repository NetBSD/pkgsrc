$NetBSD: patch-net_dns_public_scoped__res__state.cc,v 1.8 2025/10/16 19:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/public/scoped_res_state.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ net/dns/public/scoped_res_state.cc
@@ -33,7 +33,7 @@ ScopedResState::~ScopedResState() {
 #if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_FUCHSIA)
 
   // Prefer res_ndestroy where available.
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   res_ndestroy(&res_);
 #else
   res_nclose(&res_);
