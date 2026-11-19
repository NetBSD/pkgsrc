$NetBSD: patch-remoting_host_peer__connection__process__main.cc,v 1.8 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/peer_connection_process_main.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/peer_connection_process_main.cc
@@ -26,7 +26,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <memory>
 
 #include "base/logging.h"
@@ -83,7 +83,7 @@ int PeerConnectionProcessMain() {
     return kInitializationFailed;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Engage the multi-threaded Seccomp-BPF sandbox after establishing the
   // initial Mojo IPC connection with the parent process, but before starting
   // the main RunLoop to process untrusted WebRTC peer traffic and remote
