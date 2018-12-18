$NetBSD: patch-src_corelib_io_io.pri,v 1.7 2018/12/18 09:57:18 adam Exp $

* Add DragonFly support
* Patch sent and merged upstream:
  http://codereview.qt-project.org/#/c/111741/

--- src/corelib/io/io.pri.orig	2018-12-03 11:15:26.000000000 +0000
+++ src/corelib/io/io.pri
@@ -101,7 +101,7 @@ qtConfig(filesystemwatcher) {
         SOURCES += io/qfilesystemwatcher_inotify.cpp
         HEADERS += io/qfilesystemwatcher_inotify_p.h
     } else {
-        freebsd|darwin|openbsd|netbsd {
+        freebsd-*|darwin-*|openbsd-*|netbsd-*|dragonfly-* {
             SOURCES += io/qfilesystemwatcher_kqueue.cpp
             HEADERS += io/qfilesystemwatcher_kqueue_p.h
         }
