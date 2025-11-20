$NetBSD: patch-media_cdm_cdm__paths__unittest.cc,v 1.10 2025/11/20 08:36:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/cdm/cdm_paths_unittest.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ media/cdm/cdm_paths_unittest.cc
@@ -26,7 +26,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #elif BUILDFLAG(IS_FUCHSIA)
     "fuchsia";
