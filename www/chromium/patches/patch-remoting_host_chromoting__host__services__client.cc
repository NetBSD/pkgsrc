$NetBSD: patch-remoting_host_chromoting__host__services__client.cc,v 1.7 2025/09/12 16:02:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host_services_client.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ remoting/host/chromoting_host_services_client.cc
@@ -139,7 +139,7 @@ bool ChromotingHostServicesClient::Ensur
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
