$NetBSD: patch-src_3rdparty_chromium_chrome_common_media_cdm__registration.cc,v 1.1 2025/12/21 09:38:20 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/media/cdm_registration.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/media/cdm_registration.cc
@@ -33,7 +33,7 @@
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #include "components/cdm/common/cdm_manifest.h"
 #include "third_party/widevine/cdm/widevine_cdm_common.h"  // nogncheck
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/native_library.h"
 #include "chrome/common/chrome_paths.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
@@ -52,7 +52,7 @@ using Robustness = content::CdmInfo::Rob
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #if (BUILDFLAG(BUNDLE_WIDEVINE_CDM) ||            \
      BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Create a CdmInfo for a Widevine CDM, using |version|, |cdm_library_path|, and
 // |capability|.
 std::unique_ptr<content::CdmInfo> CreateWidevineCdmInfo(
@@ -97,7 +97,7 @@ std::unique_ptr<content::CdmInfo> Create
         // BUILDFLAG(IS_CHROMEOS))
 
 #if BUILDFLAG(BUNDLE_WIDEVINE_CDM) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // On Linux/ChromeOS we have to preload the CDM since it uses the zygote
 // sandbox. On Windows and Mac, CDM registration is handled by Component
 // Update (as the CDM can be loaded only when needed).
@@ -121,7 +121,7 @@ std::unique_ptr<content::CdmInfo> GetBun
         // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 
 #if (BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT) && \
-     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)))
+     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)))
 // This code checks to see if Component Updater picked a version of the Widevine
 // CDM to be used last time it ran. (Component Updater may choose the bundled
 // CDM if there is not a new version available for download.) If there is one
@@ -163,7 +163,7 @@ void AddSoftwareSecureWidevine(std::vect
       /*supports_sub_key_systems=*/false, kWidevineCdmDisplayName,
       kWidevineCdmType, base::Version(), base::FilePath());
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The Widevine CDM on Linux/ChromeOS needs to be registered (and loaded)
   // before the zygote is locked down. The CDM can be found from the version
   // bundled with Chrome (if BUNDLE_WIDEVINE_CDM = true) and/or the version
@@ -388,7 +388,7 @@ void RegisterCdmInfo(std::vector<content
 }
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine() {
   std::vector<content::CdmInfo> cdms;
   AddSoftwareSecureWidevine(&cdms);
