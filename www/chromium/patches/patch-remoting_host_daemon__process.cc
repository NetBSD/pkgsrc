$NetBSD: patch-remoting_host_daemon__process.cc,v 1.4 2026/10/16 15:30:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/daemon_process.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ remoting/host/daemon_process.cc
@@ -299,7 +299,7 @@ void DaemonProcess::GetDesktopSession(
   // Windows, user sessions and applications are persisted natively by the OS,
   // and the desktop process is purely a transient capture/input agent that is
   // recreated per connection.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::string& client_id = options->client_id;
   auto it = std::ranges::find_if(desktop_sessions_, [&](const auto& pair) {
     return !client_id.empty() && pair.second->client_id() == client_id;
