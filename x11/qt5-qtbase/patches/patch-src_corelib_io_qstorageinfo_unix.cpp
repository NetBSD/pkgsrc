$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.7 2018/01/17 19:30:47 markd Exp $

* fix build on SunOS

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2015-10-13 04:35:31 UTC
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -87,7 +87,7 @@
 #  if !defined(ST_RDONLY)
 #    define ST_RDONLY 1 // hack for missing define on Android
 #  endif
-#elif defined(Q_OS_HAIKU)
+#elif defined(Q_OS_HAIKU) || defined(Q_OS_SOLARIS)
 #  define QT_STATFSBUF struct statvfs
 #  define QT_STATFS    ::statvfs
 #else
