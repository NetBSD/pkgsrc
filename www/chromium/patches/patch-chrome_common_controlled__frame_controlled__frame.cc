$NetBSD: patch-chrome_common_controlled__frame_controlled__frame.cc,v 1.10 2026/04/21 15:21:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/controlled_frame/controlled_frame.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/common/controlled_frame/controlled_frame.cc
@@ -20,7 +20,7 @@
 #include "third_party/blink/public/common/features.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -91,7 +91,7 @@ bool AvailabilityCheck(const std::string
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Verify that the current context is an Isolated Web App and the API name is
   // in our expected list.
   return (extension == nullptr) && url.SchemeIs(webapps::kIsolatedAppScheme) &&
