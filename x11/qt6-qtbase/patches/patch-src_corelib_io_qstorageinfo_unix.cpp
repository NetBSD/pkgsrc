$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.3 2025/11/11 12:34:13 adam Exp $

Fix build on SunOS.

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2025-10-01 09:37:05.000000000 +0000
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -51,7 +51,7 @@
 #  if !defined(_STATFS_F_FLAGS) && !defined(Q_OS_NETBSD)
 #    define _STATFS_F_FLAGS 1
 #  endif
-#elif defined(Q_OS_HAIKU) || defined(Q_OS_CYGWIN)
+#elif defined(Q_OS_HAIKU) || defined(Q_OS_CYGWIN) || defined(Q_OS_SOLARIS)
 #  define QT_STATFSBUF struct statvfs
 #  define QT_STATFS    ::statvfs
 #else
