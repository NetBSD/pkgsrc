$NetBSD: patch-libAfterStep_screen.c,v 1.1 2025/09/04 22:50:51 gutteridge Exp $

Source fcntl.h as per standard, and as is done everywhere else in this
code base, too. Addresses build issue with SunOS.

--- libAfterStep/screen.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/screen.c
@@ -24,7 +24,7 @@
 #include <signal.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#include <sys/fcntl.h>
+#include <fcntl.h>
 #include <sys/un.h>
 
 #include "afterstep.h"
