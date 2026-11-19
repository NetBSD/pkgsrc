$NetBSD: patch-remoting_signaling_ftl__host__device__id__provider.cc,v 1.32 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/signaling/ftl_host_device_id_provider.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/signaling/ftl_host_device_id_provider.cc
@@ -16,7 +16,7 @@ constexpr char kDeviceIdPrefix[] = "crd-
 constexpr char kDeviceIdPrefix[] = "crd-mac-host-";
 #elif BUILDFLAG(IS_CHROMEOS)
 constexpr char kDeviceIdPrefix[] = "crd-cros-host-";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kDeviceIdPrefix[] = "crd-linux-host-";
 #else
 constexpr char kDeviceIdPrefix[] = "crd-unknown-host-";
