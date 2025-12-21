$NetBSD: patch-src_3rdparty_chromium_net_base_features.cc,v 1.1 2025/12/21 09:38:33 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/base/features.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/net/base/features.cc
@@ -451,7 +451,7 @@ BASE_FEATURE(kDisableBlackholeOnNoNewNet
              "DisableBlackHoleOnNoNewNetwork",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAddressTrackerLinuxIsProxied,
              "AddressTrackerLinuxIsProxied",
              base::FEATURE_ENABLED_BY_DEFAULT);
