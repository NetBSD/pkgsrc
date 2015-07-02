$NetBSD: patch-mkallcomposecaches.sh,v 1.1 2015/07/02 12:38:32 rodent Exp $

Fixes portability failure.

--- mkallcomposecaches.sh.orig	2009-04-10 00:43:20.000000000 +0000
+++ mkallcomposecaches.sh
@@ -55,7 +55,7 @@ while [ "x$1" != x ] ; do
   esac
 done
 
-test $# == 1 || usage
+test $# = 1 || usage
 
 
 # Defaults
