$NetBSD: patch-chrome_common_controlled__frame_controlled__frame.cc,v 1.6 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/controlled_frame/controlled_frame.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/common/controlled_frame/controlled_frame.cc
@@ -18,7 +18,7 @@
 #include "third_party/blink/public/common/features.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -89,7 +89,7 @@ bool AvailabilityCheck(const std::string
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Verify that the current context is an Isolated Web App and the API name is
   // in our expected list.
   return (extension == nullptr) && url.SchemeIs(webapps::kIsolatedAppScheme) &&
