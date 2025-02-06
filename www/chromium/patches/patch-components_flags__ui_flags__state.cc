$NetBSD: patch-components_flags__ui_flags__state.cc,v 1.1 2025/02/06 09:58:00 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/flags_ui/flags_state.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/flags_ui/flags_state.cc
@@ -755,7 +755,7 @@ unsigned short FlagsState::GetCurrentPla
   return kOsCrOS;
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return kOsLacros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
