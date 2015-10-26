$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.5 2015/10/26 19:03:59 adam Exp $

* make statvfs available on non-NetBSD BSD platforms
* fix build on SunOS

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2015-10-13 04:35:31.000000000 +0000
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
