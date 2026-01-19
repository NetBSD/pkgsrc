$NetBSD: patch-chrome_browser_safe__browsing_cloud__content__scanning_binary__upload__service.cc,v 1.14 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc
@@ -21,7 +21,7 @@
 #include "components/safe_browsing/core/common/safebrowsing_switches.h"
 #include "net/base/url_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/local_binary_upload_service_factory.h"
 #endif
 
