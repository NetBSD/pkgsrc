$NetBSD: patch-externs.h,v 1.1 2025/12/18 13:00:31 nia Exp $

Add missing include for bzero(3).

--- externs.h.orig	2025-12-18 12:54:39.717614007 +0000
+++ externs.h
@@ -45,6 +45,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <time.h>
 #include <unistd.h>
 #include <utime.h>
