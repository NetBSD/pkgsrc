$NetBSD: patch-src_corelib_io_io.pri,v 1.6 2018/11/13 09:24:37 markd Exp $

* Add DragonFly support
* Patch sent and merged upstream:
  http://codereview.qt-project.org/#/c/111741/

--- src/corelib/io/io.pri.orig	2017-01-18 14:20:58.000000000 +0000
+++ src/corelib/io/io.pri
@@ -175,7 +175,7 @@ win32 {
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
