$NetBSD: patch-remoting_host_chromoting__host.cc,v 1.26 2026/09/22 13:41:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/host/chromoting_host.cc
@@ -143,7 +143,7 @@ void ChromotingHost::Start(const std::st
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
@@ -162,7 +162,7 @@ void ChromotingHost::BindChromotingHostS
 }
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindChromotingHostServices(
     mojo::PendingReceiver<mojom::ChromotingHostServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -301,7 +301,7 @@ std::optional<ErrorCode> ChromotingHost:
   return per_session_policies_validator_.Run(policies);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindSessionServices(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
