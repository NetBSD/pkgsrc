$NetBSD: patch-src_3rdparty_chromium_content_common_set__process__title__linux.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/common/set_process_title_linux.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/common/set_process_title_linux.h
@@ -5,6 +5,9 @@
 #ifndef CONTENT_COMMON_SET_PROCESS_TITLE_LINUX_H_
 #define CONTENT_COMMON_SET_PROCESS_TITLE_LINUX_H_
 
+#include "build/build_config.h"
+
+#if !defined(OS_BSD)
 // Set the process title that will show in "ps" and similar tools. Takes
 // printf-style format string and arguments. After calling setproctitle()
 // the original main() argv[] array should not be used. By default, the
@@ -14,6 +17,7 @@
 // This signature and naming is to be compatible with most other Unix
 // implementations of setproctitle().
 void setproctitle(const char* fmt, ...);
+#endif
 
 // Initialize state needed for setproctitle() on Linux. Pass the argv pointer
 // from main() to setproctitle_init() before calling setproctitle().
