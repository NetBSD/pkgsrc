$NetBSD: patch-src_corelib_io_io.pri,v 1.1 2014/12/30 17:23:46 adam Exp $

* Add NetBSD support
* Add DragonFly support

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
