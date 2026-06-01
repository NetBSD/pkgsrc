$NetBSD: patch-components_device__signals_test_signals__contract.cc,v 1.20 2026/06/01 10:09:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/test/signals_contract.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/device_signals/test/signals_contract.cc
@@ -216,7 +216,7 @@ GetSignalsContract() {
       base::BindRepeating(VerifyUnset, names::kCrowdStrike);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   contract[names::kAllowScreenLock] =
       base::BindRepeating(VerifyUnset, names::kAllowScreenLock);
   contract[names::kImei] = base::BindRepeating(VerifyUnset, names::kImei);
