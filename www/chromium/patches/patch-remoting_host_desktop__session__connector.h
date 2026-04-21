$NetBSD: patch-remoting_host_desktop__session__connector.h,v 1.3 2026/04/21 15:21:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_connector.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ remoting/host/desktop_session_connector.h
@@ -57,7 +57,7 @@ class DesktopSessionConnector : public m
   // connections.
   virtual void SetRequiredUsername(std::string_view username) = 0;
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Notifies the network process that |terminal_id| is now attached to
   // a desktop integration process. |session_id| is the id of the desktop
   // session being attached. |desktop_pipe| is the client end of the pipe opened
