$NetBSD: patch-base_files_dir__reader__linux.h,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/dir_reader_linux.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/files/dir_reader_linux.h
@@ -21,10 +21,16 @@
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 
+#include "build/build_config.h"
+
 // See the comments in dir_reader_posix.h about this.
 
 namespace base {
 
+#if BUILDFLAG(IS_BSD)
+#include <dirent.h>
+typedef struct dirent linux_dirent;
+#else
 struct linux_dirent {
   uint64_t d_ino;
   int64_t d_off;
@@ -32,6 +38,7 @@ struct linux_dirent {
   unsigned char d_type;
   char d_name[0];
 };
+#endif
 
 class DirReaderLinux {
  public:
@@ -66,7 +73,11 @@ class DirReaderLinux {
       return true;
     }
 
+#if BUILDFLAG(IS_BSD)
+    const int r = getdents(fd_, reinterpret_cast<char *>(buf_), sizeof(buf_));
+#else
     const long r = syscall(__NR_getdents64, fd_, buf_, sizeof(buf_));
+#endif
     if (r == 0) {
       return false;
     }
