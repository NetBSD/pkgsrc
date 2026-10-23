$NetBSD: patch-net_cert_ev__root__ca__metadata.h,v 1.3 2026/10/23 15:05:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/cert/ev_root_ca_metadata.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ net/cert/ev_root_ca_metadata.h
@@ -17,7 +17,7 @@
 #include "net/cert/x509_certificate.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // When not defined, the EVRootCAMetadata singleton is a dumb placeholder
 // implementation that will fail all EV lookup operations.
 #define PLATFORM_USES_CHROMIUM_EV_METADATA
