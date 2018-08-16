$NetBSD: patch-Source_autotools_SetupCompilerFlags.m4,v 1.1 2018/08/16 11:49:13 he Exp $

NetBSD doesn't have -latomic.

--- Source/autotools/SetupCompilerFlags.m4.orig	2016-04-10 06:48:38.000000000 +0000
+++ Source/autotools/SetupCompilerFlags.m4
@@ -69,6 +69,9 @@ int main() {
 }
 ]])], has_atomic=yes, has_atomic=no)
 AC_LANG_POP([C++])
-if test "$has_atomic" = "no"; then
-   LIBS="$LIBS -latomic"
+if test "`(uname -s)`" != "NetBSD"; then
+   # no -latomic on NetBSD...
+   if test "$has_atomic" = "no"; then
+      LIBS="$LIBS -latomic"
+   fi
 fi
