$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.3 2015/04/08 10:31:28 nros Exp $
* make statvfs available on non-NetBSD BSD platforms
* NetBSD uses struct statvfs as first argument to getmntinfo
* fix build on SunOS
--- src/corelib/io/qstorageinfo_unix.cpp.orig	2014-12-05 16:24:37.000000000 +0000
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -52,6 +52,7 @@
 
 #if defined(Q_OS_BSD4)
 #  include <sys/mount.h>
+#  include <sys/statvfs.h>
 #elif defined(Q_OS_ANDROID)
 #  include <sys/mount.h>
 #  include <sys/vfs.h>
@@ -63,6 +64,8 @@
 #  include <sys/statvfs.h>
 #elif defined(Q_OS_SOLARIS)
 #  include <sys/mnttab.h>
+#  include <sys/types.h>
+#  include <sys/statvfs.h>
 #endif
 
 #if defined(Q_OS_BSD4)
@@ -74,6 +77,9 @@
 #  if !defined(ST_RDONLY)
 #    define ST_RDONLY 1 // hack for missing define on Android
 #  endif
+#elif defined(Q_OS_SOLARIS)
+#  define QT_STATFSBUF struct statvfs
+#  define QT_STATFS    ::statvfs
 #else
 #  if defined(QT_LARGEFILE_SUPPORT)
 #    define QT_STATFSBUF struct statvfs64
@@ -118,7 +124,11 @@ public:
     inline QByteArray device() const;
 private:
 #if defined(Q_OS_BSD4)
-    statfs *stat_buf;
+#if defined(Q_OS_NETBSD)
+    QT_STATFSBUF *stat_buf;
+#else
+    struct statfs *stat_buf;
+#endif
     int entryCount;
     int currentIndex;
 #elif defined(Q_OS_SOLARIS)
@@ -196,22 +206,22 @@ inline bool QStorageIterator::isValid() 
 
 inline bool QStorageIterator::next()
 {
-    return ::getmntent(fp, &mnt) == Q_NULLPTR;
+    return ::getmntent(fp, &mnt) == 0;
 }
 
 inline QString QStorageIterator::rootPath() const
 {
-    return QFile::decodeName(mnt->mnt_mountp);
+    return QFile::decodeName(mnt.mnt_mountp);
 }
 
 inline QByteArray QStorageIterator::fileSystemType() const
 {
-    return QByteArray(mnt->mnt_fstype);
+    return QByteArray(mnt.mnt_fstype);
 }
 
 inline QByteArray QStorageIterator::device() const
 {
-    return QByteArray(mnt->mnt_mntopts);
+    return QByteArray(mnt.mnt_mntopts);
 }
 
 #elif defined(Q_OS_ANDROID)
