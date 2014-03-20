$NetBSD: patch-xpcom_io_nsLocalFileUnix.cpp,v 1.1 2014/03/20 21:02:00 ryoon Exp $

--- xpcom/io/nsLocalFileUnix.cpp.orig	2014-03-15 05:19:39.000000000 +0000
+++ xpcom/io/nsLocalFileUnix.cpp
@@ -382,7 +382,7 @@ nsLocalFile::OpenNSPRFileDesc(int32_t fl
         PR_Delete(mPath.get());
     }
 
-#if defined(LINUX) && !defined(ANDROID)
+#if defined(HAVE_POSIX_FADVISE)
     if (flags & OS_READAHEAD) {
         posix_fadvise(PR_FileDesc2NativeHandle(*_retval), 0, 0,
                       POSIX_FADV_SEQUENTIAL);
