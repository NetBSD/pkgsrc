$NetBSD: patch-bin_build-index.sh,v 1.1 2015/12/11 21:45:07 riz Exp $

Fix default paths.
--- bin/build-index.sh.orig	2013-08-21 17:11:04.000000000 +0000
+++ bin/build-index.sh
@@ -2,12 +2,12 @@
 
 if [ "$GRAPHITE_ROOT" = "" ]
 then
-  GRAPHITE_ROOT="/opt/graphite"
+  GRAPHITE_ROOT="@PREFIX@/graphite"
 fi
 
 if [ "$GRAPHITE_STORAGE_DIR" = "" ]
 then
-  GRAPHITE_STORAGE_DIR="${GRAPHITE_ROOT}/storage"
+  GRAPHITE_STORAGE_DIR="@GRAPHITE_DIR@"
 fi
 
 
