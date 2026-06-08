$NetBSD: patch-remoting_signaling_ftl__host__device__id__provider.cc,v 1.20 2026/06/08 13:12:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/signaling/ftl_host_device_id_provider.cc.orig	2026-05-28 23:24:11.000000000 +0000
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
