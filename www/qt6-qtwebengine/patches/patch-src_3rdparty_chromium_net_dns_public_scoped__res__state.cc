$NetBSD: patch-src_3rdparty_chromium_net_dns_public_scoped__res__state.cc,v 1.1 2025/12/21 09:38:34 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/dns/public/scoped_res_state.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/net/dns/public/scoped_res_state.cc
@@ -28,7 +28,7 @@ ScopedResState::~ScopedResState() {
 #if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_FUCHSIA)
 
   // Prefer res_ndestroy where available.
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   res_ndestroy(&res_);
 #else
   res_nclose(&res_);
