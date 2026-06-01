$NetBSD: patch-remoting_host_desktop__session__proxy.h,v 1.2 2026/06/01 10:09:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_proxy.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ remoting/host/desktop_session_proxy.h
@@ -107,7 +107,7 @@ class DesktopSessionProxy
   std::unique_ptr<UrlForwarderConfigurator> CreateUrlForwarderConfigurator();
   std::unique_ptr<RemoteWebAuthnStateChangeNotifier>
   CreateRemoteWebAuthnStateChangeNotifier();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
 #endif
