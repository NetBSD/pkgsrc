$NetBSD: patch-remoting_host_chromoting__host.cc,v 1.15 2026/02/15 09:04:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ remoting/host/chromoting_host.cc
@@ -144,7 +144,7 @@ void ChromotingHost::Start(const std::st
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
