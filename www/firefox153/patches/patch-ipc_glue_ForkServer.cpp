$NetBSD: patch-ipc_glue_ForkServer.cpp,v 1.1 2026/08/27 01:23:16 gutteridge Exp $

* Fix build for signal(3).

--- ipc/glue/ForkServer.cpp.orig	2026-04-20 09:24:23.315338652 +0000
+++ ipc/glue/ForkServer.cpp
@@ -19,6 +19,7 @@
 #include "nsTraceRefcnt.h"
 
 #include <fcntl.h>
+#include <signal.h>
 #include <string.h>
 #include <sys/wait.h>
 #include <unistd.h>
