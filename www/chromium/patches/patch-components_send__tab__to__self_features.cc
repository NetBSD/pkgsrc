$NetBSD: patch-components_send__tab__to__self_features.cc,v 1.1 2026/10/23 15:05:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/send_tab_to_self/features.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/send_tab_to_self/features.cc
@@ -49,7 +49,7 @@ BASE_FEATURE(kSendTabToSelfPostSendToast
 
 BASE_FEATURE(kSendTabToSelfExtraEntryPoints, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Guarded to Windows, Mac, and Linux because it relies on
 // `switches::kCrossDeviceSigninFromDesktopUrl` in
 // `components/signin/public/base/signin_switches.h`.
