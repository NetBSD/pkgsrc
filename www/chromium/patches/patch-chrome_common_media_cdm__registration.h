$NetBSD: patch-chrome_common_media_cdm__registration.h,v 1.24 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/media/cdm_registration.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/common/media/cdm_registration.h
@@ -15,7 +15,7 @@
 void RegisterCdmInfo(std::vector<content::CdmInfo>* cdms);
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Returns the software secure Widevine CDM, if one exists.
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine();
 #endif
