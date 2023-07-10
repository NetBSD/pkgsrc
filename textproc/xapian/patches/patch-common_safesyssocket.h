$NetBSD: patch-common_safesyssocket.h,v 1.2 2023/07/10 15:07:26 schmonz Exp $

Fix compilation error on NetBSD-current (as of 2015-05-26).

--- common/safesyssocket.h.orig	2023-07-07 01:59:19.000000000 +0000
+++ common/safesyssocket.h
@@ -26,6 +26,7 @@
 #include <sys/types.h>
 #ifndef __WIN32__
 # include <sys/socket.h>
+# include <sys/time.h>
 #else
 # include "safewinsock2.h"
 #endif
