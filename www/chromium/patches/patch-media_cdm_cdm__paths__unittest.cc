$NetBSD: patch-media_cdm_cdm__paths__unittest.cc,v 1.25 2026/09/02 13:13:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/cdm/cdm_paths_unittest.cc.orig	2026-08-31 22:47:51.000000000 +0000
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
