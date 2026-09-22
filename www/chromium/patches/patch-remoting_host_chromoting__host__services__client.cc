$NetBSD: patch-remoting_host_chromoting__host__services__client.cc,v 1.26 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host_services_client.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/host/chromoting_host_services_client.cc
@@ -78,7 +78,7 @@ mojo::PendingRemote<mojom::ChromotingHos
 
 ChromotingHostServicesClient::ChromotingHostServicesClient()
     : ChromotingHostServicesClient(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           std::vector{GetChromotingHostServicesServerName(),
                       GetLegacyChromotingHostServicesServerName()}
 #else
@@ -147,7 +147,7 @@ bool ChromotingHostServicesClient::Ensur
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
