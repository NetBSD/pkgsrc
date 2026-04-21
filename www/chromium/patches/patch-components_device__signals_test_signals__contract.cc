$NetBSD: patch-components_device__signals_test_signals__contract.cc,v 1.18 2026/04/21 15:21:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/test/signals_contract.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/device_signals/test/signals_contract.cc
@@ -216,7 +216,7 @@ GetSignalsContract() {
       base::BindRepeating(VerifyUnset, names::kCrowdStrike);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   contract[names::kAllowScreenLock] =
       base::BindRepeating(VerifyUnset, names::kAllowScreenLock);
   contract[names::kImei] = base::BindRepeating(VerifyUnset, names::kImei);
