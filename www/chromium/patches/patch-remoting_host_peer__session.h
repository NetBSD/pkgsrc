$NetBSD: patch-remoting_host_peer__session.h,v 1.1 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/peer_session.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/host/peer_session.h
@@ -19,7 +19,7 @@
 #include "remoting/proto/control.pb.h"
 #include "remoting/protocol/errors.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/mojom/peer_session.mojom.h"
 #endif
 
@@ -40,7 +40,7 @@ struct SessionPolicies;
 class PeerSession {
  public:
   // LINT.IfChange(peer_session_event_handler)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Windows and Linux, `PeerSession::EventHandler` is an alias to the
   // generated Mojo interface `mojom::PeerSessionEventHandler`.
   using EventHandler = mojom::PeerSessionEventHandler;
