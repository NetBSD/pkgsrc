$NetBSD: patch-get_version.sh,v 1.1 2017/07/28 08:42:17 tnn Exp $

avoid git dependency

--- get_version.sh.orig	2017-06-11 09:15:36.000000000 +0000
+++ get_version.sh
@@ -1,5 +1,9 @@
 #!/bin/sh
 
+set -e
+echo '#define VERSION_STRING "'$(head -n 1 ChangeLog)'"' > version.h
+exit 0
+
 MAJOR=0.14
 DIRTY=""
 
