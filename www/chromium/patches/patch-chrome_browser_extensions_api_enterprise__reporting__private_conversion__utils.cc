$NetBSD: patch-chrome_browser_extensions_api_enterprise__reporting__private_conversion__utils.cc,v 1.9 2025/11/04 14:55:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.cc
@@ -8,7 +8,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #include <memory>
 #include <utility>
