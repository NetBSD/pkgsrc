$NetBSD: patch-remoting_host_ipc__constants.cc,v 1.7 2025/09/12 16:02:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_constants.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ remoting/host/ipc_constants.cc
@@ -17,7 +17,7 @@ namespace remoting {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if !defined(NDEBUG)
 // Use a different IPC name for debug builds so that we can run the host
@@ -81,7 +81,7 @@ GetChromotingHostServicesServerName() {
   static const base::NoDestructor<mojo::NamedPlatformChannel::ServerName>
       server_name(
           named_mojo_ipc_server::WorkingDirectoryIndependentServerNameFromUTF8(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
               // Linux host creates the socket file in /tmp, and it won't be
               // deleted until reboot, so we put username in the path in case
               // the user switches the host owner.
