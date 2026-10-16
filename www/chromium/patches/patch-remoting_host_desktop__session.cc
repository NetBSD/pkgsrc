$NetBSD: patch-remoting_host_desktop__session.cc,v 1.4 2026/10/16 15:30:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ remoting/host/desktop_session.cc
@@ -23,7 +23,7 @@ void DesktopSession::SetReceiver(
   if (receiver.is_valid()) {
     receiver_.reset();
     receiver_.Bind(std::move(receiver));
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On platforms without persistent desktop sessions, immediately close the
     // desktop session when the control pipe drops so that background agents
     // (e.g. `remoting_desktop.exe`) are torn down and resources released.
