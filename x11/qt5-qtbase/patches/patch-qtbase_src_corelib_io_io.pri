$NetBSD: patch-qtbase_src_corelib_io_io.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support
* Add DragonFly support

--- qtbase/src/corelib/io/io.pri.orig	2013-11-27 01:01:16.000000000 +0000
+++ qtbase/src/corelib/io/io.pri
@@ -152,7 +152,7 @@ win32 {
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
