$NetBSD: patch-sandbox_policy_features.cc,v 1.14 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ sandbox/policy/features.cc
@@ -154,7 +154,7 @@ bool IsNetworkSandboxSupported() {
 #endif  // BUILDFLAG(IS_WIN)
 
 bool IsNetworkSandboxEnabled() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return true;
 #else
 #if BUILDFLAG(IS_WIN)
