$NetBSD: patch-third__party_crashpad_crashpad_util_posix_close__multiple.cc,v 1.1 2025/02/06 09:58:25 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -73,7 +73,7 @@ void CloseNowOrOnExec(int fd, bool ebadf
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
