$NetBSD: patch-remoting_host_ipc__constants.h,v 1.3 2026/04/21 15:21:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_constants.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ remoting/host/ipc_constants.h
@@ -39,7 +39,7 @@ extern const char kAgentProcessBrokerMes
 const mojo::NamedPlatformChannel::ServerName& GetAgentProcessBrokerServerName();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Message pipe ID used for LoginSessionReporter.
 extern const char kLoginSessionReporterMessagePipeId[];
 
