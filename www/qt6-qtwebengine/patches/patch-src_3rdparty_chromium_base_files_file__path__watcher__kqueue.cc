$NetBSD: patch-src_3rdparty_chromium_base_files_file__path__watcher__kqueue.cc,v 1.1 2025/12/21 09:38:13 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc
@@ -81,10 +81,16 @@ size_t FilePathWatcherKQueue::EventsForP
     FilePath::StringType subdir = (i != (components.end() - 1)) ? *(i + 1) : "";
     EventData* data = new EventData(built_path, subdir);
     struct kevent event;
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999000000
+    EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
+           (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
+            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, reinterpret_cast<intptr_t>(data));
+#else
     EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
            (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB | NOTE_RENAME | NOTE_REVOKE |
             NOTE_EXTEND),
            0, data);
+#endif
     events->push_back(event);
   }
   return last_existing_entry;
