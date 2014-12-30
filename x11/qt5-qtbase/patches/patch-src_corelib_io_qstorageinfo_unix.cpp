$NetBSD: patch-src_corelib_io_qstorageinfo_unix.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

--- src/corelib/io/qstorageinfo_unix.cpp.orig	2014-12-17 11:12:56.000000000 +0000
+++ src/corelib/io/qstorageinfo_unix.cpp
@@ -118,7 +118,7 @@ public:
     inline QByteArray device() const;
 private:
 #if defined(Q_OS_BSD4)
-    statfs *stat_buf;
+    QT_STATFSBUF *stat_buf;
     int entryCount;
     int currentIndex;
 #elif defined(Q_OS_SOLARIS)
