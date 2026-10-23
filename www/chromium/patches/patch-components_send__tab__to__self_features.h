$NetBSD: patch-components_send__tab__to__self_features.h,v 1.1 2026/10/23 15:05:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/send_tab_to_self/features.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/send_tab_to_self/features.h
@@ -59,7 +59,7 @@ BASE_DECLARE_FEATURE(kSendTabToSelfPostS
 // to the Omnibox context menu.
 BASE_DECLARE_FEATURE(kSendTabToSelfExtraEntryPoints);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, a QR code promo is shown in the Send Tab to Self
 // bubble on desktop when no target devices are found. Guarded to Windows, Mac,
 // and Linux because it relies on `switches::kCrossDeviceSigninFromDesktopUrl`
