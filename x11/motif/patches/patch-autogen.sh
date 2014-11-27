$NetBSD: patch-autogen.sh,v 1.1 2014/11/27 13:30:04 joerg Exp $

--- autogen.sh.orig	2014-11-26 13:30:56.000000000 +0000
+++ autogen.sh
@@ -12,13 +12,3 @@ aclocal -I .
 autoconf
 autoheader
 automake --foreign  --include-deps --add-missing
-
-if test -z "$*"; then
-        echo "I am going to run ./configure with no arguments - if you wish "
-        echo "to pass any to it, please specify them on the $0 command line."
-fi
-
-cd "$THEDIR"
-
-$srcdir/configure "$@"
-
