$NetBSD: patch-components_enterprise_data__controls_core_browser_features.cc,v 1.3 2025/09/12 16:02:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/data_controls/core/browser/features.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/enterprise/data_controls/core/browser/features.cc
@@ -13,7 +13,7 @@ BASE_FEATURE(kEnableClipboardDataControl
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDownloadDataControlsDesktop,
              "EnableDownloadDataControlsDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
