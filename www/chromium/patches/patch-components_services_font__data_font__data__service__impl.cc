$NetBSD: patch-components_services_font__data_font__data__service__impl.cc,v 1.6 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/services/font_data/font_data_service_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/services/font_data/font_data_service_impl.cc
@@ -119,7 +119,7 @@ std::tuple<base::File, uint64_t> FontDat
   typeface.getResourceName(&font_path);
   base::UmaHistogramBoolean("Chrome.FontDataService.EmptyPathOnGetFileHandle",
                             font_path.isEmpty());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/463411679): `getResourceName()` is not implemented for
   // Linux nor ChromeOS, so the returned file will always be invalid and a
   // memory region will be shared instead.
