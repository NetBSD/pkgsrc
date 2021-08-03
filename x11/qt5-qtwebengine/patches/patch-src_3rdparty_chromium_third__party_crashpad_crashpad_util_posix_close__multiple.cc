$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_posix_close__multiple.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2020-07-15 18:56:30.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -31,7 +31,7 @@
 #include "util/file/directory_reader.h"
 #include "util/misc/implicit_cast.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/sysctl.h>
 #endif
 
@@ -72,7 +72,7 @@ void CloseNowOrOnExec(int fd, bool ebadf
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif defined(OS_LINUX) || defined(OS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
