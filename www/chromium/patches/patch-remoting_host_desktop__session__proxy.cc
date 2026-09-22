$NetBSD: patch-remoting_host_desktop__session__proxy.cc,v 1.8 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_proxy.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/host/desktop_session_proxy.cc
@@ -168,7 +168,7 @@ DesktopSessionProxy::CreateRemoteWebAuth
       base::BindRepeating(&DesktopSessionProxy::SignalWebAuthnExtension, this));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopSessionProxy::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -208,7 +208,7 @@ std::string DesktopSessionProxy::GetCapa
     result += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   result += " ";
   result += protocol::kClientControlledLayoutCapability;
 #endif
