$NetBSD: patch-mozilla_xpcom_io_nsLocalFileUnix.cpp,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/xpcom/io/nsLocalFileUnix.cpp.orig	2014-03-19 01:42:18.000000000 +0000
+++ mozilla/xpcom/io/nsLocalFileUnix.cpp
@@ -382,7 +382,7 @@ nsLocalFile::OpenNSPRFileDesc(int32_t fl
         PR_Delete(mPath.get());
     }
 
-#if defined(LINUX) && !defined(ANDROID)
+#if defined(HAVE_POSIX_FADVISE)
     if (flags & OS_READAHEAD) {
         posix_fadvise(PR_FileDesc2NativeHandle(*_retval), 0, 0,
                       POSIX_FADV_SEQUENTIAL);
