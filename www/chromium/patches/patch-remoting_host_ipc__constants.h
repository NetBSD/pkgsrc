$NetBSD: patch-remoting_host_ipc__constants.h,v 1.16 2026/10/23 15:05:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_constants.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ remoting/host/ipc_constants.h
@@ -38,7 +38,7 @@ bool GetInstalledBinaryPath(const base::
 const mojo::NamedPlatformChannel::ServerName&
 GetChromotingHostServicesServerName();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the server name for the legacy single-process Linux host.
 const mojo::NamedPlatformChannel::ServerName&
 GetLegacyChromotingHostServicesServerName();
@@ -52,7 +52,7 @@ extern const char kAgentProcessBrokerMes
 const mojo::NamedPlatformChannel::ServerName& GetAgentProcessBrokerServerName();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Message pipe ID used for LoginSessionReporter.
 extern const char kLoginSessionReporterMessagePipeId[];
 
