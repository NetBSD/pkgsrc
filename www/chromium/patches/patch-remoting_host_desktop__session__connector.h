$NetBSD: patch-remoting_host_desktop__session__connector.h,v 1.9 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_connector.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/host/desktop_session_connector.h
@@ -57,7 +57,7 @@ class DesktopSessionConnector : public m
   // connections.
   virtual void SetRequiredUsername(std::string_view username) = 0;
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Notifies the network process that |terminal_id| is now attached to
   // a desktop integration process. |desktop_pipe| is the client end of the pipe
   // opened by the desktop process.
