$NetBSD: patch-base_process_kill__posix.cc,v 1.6 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/kill_posix.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/process/kill_posix.cc
@@ -161,7 +161,7 @@ void EnsureProcessTerminated(Process pro
       0, new BackgroundReaper(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
