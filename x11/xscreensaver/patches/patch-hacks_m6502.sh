$NetBSD: patch-hacks_m6502.sh,v 1.1 2016/06/06 12:41:42 wiz Exp $

NetBSD's sh(1) does not recognize the ERR signal.

--- hacks/m6502.sh.orig	2016-04-08 03:58:51.000000000 +0000
+++ hacks/m6502.sh
@@ -7,7 +7,7 @@ SRCS=$*
 TMP1=m6502.h.1.$$
 TMP2=m6502.h.2.$$
 rm -f $TMP1 $TMP2
-trap "rm -f $TMP1 $TMP2" 1 2 3 15 ERR EXIT
+trap "rm -f $TMP1 $TMP2" 1 2 3 15 EXIT
 
 if [ -z "$UTILS_SRC" ]; then UTILS_SRC="../utils"; fi
 
