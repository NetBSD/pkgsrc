$NetBSD: patch-components_notebooks_internal_notebooks__network__service__impl.cc,v 1.2 2026/09/29 07:42:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/notebooks/internal/notebooks_network_service_impl.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/notebooks/internal/notebooks_network_service_impl.cc
@@ -69,7 +69,7 @@ Device GetDevice() {
   return Device::kMobileAndroid;
 #elif BUILDFLAG(IS_IOS)
   return Device::kMobileIos;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return Device::kDesktop;
 #else
   return Device::kOther;
