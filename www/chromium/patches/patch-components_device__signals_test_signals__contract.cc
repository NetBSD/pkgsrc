$NetBSD: patch-components_device__signals_test_signals__contract.cc,v 1.6 2025/09/08 13:24:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/test/signals_contract.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/device_signals/test/signals_contract.cc
@@ -221,7 +221,7 @@ GetSignalsContract(bool is_av_signal_ena
       base::BindRepeating(VerifyUnset, names::kCrowdStrike);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   contract[names::kAllowScreenLock] =
       base::BindRepeating(VerifyUnset, names::kAllowScreenLock);
   contract[names::kImei] = base::BindRepeating(VerifyUnset, names::kImei);
