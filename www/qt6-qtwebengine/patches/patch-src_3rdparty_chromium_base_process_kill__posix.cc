$NetBSD: patch-src_3rdparty_chromium_base_process_kill__posix.cc,v 1.1 2025/12/21 09:38:14 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/process/kill_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/process/kill_posix.cc
@@ -157,7 +157,7 @@ void EnsureProcessTerminated(Process pro
       0, new BackgroundReaper(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
