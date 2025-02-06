$NetBSD: patch-components_safe__browsing_core_browser_realtime_url__lookup__service__base.cc,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -110,7 +110,7 @@ RTLookupRequest::OSType GetRTLookupReque
   return RTLookupRequest::OS_TYPE_CHROME_OS;
 #elif BUILDFLAG(IS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif BUILDFLAG(IS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
