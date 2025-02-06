$NetBSD: patch-chrome_common_media_cdm__registration.h,v 1.1 2025/02/06 09:57:57 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/media/cdm_registration.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/common/media/cdm_registration.h
@@ -16,7 +16,7 @@
 void RegisterCdmInfo(std::vector<content::CdmInfo>* cdms);
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD))
 // Returns the software secure Widevine CDM, if one exists.
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine();
 #endif
