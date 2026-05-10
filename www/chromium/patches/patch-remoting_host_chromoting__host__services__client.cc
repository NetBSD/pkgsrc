$NetBSD: patch-remoting_host_chromoting__host__services__client.cc,v 1.19 2026/05/10 15:30:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host_services_client.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ remoting/host/chromoting_host_services_client.cc
@@ -74,7 +74,7 @@ mojo::PendingRemote<mojom::ChromotingHos
 
 ChromotingHostServicesClient::ChromotingHostServicesClient()
     : ChromotingHostServicesClient(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           std::vector{GetChromotingHostServicesServerName(),
                       GetLegacyChromotingHostServicesServerName()}
 #else
@@ -163,7 +163,7 @@ bool ChromotingHostServicesClient::Ensur
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
