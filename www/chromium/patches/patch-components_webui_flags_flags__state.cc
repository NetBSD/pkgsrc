$NetBSD: patch-components_webui_flags_flags__state.cc,v 1.19 2026/06/01 10:09:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webui/flags/flags_state.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/webui/flags/flags_state.cc
@@ -773,7 +773,7 @@ unsigned short FlagsState::GetCurrentPla
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kOsCrOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
