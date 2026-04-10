$NetBSD: patch-components_safe__browsing_core_browser_realtime_url__lookup__service__base.cc,v 1.17 2026/04/10 17:31:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -116,7 +116,7 @@ RTLookupRequest::OSType GetRTLookupReque
   return RTLookupRequest::OS_TYPE_CHROME_OS;
 #elif BUILDFLAG(IS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif BUILDFLAG(IS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
