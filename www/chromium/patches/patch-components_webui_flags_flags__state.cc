$NetBSD: patch-components_webui_flags_flags__state.cc,v 1.25 2026/09/22 13:41:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webui/flags/flags_state.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/webui/flags/flags_state.cc
@@ -794,7 +794,7 @@ unsigned short FlagsState::GetCurrentPla
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kOsCrOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
