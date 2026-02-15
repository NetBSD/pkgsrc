$NetBSD: patch-remoting_host_host__power__save__blocker.cc,v 1.7 2026/02/15 09:04:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_power_save_blocker.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ remoting/host/host_power_save_blocker.cc
@@ -29,7 +29,7 @@ HostPowerSaveBlocker::~HostPowerSaveBloc
 
 void HostPowerSaveBlocker::OnClientConnected(const std::string& jid) {
   // TODO(447203893): Re-enable this on Linux once the bug is fixed.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   blocker_ = std::make_unique<device::PowerSaveBlocker>(
       device::mojom::WakeLockType::kPreventDisplaySleep,
       device::mojom::WakeLockReason::kOther, "Remoting session is active",
