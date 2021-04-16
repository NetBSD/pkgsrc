$NetBSD: patch-build-aux_find-x-server.sh,v 1.1 2021/04/16 13:57:52 cirnatdan Exp $

Help build script find NetBSD base X server

--- build-aux/find-x-server.sh.orig	2021-03-16 20:48:04.000000000 +0000
+++ build-aux/find-x-server.sh
@@ -21,6 +21,8 @@ elif test ! -h /usr/X11 -a -x /usr/X11/b
     echo "/usr/X11/bin/X"
 elif test -x /usr/X11R6/bin/X; then
     echo "/usr/X11R6/bin/X"
+elif test -x /usr/X11R7/bin/X; then
+    echo "/usr/X11R7/bin/X"
 elif test -x /usr/bin/Xorg; then
     echo "/usr/bin/Xorg"
 elif test -x /usr/X11/bin/X; then
