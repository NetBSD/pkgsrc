$NetBSD: patch-src_corelib_io_io.pri,v 1.3 2015/08/30 04:13:46 markd Exp $

* Add NetBSD support
* Add DragonFly support
* Patch sent and merged upstream:
  http://codereview.qt-project.org/#/c/111741/

* fix linux test.

--- src/corelib/io/io.pri.orig	2014-12-05 16:24:37.000000000 +0000
+++ src/corelib/io/io.pri
@@ -172,13 +172,13 @@ win32 {
                 io/qstorageinfo_unix.cpp
         }
 
-        linux|if(qnx:contains(QT_CONFIG, inotify)) {
+        linux*|if(qnx:contains(QT_CONFIG, inotify)) {
             SOURCES += io/qfilesystemwatcher_inotify.cpp
             HEADERS += io/qfilesystemwatcher_inotify_p.h
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
