$NetBSD: patch-libs_ksysguard_processcore_processes__netbsd__p.cpp,v 1.1 2013/01/17 16:05:53 joerg Exp $

--- libs/ksysguard/processcore/processes_netbsd_p.cpp.orig	2013-01-16 23:10:41.000000000 +0000
+++ libs/ksysguard/processcore/processes_netbsd_p.cpp
@@ -30,6 +30,7 @@
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#include <sys/resource.h>
 #include <sys/stat.h>
 #include <signal.h>
 #include <unistd.h>
