$NetBSD: patch-base_process_kill__posix.cc,v 1.24 2026/08/09 06:31:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/kill_posix.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ base/process/kill_posix.cc
@@ -169,7 +169,7 @@ void EnsureProcessTerminated(Process pro
       0, MakeSelfDeleting<BackgroundReaper>(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
