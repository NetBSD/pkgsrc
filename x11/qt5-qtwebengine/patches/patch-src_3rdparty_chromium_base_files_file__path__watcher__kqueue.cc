$NetBSD: patch-src_3rdparty_chromium_base_files_file__path__watcher__kqueue.cc,v 1.2 2023/04/12 19:24:06 adam Exp $

data was intptr_t until NetBSD 9, then it switched to void * like every other operating system.

--- src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc.orig	2022-03-30 09:48:18.000000000 +0000
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
@@ -72,9 +81,15 @@ int FilePathWatcherKQueue::EventsForPath
     FilePath::StringType subdir = (i != (components.end() - 1)) ? *(i + 1) : "";
     EventData* data = new EventData(built_path, subdir);
     struct kevent event;
+#ifdef __NetBSD__
+    EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
+           (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
+            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, reinterpret_cast<KEVENT_TYPE>(data));
+#else
     EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
            (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
             NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, data);
+#endif
     events->push_back(event);
   }
   return last_existing_entry;
