$NetBSD: patch-oneko.h,v 1.1 2026/03/23 11:32:52 nia Exp $

Include <unistd.h> for pause(3).

--- oneko.h.orig	2026-03-23 11:17:49.591075557 +0000
+++ oneko.h
@@ -17,6 +17,7 @@
 #include <string.h>
 
 #include <signal.h>
+#include <unistd.h>
 #include <math.h>
 #include <sys/time.h>
 
