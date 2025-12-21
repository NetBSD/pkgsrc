$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_enterprise__reporting__private_conversion__utils.h,v 1.1 2025/12/21 09:38:18 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #include <optional>
 #include <vector>
