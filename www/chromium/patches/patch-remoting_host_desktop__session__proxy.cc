$NetBSD: patch-remoting_host_desktop__session__proxy.cc,v 1.1 2026/05/10 15:30:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_proxy.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ remoting/host/desktop_session_proxy.cc
@@ -163,7 +163,7 @@ DesktopSessionProxy::CreateRemoteWebAuth
       base::BindRepeating(&DesktopSessionProxy::SignalWebAuthnExtension, this));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopSessionProxy::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -203,7 +203,7 @@ std::string DesktopSessionProxy::GetCapa
     result += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   result += " ";
   result += protocol::kClientControlledLayoutCapability;
 #endif
