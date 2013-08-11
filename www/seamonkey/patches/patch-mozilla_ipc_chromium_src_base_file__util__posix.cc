$NetBSD: patch-mozilla_ipc_chromium_src_base_file__util__posix.cc,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util_posix.cc.orig	2013-08-04 03:05:29.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util_posix.cc
@@ -8,7 +8,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <fnmatch.h>
-#ifndef ANDROID
+#if !defined(ANDROID) && !defined(OS_SOLARIS)
 #include <fts.h>
 #endif
 #include <libgen.h>
@@ -121,7 +121,7 @@ bool Delete(const FilePath& path, bool r
   if (!recursive)
     return (rmdir(path_str) == 0);
 
-#ifdef ANDROID
+#if defined(ANDROID) || defined(OS_SOLARIS)
   // XXX Need ftsless impl for bionic
   return false;
 #else
@@ -194,7 +194,7 @@ bool CopyDirectory(const FilePath& from_
     return false;
   }
 
-#ifdef ANDROID
+#if defined(ANDROID) || defined(OS_SOLARIS)
   // XXX Need ftsless impl for bionic
   return false;
 #else
@@ -613,7 +613,7 @@ FileEnumerator::FileEnumerator(const Fil
 }
 
 FileEnumerator::~FileEnumerator() {
-#ifndef ANDROID
+#if !defined(ANDROID) && !defined(OS_SOLARIS)
   if (fts_)
     fts_close(fts_);
 #endif
@@ -625,7 +625,7 @@ void FileEnumerator::GetFindInfo(FindInf
   if (!is_in_find_op_)
     return;
 
-#ifndef ANDROID
+#if !defined(ANDROID) && !defined(OS_SOLARIS)
   memcpy(&(info->stat), fts_ent_->fts_statp, sizeof(info->stat));
   info->filename.assign(fts_ent_->fts_name);
 #endif
@@ -636,7 +636,7 @@ void FileEnumerator::GetFindInfo(FindInf
 // large directories with many files this can be quite deep.
 // TODO(erikkay) - get rid of this recursive pattern
 FilePath FileEnumerator::Next() {
-#ifdef ANDROID
+#if defined(ANDROID) || defined(OS_SOLARIS)
   return FilePath();
 #else
   if (!is_in_find_op_) {
