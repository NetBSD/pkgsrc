$NetBSD: patch-src_corelib_io_qfilesystemwatcher.cpp,v 1.1 2012/09/12 17:02:50 jaapb Exp $

Use kqueue instead of fam to monitor the file system
--- src/corelib/io/qfilesystemwatcher.cpp.orig	2012-04-26 19:46:08.000000000 +0000
+++ src/corelib/io/qfilesystemwatcher.cpp
@@ -57,7 +57,7 @@
 #elif defined(Q_OS_LINUX)
 #  include "qfilesystemwatcher_inotify_p.h"
 #  include "qfilesystemwatcher_dnotify_p.h"
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 #  if (defined Q_OS_MAC) && (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
 #  include "qfilesystemwatcher_fsevents_p.h"
 #  endif //MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@@ -253,7 +253,7 @@ QFileSystemWatcherEngine *QFileSystemWat
     if(!eng)
         eng = QDnotifyFileSystemWatcherEngine::create();
     return eng;
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 #  if 0 && defined(Q_OS_MAC) && (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
     if (QSysInfo::MacintoshVersion >= QSysInfo::MV_10_5)
         return QFSEventsFileSystemWatcherEngine::create();
