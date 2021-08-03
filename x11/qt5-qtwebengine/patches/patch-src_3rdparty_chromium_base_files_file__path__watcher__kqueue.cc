$NetBSD: patch-src_3rdparty_chromium_base_files_file__path__watcher__kqueue.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

data was intptr_t until NetBSD 9, then it switched to void * like every other operating system.

--- src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc
@@ -4,6 +4,15 @@
 
 #include "base/files/file_path_watcher_kqueue.h"
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ < 999000000
+#define KEVENT_TYPE intptr_t
+#else
+#define KEVENT_TYPE void *
+#endif
+#endif
+
 #include <fcntl.h>
 #include <stddef.h>
 #include <sys/param.h>
@@ -74,7 +83,7 @@ int FilePathWatcherKQueue::EventsForPath
     struct kevent event;
     EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
            (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
-            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, data);
+            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, reinterpret_cast<KEVENT_TYPE>(data));
     events->push_back(event);
   }
   return last_existing_entry;
