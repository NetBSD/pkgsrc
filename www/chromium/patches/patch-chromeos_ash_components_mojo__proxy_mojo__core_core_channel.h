$NetBSD: patch-chromeos_ash_components_mojo__proxy_mojo__core_core_channel.h,v 1.1 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromeos/ash/components/mojo_proxy/mojo_core/core/channel.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/channel.h
@@ -169,7 +169,7 @@ class MOJO_LEGACY_SYSTEM_IMPL_EXPORT Cha
       } v2;
 
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
       // On Android for each pair of connected ipcz::Node instances both sides
       // of the connection run the same version of code. Restricting this
       // extension of IpczHeader to Android allows to iterate on the wire format
