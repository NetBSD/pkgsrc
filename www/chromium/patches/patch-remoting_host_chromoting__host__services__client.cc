$NetBSD: patch-remoting_host_chromoting__host__services__client.cc,v 1.1 2025/02/06 09:58:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host_services_client.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/chromoting_host_services_client.cc
@@ -59,7 +59,7 @@ mojo::PendingRemote<mojom::ChromotingHos
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 constexpr char
@@ -136,7 +136,7 @@ bool ChromotingHostServicesClient::Ensur
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
