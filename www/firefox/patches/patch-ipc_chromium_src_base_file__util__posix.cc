$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.2 2013/12/15 13:54:37 ryoon Exp $

--- ipc/chromium/src/base/file_util_posix.cc.orig	2013-12-05 16:07:35.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -8,7 +8,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <fnmatch.h>
-#ifndef ANDROID
+#if !defined(ANDROID) && !defined(OS_SOLARIS)
 #include <fts.h>
 #endif
 #include <libgen.h>
@@ -67,7 +67,7 @@ bool Delete(const FilePath& path, bool r
   if (!recursive)
     return (rmdir(path_str) == 0);
 
-#ifdef ANDROID
+#if defined(ANDROID) || defined(OS_SOLARIS)
   // XXX Need ftsless impl for bionic
   return false;
 #else
@@ -140,7 +140,7 @@ bool CopyDirectory(const FilePath& from_
     return false;
   }
 
-#ifdef ANDROID
+#if defined(ANDROID) || defined(OS_SOLARIS)
   // XXX Need ftsless impl for bionic
   return false;
 #else
