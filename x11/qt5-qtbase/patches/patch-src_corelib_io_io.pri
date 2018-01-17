$NetBSD: patch-src_corelib_io_io.pri,v 1.5 2018/01/17 19:30:47 markd Exp $

* Add DragonFly support
* Patch sent and merged upstream:
  http://codereview.qt-project.org/#/c/111741/
* fix linux test.

--- src/corelib/io/io.pri.orig	2017-01-18 14:20:58.000000000 +0000
+++ src/corelib/io/io.pri
@@ -169,13 +169,13 @@ win32 {
                 io/qstorageinfo_unix.cpp
         }
 
-        linux|if(qnx:qtConfig(inotify)) {
+        linux*|if(qnx:qtConfig(inotify)) {
             SOURCES += io/qfilesystemwatcher_inotify.cpp
             HEADERS += io/qfilesystemwatcher_inotify_p.h
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
