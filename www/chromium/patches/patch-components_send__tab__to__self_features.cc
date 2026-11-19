$NetBSD: patch-components_send__tab__to__self_features.cc,v 1.3 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/send_tab_to_self/features.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/send_tab_to_self/features.cc
@@ -29,7 +29,7 @@ BASE_FEATURE(kSendTabToSelfSupportAutoOp
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Guarded to Windows, Mac, and Linux because it relies on
 // `switches::kCrossDeviceSigninFromDesktopUrl` in
 // `components/signin/public/base/signin_switches.h`.
