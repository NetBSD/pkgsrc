$NetBSD: patch-components_feature__engagement_public_tracker.h,v 1.3 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/tracker.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/feature_engagement/public/tracker.h
@@ -260,7 +260,7 @@ class Tracker : public KeyedService, pub
     Dismissed(feature);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(https://crbug.com/511194274): For now, allow calling the base API in
   // chromeos-only code; remove the exception for ChromeOS when we've migrated
   // those calls.
