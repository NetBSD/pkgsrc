$NetBSD: patch-media_cdm_cdm__paths__unittest.cc,v 1.1 2025/02/06 09:58:12 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/cdm/cdm_paths_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/cdm/cdm_paths_unittest.cc
@@ -27,7 +27,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #elif BUILDFLAG(IS_FUCHSIA)
     "fuchsia";
