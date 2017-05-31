$NetBSD: patch-startx.cpp,v 1.1 2017/05/31 05:29:34 maya Exp $

Don't use GNU expr extensions

Use the ':' operator instead of "match" and avoid the use of "\+".  Both
constructions aren't specified by POSIX and not supported in BSD expr.
Also drop the '^' from the regular expressions as it is implicit and
POSIX leaves its behaviour undefined.

https://cgit.freedesktop.org/xorg/app/xinit/commit/?id=e3bab0cc706880c22f2b205e7abad9d8c0227071app/xinit/commit/?id=e3bab0cc706880c22f2b205e7abad9d8c0227071

--- startx.cpp.orig	2014-09-11 17:31:42.000000000 +0000
+++ startx.cpp
@@ -217,7 +217,7 @@ fi
 XCOMM if no vt is specified add vtarg (which may be empty)
 have_vtarg="no"
 for i in $serverargs; do
-    if expr match "$i" '^vt[0-9]\+$' > /dev/null; then
+    if expr "$i" : 'vt[0-9][0-9]*$' > /dev/null; then
         have_vtarg="yes"
     fi
 done
