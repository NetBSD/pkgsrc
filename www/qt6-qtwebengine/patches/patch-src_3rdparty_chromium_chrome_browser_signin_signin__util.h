$NetBSD: patch-src_3rdparty_chromium_chrome_browser_signin_signin__util.h,v 1.1 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/signin/signin_util.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/signin/signin_util.h
@@ -171,7 +171,7 @@ SignedInState GetSignedInState(const sig
 // Returns a string representation of `SignedInState`.
 std::string SignedInStateToString(SignedInState state);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns if the necessary conditions to show the History Sync Optin screen
 // are met.
 // This method does not take into account any feature flags related to the above
