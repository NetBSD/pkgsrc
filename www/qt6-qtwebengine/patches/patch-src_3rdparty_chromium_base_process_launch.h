$NetBSD: patch-src_3rdparty_chromium_base_process_launch.h,v 1.1 2025/12/21 09:38:14 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/process/launch.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/process/launch.h
@@ -7,6 +7,13 @@
 #ifndef BASE_PROCESS_LAUNCH_H_
 #define BASE_PROCESS_LAUNCH_H_
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE 1
+#ifndef PTHREAD_STACK_MIN
+#define PTHREAD_STACK_MIN 4096
+#endif
+#endif
+
 #include <limits.h>
 #include <stddef.h>
 
@@ -237,7 +244,7 @@ struct BASE_EXPORT LaunchOptions {
   bool clear_environment = false;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
