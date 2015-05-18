$NetBSD: patch-src_corelib_io_io.pri,v 1.2 2015/05/18 13:52:24 nros Exp $

* Add NetBSD support
* Add DragonFly support
* Patch sent and merged upstream:
  http://codereview.qt-project.org/#/c/111741/
--- src/corelib/io/io.pri.orig	2013-11-27 01:01:16.000000000 +0000
+++ src/corelib/io/io.pri
@@ -152,7 +152,7 @@ win32 {
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
