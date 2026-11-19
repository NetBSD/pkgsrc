$NetBSD: patch-remoting_host_host__power__save__blocker.cc,v 1.25 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_power_save_blocker.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/host_power_save_blocker.cc
@@ -29,7 +29,7 @@ HostPowerSaveBlocker::~HostPowerSaveBloc
 
 void HostPowerSaveBlocker::OnClientConnected(const std::string& jid) {
   // TODO(447203893): Re-enable this on Linux once the bug is fixed.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   blocker_ = std::make_unique<device::PowerSaveBlocker>(
       device::mojom::WakeLockType::kPreventDisplaySleep,
       device::mojom::WakeLockReason::kOther, "Remoting session is active",
