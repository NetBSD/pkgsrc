$NetBSD: patch-hacks_glx_molecules.sh,v 1.1 2016/06/06 12:41:42 wiz Exp $

NetBSD's sh(1) does not recognize the ERR signal.

--- hacks/glx/molecules.sh.orig	2016-04-08 03:58:54.000000000 +0000
+++ hacks/glx/molecules.sh
@@ -6,7 +6,7 @@ SRCS=$*
 
 TMP=molecules.h.$$
 rm -f $TMP
-trap "rm -f $TMP" 1 2 3 15 ERR EXIT
+trap "rm -f $TMP" 1 2 3 15 EXIT
 
 if [ -z "$UTILS_SRC" ]; then UTILS_SRC="../../utils"; fi
 
