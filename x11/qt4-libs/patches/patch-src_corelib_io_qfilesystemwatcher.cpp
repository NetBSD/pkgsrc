$NetBSD: patch-src_corelib_io_qfilesystemwatcher.cpp,v 1.2 2012/12/07 10:06:13 adam Exp $

Use kqueue instead of fam to monitor the file system

--- src/corelib/io/qfilesystemwatcher.cpp.orig	2012-11-23 10:09:55.000000000 +0000
+++ src/corelib/io/qfilesystemwatcher.cpp
@@ -59,7 +59,7 @@
 #  include "qfilesystemwatcher_dnotify_p.h"
 #elif defined(Q_OS_QNX) && !defined(QT_NO_INOTIFY)
 #  include "qfilesystemwatcher_inotify_p.h"
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 #  if (defined Q_OS_MAC) && (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
 #  include "qfilesystemwatcher_fsevents_p.h"
 #  endif //MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@@ -257,7 +257,7 @@ QFileSystemWatcherEngine *QFileSystemWat
     if(!eng)
         eng = QDnotifyFileSystemWatcherEngine::create();
     return eng;
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 #  if 0 && defined(Q_OS_MAC) && (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
     if (QSysInfo::MacintoshVersion >= QSysInfo::MV_10_5)
         return QFSEventsFileSystemWatcherEngine::create();
