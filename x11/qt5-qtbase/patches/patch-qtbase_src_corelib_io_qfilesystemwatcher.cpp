$NetBSD: patch-qtbase_src_corelib_io_qfilesystemwatcher.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtbase/src/corelib/io/qfilesystemwatcher.cpp.orig	2013-11-27 01:01:16.000000000 +0000
+++ qtbase/src/corelib/io/qfilesystemwatcher.cpp
@@ -60,7 +60,7 @@
 #  include "qfilesystemwatcher_win_p.h"
 #elif defined(USE_INOTIFY)
 #  include "qfilesystemwatcher_inotify_p.h"
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
 #  include "qfilesystemwatcher_kqueue_p.h"
 #endif
 
@@ -74,7 +74,7 @@ QFileSystemWatcherEngine *QFileSystemWat
     // there is a chance that inotify may fail on Linux pre-2.6.13 (August
     // 2005), so we can't just new inotify directly.
     return QInotifyFileSystemWatcherEngine::create(parent);
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_MAC) || defined(Q_OS_NETBSD)
     return QKqueueFileSystemWatcherEngine::create(parent);
 #else
     return 0;
