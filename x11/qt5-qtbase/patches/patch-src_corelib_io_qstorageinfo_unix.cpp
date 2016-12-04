$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.6 2016/12/04 21:46:54 marino Exp $

* make statvfs available on non-NetBSD BSD platforms
* Use f_bsize instead of f_frsize on non-NetBSD BSD platforms
* fix build on SunOS

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2015-10-13 04:35:31 UTC
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -68,8 +68,8 @@
 
 #if defined(Q_OS_BSD4)
 #  if defined(Q_OS_NETBSD)
-     define QT_STATFSBUF struct statvfs
-     define QT_STATFS    ::statvfs
+#    define QT_STATFSBUF struct statvfs
+#    define QT_STATFS    ::statvfs
 #  else
 #    define QT_STATFSBUF struct statfs
 #    define QT_STATFS    ::statfs
@@ -78,7 +78,7 @@
 #  if !defined(ST_RDONLY)
 #    define ST_RDONLY MNT_RDONLY
 #  endif
-#  if !defined(_STATFS_F_FLAGS)
+#  if !defined(_STATFS_F_FLAGS) && !defined(Q_OS_NETBSD)
 #    define _STATFS_F_FLAGS 1
 #  endif
 #elif defined(Q_OS_ANDROID)
@@ -87,7 +87,7 @@
 #  if !defined(ST_RDONLY)
 #    define ST_RDONLY 1 // hack for missing define on Android
 #  endif
-#elif defined(Q_OS_HAIKU)
+#elif defined(Q_OS_HAIKU) || defined(Q_OS_SOLARIS)
 #  define QT_STATFSBUF struct statvfs
 #  define QT_STATFS    ::statvfs
 #else
@@ -506,9 +506,15 @@ void QStorageInfoPrivate::retrieveVolume
         valid = true;
         ready = true;
 
+#if defined(Q_OS_BSD4) && !defined(Q_OS_NETBSD)
+        bytesTotal = statfs_buf.f_blocks * statfs_buf.f_bsize;
+        bytesFree = statfs_buf.f_bfree * statfs_buf.f_bsize;
+        bytesAvailable = statfs_buf.f_bavail * statfs_buf.f_bsize;
+#else
         bytesTotal = statfs_buf.f_blocks * statfs_buf.f_frsize;
         bytesFree = statfs_buf.f_bfree * statfs_buf.f_frsize;
         bytesAvailable = statfs_buf.f_bavail * statfs_buf.f_frsize;
+#endif
 #if defined(Q_OS_ANDROID) || defined (Q_OS_BSD4)
 #if defined(_STATFS_F_FLAGS)
         readOnly = (statfs_buf.f_flags & ST_RDONLY) != 0;
