$NetBSD: patch-remoting_host_chromoting__host.cc,v 1.16 2026/03/14 12:40:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ remoting/host/chromoting_host.cc
@@ -144,7 +144,7 @@ void ChromotingHost::Start(const std::st
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
