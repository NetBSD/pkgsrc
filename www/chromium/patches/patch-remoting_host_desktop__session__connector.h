$NetBSD: patch-remoting_host_desktop__session__connector.h,v 1.7 2026/07/06 13:06:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_connector.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ remoting/host/desktop_session_connector.h
@@ -57,7 +57,7 @@ class DesktopSessionConnector : public m
   // connections.
   virtual void SetRequiredUsername(std::string_view username) = 0;
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Notifies the network process that |terminal_id| is now attached to
   // a desktop integration process. |desktop_pipe| is the client end of the pipe
   // opened by the desktop process.
