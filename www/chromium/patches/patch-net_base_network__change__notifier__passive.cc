$NetBSD: patch-net_base_network__change__notifier__passive.cc,v 1.24 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/network_change_notifier_passive.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ net/base/network_change_notifier_passive.cc
@@ -108,7 +108,7 @@ NetworkChangeNotifierPassive::GetAddress
 NetworkChangeNotifier::NetworkChangeCalculatorParams
 NetworkChangeNotifierPassive::NetworkChangeCalculatorParamsPassive() {
   NetworkChangeCalculatorParams params;
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Delay values arrived at by simple experimentation and adjusted so as to
   // produce a single signal when switching between network connections.
   params.ip_address_offline_delay_ = base::Milliseconds(4000);
