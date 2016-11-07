$NetBSD: patch-common_safesyssocket.h,v 1.1 2016/11/07 13:02:17 schmonz Exp $

Fix compilation error on NetBSD-current (as of 2015-05-26).

--- common/safesyssocket.h.orig	2016-10-21 04:54:32.000000000 +0000
+++ common/safesyssocket.h
@@ -25,6 +25,7 @@
 // Some older BSDs require sys/types.h to be included first.
 # include <sys/types.h>
 # include <sys/socket.h>
+# include <sys/time.h>
 #else
 # include "safewinsock2.h"
 #endif
