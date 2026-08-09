$NetBSD: patch-remoting_host_desktop__session__proxy.cc,v 1.6 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_proxy.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/host/desktop_session_proxy.cc
@@ -169,7 +169,7 @@ DesktopSessionProxy::CreateRemoteWebAuth
       base::BindRepeating(&DesktopSessionProxy::SignalWebAuthnExtension, this));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopSessionProxy::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -209,7 +209,7 @@ std::string DesktopSessionProxy::GetCapa
     result += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   result += " ";
   result += protocol::kClientControlledLayoutCapability;
 #endif
