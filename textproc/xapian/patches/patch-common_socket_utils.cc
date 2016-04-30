$NetBSD: patch-common_socket_utils.cc,v 1.2 2016/04/30 14:14:07 schmonz Exp $

Fix compilation error on NetBSD-current (as of 2015-05-26).

--- common/socket_utils.cc.orig	2015-05-21 05:57:01.000000000 +0000
+++ common/socket_utils.cc
@@ -28,6 +28,7 @@ using namespace std;
 
 #ifndef __WIN32__
 # include <sys/socket.h>
+# include <sys/time.h>
 #else
 # include "safeerrno.h"
 
