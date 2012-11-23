$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.6 2012/11/23 17:28:49 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util_posix.cc.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util_posix.cc
@@ -33,7 +33,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef HAVE_STAT64
 #define stat64 stat
 #endif
 
