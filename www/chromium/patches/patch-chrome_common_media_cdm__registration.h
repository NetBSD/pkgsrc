$NetBSD: patch-chrome_common_media_cdm__registration.h,v 1.5 2025/08/13 07:44:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/media/cdm_registration.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/common/media/cdm_registration.h
@@ -15,7 +15,7 @@
 void RegisterCdmInfo(std::vector<content::CdmInfo>* cdms);
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Returns the software secure Widevine CDM, if one exists.
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine();
 #endif
